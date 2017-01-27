#include "Map.h"
#include "define.h"
#include "CloudMgr.h"
#include "Cloud.h"
#include "BossRedDemon.h"
#include "BossBlueDemon.h"

Map::Map( const Item * item, const Panel * panel, int panel_num ) :
_item( item ),
_panel( panel ),
_panel_num( panel_num ) {
}

Map::~Map( ) {
}

int Map::getLength( ) const {
	return _panel_num * BG_SIZE;
}

const char * Map::getBgFilename( int idx ) const {
	return _panel[ idx ].bg_filename;
}

const char * Map::getCoverFilename( int idx ) const {
	return _panel[ idx ].cover_filename;
}

const unsigned int Map::getEnemyData( int idx ) const {
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

BossPtr Map::createBoss( EnemyStockPtr enemy_stock ) const {
	
	BossPtr boss;
	switch ( _item->boss ) {
	case BOSS_REDDEMON:
		boss = BossPtr( new BossRedDemon( enemy_stock, getLength( ) - BG_SIZE ) );
		break;
	case BOSS_BLUEDEMON:
		boss = BossPtr( new BossBlueDemon( enemy_stock, getLength( ) - BG_SIZE ) );
		break;
	} 

	return boss;
}
