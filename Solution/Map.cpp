#include "Map.h"
#include "define.h"
#include "CloudMgr.h"
#include "Cloud.h"
#include "EnemyStock.h"

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

const unsigned long long Map::getEnemyData( int idx ) const {
	return _panel[ idx ].enemy;
}

bool Map::isChip( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '#';
}

bool Map::isBlockChip( int bg_idx, int chip_idx ) const {
	return _panel[ bg_idx ].chip[ chip_idx ] == '*';
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

Vector Map::getMarkerPos( int idx ) const {
	return Vector( _panel[ idx ].marker_x, _panel[ idx ].marker_y ); 
}

void Map::addToStock( EnemyStockPtr stock, int bg_idx ) const {
	for ( int i = 0; i < MAPCHIP_NUM * MAPCHIP_NUM; i++ ) {
		char ch = _panel[ bg_idx ].chip[ i ];
		if ( ch < 'A' || ch > 'Z' ) {
			continue;
		}

		int x = bg_idx * BG_SIZE + i % MAPCHIP_NUM * MAPCHIP_SIZE + MAPCHIP_SIZE / 2; 
		int y =                    i / MAPCHIP_NUM * MAPCHIP_SIZE + MAPCHIP_SIZE - 1;
		EnemyPtr enemy = generateEnemy( ch, x, y );
		if ( enemy ) {
			stock->addEnemy( enemy );
		}
	}
}

