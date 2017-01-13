#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"

Field::Field( MapConstPtr map ) :
_map( map ) {
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
	_y = -48; // 最終的にはカメラから取得
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
			if ( !_map->isChipIdx( bg_idx, j ) ) {
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
