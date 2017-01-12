#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"

static const int BG_X = 0;
static const int BG_Y = -48;
static const int BG_SIZE = 758;

Field::Field( MapConstPtr map ) :
_map( map ) {
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
			drawer->loadGraph( GRAPH_BG + i, _map->getBGFilename( _idx + i ) );
		}
	}

	_x = idx * BG_SIZE - camera->getX( );
	_y = -48; // 最終的にはカメラから取得
}

void Field::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	for ( int i = 0; i < 3; i++ ) {
		Drawer::Sprite sprite( 
			Drawer::Transform( _x + i * BG_SIZE, _y ),
			GRAPH_BG + i );
		drawer->setSprite( sprite );
	}
}

