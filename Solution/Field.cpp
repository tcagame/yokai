#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"
#include "Cloud.h"
#include "CloudMgr.h"
#include "ItemMgr.h"
#include "Keyboard.h"
#include "Game.h"
#include "EnemyStock.h"
#include "EnemyHellFire.h"

static const int HEAD_HEIGHT = 100;
static const int REBORN_RANGE = 2;
static const int HELLFIRE_COUNT = 300;

Field::Field( MapConstPtr map, EnemyStockPtr stock ) :
_map( map ),
_stock( stock ) {
	_idx = 0;

	_scroll_x = 0;
	_scroll_y = -48; // ÅI“I‚É‚ÍƒJƒƒ‰‚©‚çŽæ“¾
	_hellfire_count = 0;
	_cloud_mgr = map->createCloudMgr( );
	_item_mgr  = map->createItemMgr( );

	DrawerPtr drawer = Drawer::getTask( );

	_create_idx = 0;
	for ( int i = 0; i < BG_NUM; i++ ) {
		std::string str;

		int graph_bg = GRAPH_BG + ( _idx + i ) % BG_NUM;
		drawer->unloadGraph( graph_bg );
		str = _map->getBgFilename( _idx + i );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_bg, str.c_str( ) );
		}

		int graph_cover = GRAPH_COVER + ( _idx + i ) % BG_NUM;
		drawer->unloadGraph( graph_cover );
		str = _map->getCoverFilename( _idx + i );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_cover, str.c_str( ) ); 
		}
		
		_map->addToStock( _stock, i);
	}

	initMark( );
}

Field::~Field( ) {
}

void Field::initMark( ) {
	int num = _map->getPanelNum( );
	_markers.resize( num );

	int s = 0;
	for ( int i = 1; i < num + 1; i++ ) {
		Vector dst = _map->getMarkerPos( i );
		if ( dst.isOrijin( ) ) {
			if ( i < num ) { 
				continue;
			}
			dst = _map->getMarkerPos( s );
		}

		int c = i - s;
		for ( int j = 0; j < c; j++ ) {
			Vector src = _map->getMarkerPos( s );
			_markers[ s + j ] = src + ( dst - src ) * j * ( 1.0 / c );
		}

		s = i;
	}
}

int Field::getLimitX( ) const {
	return ( _map->getPanelNum( ) - 1 ) * BG_SIZE;
}

Vector Field::getStatusMarkerPos( int x ) const {
	int idx = x / BG_SIZE;
	Vector src = _markers[ idx ];
	Vector dst = src;
	if ( idx + 1 < ( int )_markers.size( ) ) {
		dst = _markers[ idx + 1 ];
	}
	double offset = x % BG_SIZE;
	return src + ( dst - src ) * ( offset / BG_SIZE );
}

void Field::update( CameraConstPtr camera, TarosukePtr tarosuke ) {
	scroll( camera );
	_cloud_mgr->update( );
	_item_mgr->update( camera, tarosuke );
}

void Field::scroll( CameraConstPtr camera ) {
	int idx = camera->getX( ) / BG_SIZE;
	if ( idx != _idx ) {
		int new_idx = idx;
		if ( idx > _idx ) {
			new_idx = idx + BG_NUM - 1;
		}

		DrawerPtr drawer = Drawer::getTask( );
		std::string str;
		
		int graph_bg = GRAPH_BG + new_idx % BG_NUM;
		drawer->unloadGraph( graph_bg );
		str = _map->getBgFilename( new_idx );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_bg, str.c_str( ) );
		}
		int graph_cover = GRAPH_COVER + new_idx % BG_NUM;
		drawer->unloadGraph( graph_cover );
		str = _map->getCoverFilename( new_idx );
		if ( !str.empty( ) ) {
			drawer->loadGraph( graph_cover, _map->getCoverFilename( new_idx ) );
		}
		_idx = idx;
		
		if ( _create_idx < _idx ) {
			_hellfire_count = 0;
			_create_idx = _idx;
			_map->addToStock( _stock, _create_idx + BG_NUM - 1 );
		}
		if ( _idx < _create_idx - REBORN_RANGE ) {
			_create_idx -= REBORN_RANGE;
		}
	}

	_scroll_x = _idx * BG_SIZE - camera->getX( );
	_scroll_y = -camera->getY( );
	
	if ( !camera->isLocked( ) ) {
		_hellfire_count++;
		if ( _hellfire_count > HELLFIRE_COUNT ) {
			_hellfire_count = 0;
			_stock->addEnemy( EnemyPtr( new EnemyHellFire( camera->getX( ), 0 ) ) );
		}
	}
}

void Field::draw( CameraConstPtr camera ) const {
	drawFarBG( camera );
	drawBG( );
	drawChip( );
	_cloud_mgr->draw( camera );
	_item_mgr->draw( camera );
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

void Field::drawFarBG( CameraConstPtr camera ) const {
	DrawerPtr drawer = Drawer::getTask( );
	for ( int i = 0; i < 4; i++ ) {
		Drawer::Sprite sprite( 
			Drawer::Transform( i * BG_SIZE - camera->getX( ) / 4 % BG_SIZE, 208 ),
			GRAPH_FAR_BG );
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

FLOOR Field::getFloor( int x, int y ) const {
	if ( x < 0 || x >= _map->getPanelNum( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return FLOOR_ROAD;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->getFloor( bg_idx, chip_idx );
}

bool Field::isChip( int x, int y ) const {
	if ( x < 0 || x >= _map->getPanelNum( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return false;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->isChip( bg_idx, chip_idx );
}

bool Field::isBlockChip( int x, int y ) const {
	if ( x < 0 || x >= _map->getPanelNum( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return false;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->isBlockChip( bg_idx, chip_idx );
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
	} else {
		if ( isBlockChip( src_x, dst_y - HEAD_HEIGHT ) ) {
			collision.adjust_y = ( dst_y - HEAD_HEIGHT ) / MAPCHIP_SIZE * MAPCHIP_SIZE + MAPCHIP_SIZE + HEAD_HEIGHT + 1;
			collision.overlapped_y = true;
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
