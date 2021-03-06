#include "Map.h"
#include "define.h"
#include "CloudMgr.h"
#include "Cloud.h"
#include "EnemyStock.h"
#include "ItemMgr.h"
#include "Item.h"

Map::Map( const Panel * panel, int panel_num ) :
_panel( panel ),
_panel_num( panel_num ) {
}

Map::~Map( ) {
}

int Map::getPanelNum( ) const {
	return _panel_num;
}

const char * Map::getBgFilename( int idx ) const {
	return _panel[ idx ].bg_filename;
}

const char * Map::getCoverFilename( int idx ) const {
	return _panel[ idx ].cover_filename;
}

bool Map::isChip( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '#';
}

bool Map::isBlockChip( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '*';
}

bool Map::isItem( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '$';
}

FLOOR Map::getFloor( int bg_idx, int chip_idx ) const {
	FLOOR floor = FLOOR_ROAD;
	switch ( _panel[ bg_idx ].chip[ chip_idx ] ) {
	case '~':
		floor = FLOOR_WATER;
		break;
	case '+':
		floor = FLOOR_BOG;
		break;
	case '^':
		floor = FLOOR_NEEDLE;
		break;
	}

	return floor;
}

bool Map::isBigCloud( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '=';
}

bool Map::isSmallCloud( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '-';
}

CloudMgrPtr Map::createCloudMgr( ) const {
	CloudMgrPtr mgr( new CloudMgr );

	for ( int i = 0; i < _panel_num; i++ ) {
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			if ( isBigCloud( i, j ) ||
				 isSmallCloud( i, j ) ) {
				bool big = false;
				if ( isBigCloud( i, j ) ) {
					big = true;
				}
				int x = j % MAPCHIP_NUM * MAPCHIP_SIZE + i * BG_SIZE;
				int y = j / MAPCHIP_NUM * MAPCHIP_SIZE;
				CloudPtr cloud( new Cloud( x, y, big ) );
				mgr->add( cloud );
			}
		}
	}

	return mgr;
}

ItemMgrPtr Map::createItemMgr( ) const {
	ItemMgrPtr mgr( new ItemMgr );

	for ( int i = 0; i < _panel_num; i++ ) {
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			if ( isItem( i, j ) ) {
				int x = j % MAPCHIP_NUM * MAPCHIP_SIZE + i * BG_SIZE;
				int y = j / MAPCHIP_NUM * MAPCHIP_SIZE - MAPCHIP_SIZE / 2;
				ItemPtr item( new Item( x, y ) );
				mgr->add( item );
			}
		}
	}

	return mgr;
}

Vector Map::getMarkerPos( int idx ) const {
	return Vector( _panel[ idx ].marker_x, _panel[ idx ].marker_y ); 
}

void Map::addToStock( EnemyStockPtr stock, int bg_idx ) const {
	for ( int i = 0; i < MAPCHIP_NUM * MAPCHIP_NUM; i++ ) {
		char ch = _panel[ bg_idx ].chip[ i ];
		if ( ( ch < 'A' || ch > 'Z' ) &&
			 ( ch < 'a' || ch > 'z' ) ) {
			continue;
		}

		int x = bg_idx * BG_SIZE + i % MAPCHIP_NUM * MAPCHIP_SIZE + MAPCHIP_SIZE / 2; 
		int y =                    i / MAPCHIP_NUM * MAPCHIP_SIZE + MAPCHIP_SIZE - 1;
		EnemyPtr enemy = generateEnemy( ch, stock, x, y );
		if ( enemy ) {
			stock->addEnemy( enemy );
		}
	}
}

