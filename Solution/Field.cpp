#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"
#include "CloudManager.h"

Field::Field( MapConstPtr map, CloudManagerPtr cloud_mgr ) :
_map( map ), _cloud_mgr( cloud_mgr ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE, "street/mapchipguide.png" );

	_idx = -1;
	_x = 0;
	_y = -48; // 最終的にはカメラから取得
}


Field::~Field( ) {
}

void Field::update( CameraConstPtr camera ) {
	int idx = camera->getX( ) / BG_SIZE;
	if ( idx != _idx ) {
		_idx = idx;

		DrawerPtr drawer = Drawer::getTask( );

		for ( int i = 0; i < 3; i++ ) {
			drawer->unloadGraph( GRAPH_BG + i );
		}

		for ( int i = 0; i < 3; i++ ) {
			drawer->loadGraph( GRAPH_BG + i, _map->getFilename( _idx + i ) );
		}
	}

	_x = idx * BG_SIZE - camera->getX( );
	_y = -camera->getY( );
}

void Field::draw( ) const {
	drawBG( );
	drawChip( );
}

void Field::drawBG( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	for ( int i = 0; i < 3; i++ ) {
		Drawer::Sprite sprite( 
			Drawer::Transform( _x + i * BG_SIZE, _y ),
			GRAPH_BG + i );
		drawer->setSprite( sprite );
	}
}

void Field::drawChip( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < 3; i++ ) {
		int bg_idx = _idx + i;
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			bool b = _map->isChip( bg_idx, j );
			if ( !b ) {
				continue;
			}

			int x = _x + i * BG_SIZE + j % MAPCHIP_NUM * MAPCHIP_SIZE;
			int y = _y               + j / MAPCHIP_NUM * MAPCHIP_SIZE;
			Drawer::Sprite sprite( 
				Drawer::Transform( x, y ),
				GRAPH_MAPCHIPGUIDE );
			drawer->setSprite( sprite );
		}
	}
}

bool Field::isChip( int x, int y ) const {
	// mapクラスにチップと重なっているか確認する Map::isChipを使う

	if ( x < 0 || x >= _map->getLength( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return false;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 
	


	return _map->isChip( bg_idx, chip_idx );
}

bool Field::isCloudExistence( int x, int y ) const {
	return _cloud_mgr->isCloudExistence( x, y );
}

CloudPtr Field::getCloudPtr( ) const {
	return _cloud_mgr->getCloudPtr( );
}