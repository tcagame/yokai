#include "Status.h"
#include "Camera.h"
#include "Momotaro.h"
#include "Drawer.h"

static const int LEFT_POS_X = 10;
static const int RIGHT_POS_X = 880;
static const int GRAPH_X = 384;
static const int GRAPH_Y = 147;

Status::Status( ) {
	_x = LEFT_POS_X;
}

Status::~Status( ) {
}

void Status::update( CameraConstPtr camera, MomotaroConstPtr momotaro ) {
	_x = LEFT_POS_X;

	if ( momotaro->getX( ) < 0 ||
		 momotaro->getY( ) < 0 ) {
		return;
	}

	if ( momotaro->getY( ) - momotaro->getSize( ) < GRAPH_Y ) {
		if ( ( momotaro->getX( ) - momotaro->getSize( ) / 2 ) - camera->getX( ) < GRAPH_X ) {
			_x = RIGHT_POS_X;
		}
	}
}

void Status::draw( ) {
	const int sy = 10;

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( _x, sy );
	Drawer::Sprite sprite( trans, GRAPH_STATUS );
	drawer->setSprite( sprite );
}