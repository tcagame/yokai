#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"

static const int MOVE_SPEED = 5;
static const int MAX_CHIP_PATTERN = 7;
static const int CHIP_MOMOTARO_NUM = 101;

Momotaro::Momotaro( int x, int y ) :
MassCharacter( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_MOMOTARO_7 );
}


Momotaro::~Momotaro( ) {
}

void Momotaro::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( getDir( ) == DIR_RIGHT );

	chip_drawer->draw( getChip( ), getX( ), getY( ), reverse );
}

void Momotaro::updateAccel( ) {
	manipulate( );
}

void Momotaro::debugChip( ) {

	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "W" ) ) {
		setChip( ChipDrawer::CHIP( ( ( getChip( ) + 1 ) - ChipDrawer::CHIP::CHIP_MOMOTARO_1 ) %
			( MAX_CHIP_PATTERN - 1 ) + ChipDrawer::CHIP::CHIP_MOMOTARO_1 ) );
	}

}

void Momotaro::manipulate( ) {
	DevicePtr device = Device::getTask( );
	int accel_x = device->getDirX( ) / CHARA_MOVE_RATIO;
	int accel_y = device->getDirY( ) / CHARA_MOVE_RATIO;
	setAccelX( accel_x );
	setAccelY( accel_y );
	if ( device->getButton( ) == BUTTON_A ) {

	}
}

void Momotaro::adjustX( ) {
	if ( getX( ) < 0 ) {
		setX( 0 );
	}
	if ( getX( ) > SCREEN_WIDTH - CHIP_SIZE ) {
		setX( SCREEN_WIDTH - CHIP_SIZE );
	}
}

void Momotaro::adjustY( ) {
	if ( getY( ) < 0 ) {
		setY( 0 );
	}
	if ( getY( ) > SCREEN_HEIGHT - CHIP_SIZE ) {
		setY( SCREEN_HEIGHT - CHIP_SIZE );
	}
}