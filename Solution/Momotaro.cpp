#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"
#include "Camera.h"
#include "mathmatics.h"

static const int MOVE_SPEED = 5;
static const int MAX_CHIP_PATTERN = 7;
static const int CHIP_MOMOTARO_NUM = 101;
static const int START_X = 360;
static const int START_Y = 360;
static const int CHIP_SIZE = 34 * 6;
static const int CHIP_FOOT = CHIP_SIZE / 2;

Momotaro::Momotaro( CameraConstPtr camera ) :
Character( START_X, START_Y, GRAPH_CHARACTER, CHIP_SIZE, CHIP_FOOT, false ),
_camera( camera ) {
}

Momotaro::~Momotaro( ) {
}

void Momotaro::act( ) {
	DevicePtr device = Device::getTask( );
	setAccelX( device->getDirX( ) );
	setAccelY( device->getDirY( ) );

	if ( getX( ) + getAccelX( ) < _camera->getX( ) ) {
		setAccelX( 0 );
	}
	if ( getX( ) + getAccelX( ) > _camera->getX( ) + SCREEN_WIDTH ) {
		setAccelX( 0 );
	}
	if ( getY( ) + getAccelY( ) < _camera->getY( ) ) {
		setAccelY( 0 );
	}
	if ( getY( ) + getAccelY( ) > _camera->getY( ) + SCREEN_HEIGHT ) {
		setAccelY( 0 );
	}

	Vector vec( getAccelX( ), getAccelY( ) );
	double length = vec.getLength( );
	vec = vec.normalize( ) * ( length / 10.0 );
	setAccelX( ( int )vec.x );
	setAccelY( ( int )vec.y );

	if ( device->getButton( ) == BUTTON_A ) {

	}

	setChipUV( 6, 7 );
}
