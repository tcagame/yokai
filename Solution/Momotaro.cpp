#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"

static const int MOVE_SPEED = 5;

Momotaro::Momotaro( int x, int y ) :
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_MOMOTARO_7 );
}


Momotaro::~Momotaro( ) {
}

void Momotaro::updateAccel( ) {
	manipulate( );
}

void Momotaro::debugChip( ) {
	const int MAX_CHIP_PATTERN = 7;
	const int CHIP_MOMOTARO_NUM = 101;
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
	if ( accel_x < 0 ) {
		setDir( DIR_LEFT );
	}
	if ( accel_x > 0 ) {
		setDir( DIR_RIGHT );
	}
}
