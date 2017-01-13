#include "Momotaro.h"
#include "Keyboard.h"

static const int MOVE_SPEED = 5;

Momotaro::Momotaro( int x, int y ) :
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_MOMOTARO_7 );
}


Momotaro::~Momotaro( ) {
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
	KeyboardPtr keyboard = Keyboard::getTask( );

}