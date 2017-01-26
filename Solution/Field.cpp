#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"
#include "Cloud.h"
#include "CloudMgr.h"
#include "Keyboard.h"
#include "Game.h"

Field::Field( MapConstPtr map ) :
_map( map ),
_enemy_data( 0 ) {
	_idx = 0;
	_scroll_x = 0;
	_scroll_y = -48; // ÅI“I‚É‚ÍƒJƒƒ‰‚©‚çŽæ“¾

	_cloud_mgr = map->createCloudMgr( );
	
	DrawerPtr drawer = Drawer::getTask( );
	for ( int i = 0; i < BG_NUM; i++ ) {
		int graph_bg = GRAPH_BG + ( _idx + i ) % BG_NUM;
		drawer->loadGraph( graph_bg, _map->getBgFilename( _idx + i ) );

		int graph_cover = GRAPH_COVER + ( _idx + i ) % BG_NUM;
		drawer->unloadGraph( graph_cover );
		std::string str = _map->getCoverFilename( _idx + i );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_cover, _map->getCoverFilename( _idx + i ) );
		}
	}

	_debug_mapchip = false;
}

Field::~Field( ) {
}

void Field::update( CameraConstPtr camera ) {
	scroll( camera );
	moveClouds( );

	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "C" ) ) {
		_debug_mapchip = !_debug_mapchip; 
	}
}

void Field::scroll( CameraConstPtr camera ) {
	int idx = camera->getX( ) / BG_SIZE;
	if ( idx != _idx ) {
		int new_idx = idx;
		if ( idx > _idx ) {
			new_idx = idx + BG_NUM - 1;
			_enemy_data = _map->getEnemyData( idx + BG_NUM - 1 );
		}

		DrawerPtr drawer = Drawer::getTask( );

		int graph_bg = GRAPH_BG + new_idx % BG_NUM;
		drawer->loadGraph( graph_bg, _map->getBgFilename( new_idx ) );
		
		int graph_cover = GRAPH_COVER + new_idx % BG_NUM;
		drawer->unloadGraph( graph_cover );
		std::string str = _map->getCoverFilename( new_idx );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_cover, _map->getCoverFilename( new_idx ) );
		}
		_idx = idx;
	}

	_scroll_x = _idx * BG_SIZE - camera->getX( );
	_scroll_y = -camera->getY( );
}

void Field::moveClouds( ) {
	_cloud_mgr->update( );
}

void Field::draw( CameraConstPtr camera ) const {
	drawBG( );
	drawChip( );
	drawClouds( camera );
}

void Field::drawCover( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	for ( int i = 0; i < BG_NUM; i++ ) {
		int graph = GRAPH_COVER + ( _idx + i ) % BG_NUM;
		Drawer::Sprite sprite( 
			Drawer::Transform( _scroll_x + i * BG_SIZE, _scroll_y ),
			graph );
		drawer->setSprite( sprite );
	}
}

void Field::drawBG( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	for ( int i = 0; i < BG_NUM; i++ ) {
		int graph = GRAPH_BG + ( _idx + i ) % BG_NUM;
		Drawer::Sprite sprite( 
			Drawer::Transform( _scroll_x + i * BG_SIZE, _scroll_y ),
			graph );
		drawer->setSprite( sprite );
	}
}

void Field::drawChip( ) const {
	GamePtr game = Game::getTask( );
	if ( !game->isDebug( ) ) {
		return;
	}

	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < BG_NUM; i++ ) {
		int bg_idx = _idx + i;
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			bool b = _map->isChip( bg_idx, j );
			if ( !b ) {
				continue;
			}

			int x = _scroll_x + i * BG_SIZE + j % MAPCHIP_NUM * MAPCHIP_SIZE;
			int y = _scroll_y               + j / MAPCHIP_NUM * MAPCHIP_SIZE;
			Drawer::Sprite sprite( 
				Drawer::Transform( x, y ),
				GRAPH_MAPCHIPGUIDE );
			drawer->setSprite( sprite );
		}
	}
}

void Field::drawClouds( CameraConstPtr camera ) const {
	_cloud_mgr->draw( camera );
}

FLOOR Field::getFloor( int x, int y ) const {
	if ( x < 0 || x >= _map->getLength( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return FLOOR_ROAD;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->getFloor( bg_idx, chip_idx );
}

bool Field::isChip( int x, int y ) const {
	if ( x < 0 || x >= _map->getLength( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return false;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->isChip( bg_idx, chip_idx );
}

Field::Collision Field::getCollision( int src_x, int src_y, int dst_x, int dst_y ) const {
	Collision collision;
	collision.overlapped_x = false;
	collision.overlapped_y = false;
	collision.adjust_x = 0;
	collision.adjust_y = 0;
	
	if ( dst_y > src_y ) {
		if ( !isChip( src_x, src_y ) && isChip( src_x, dst_y ) ) {
			collision.adjust_y = dst_y / MAPCHIP_SIZE * MAPCHIP_SIZE - 1;
			collision.overlapped_y = true;
			dst_y = collision.adjust_y;
		}
		
		CloudPtr cloud = _cloud_mgr->getOnStanding( src_x, src_y, dst_y );
		if ( cloud ) {
			collision.adjust_y = cloud->getY( ) - cloud->getHeight( ) / 2 + cloud->getBlank( ) - 1;
			collision.overlapped_y = true;
			collision.cloud = cloud;
			dst_y = collision.adjust_y;
		}

	}

	{
		if ( !isChip( src_x, dst_y ) && isChip( dst_x, dst_y ) ) {
			int dif = dst_x % MAPCHIP_SIZE;
			int x = dst_x / MAPCHIP_SIZE * MAPCHIP_SIZE;
			if ( dif < MAPCHIP_SIZE / 2 ) {
				x -= 1;
			} else {
				x += MAPCHIP_SIZE;
			}
			collision.adjust_x = x;
			collision.overlapped_x = true;
		}
	}

	return collision;
}

unsigned int Field::getEnemyData( ) {
	unsigned int enemy_data = _enemy_data;
	_enemy_data = 0x00000000;
	return enemy_data;
}

