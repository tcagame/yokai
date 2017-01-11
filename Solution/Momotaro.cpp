#include "Momotaro.h"
#include "Keyboard.h"


Momotaro::Momotaro( int x, int y ) :
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_MOMOTARO_7 );
	_chip_list[ 0 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_1;
	_chip_list[ 1 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_2;
	_chip_list[ 2 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_3;
	_chip_list[ 3 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_4;
	_chip_list[ 4 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_5;
	_chip_list[ 5 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_6;
	_chip_list[ 6 ] = ChipDrawer::CHIP::CHIP_MOMOTARO_7;
}


Momotaro::~Momotaro( ) {
}

void Momotaro::debugChip( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "W" ) ) {
		for ( int i = 0; i < MAX_CHIP_NUM; i++ ) {
			if ( getChip( ) == _chip_list[ i ] ) {
				_chip_num = i;
				break;
			}
		}
		_chip_num++;
		_chip_num %= ( MAX_CHIP_NUM - 1 );
		setChip( _chip_list[ _chip_num ] );
	}

}