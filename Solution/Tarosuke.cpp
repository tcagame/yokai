#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Keyboard.h"


Tarosuke::Tarosuke( int x, int y ) : 
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_TAROSUKE_001 );

	_chip_list[ 0 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_001;
	_chip_list[ 1 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_002;
	_chip_list[ 2 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_003;
	_chip_list[ 3 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_004;
	_chip_list[ 4 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_005;
	_chip_list[ 5 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_006;
	_chip_list[ 6 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_007;
	_chip_list[ 7 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_008;
	_chip_list[ 8 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_009;
	_chip_list[ 9 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_010;
	_chip_list[ 10 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_011;
	_chip_list[ 11 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_012;
	_chip_list[ 12 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_013;
	_chip_list[ 13 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_014;
	_chip_list[ 14 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_015;
	_chip_list[ 15 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_016;
	_chip_list[ 16 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_017;
	_chip_list[ 17 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_018;
	_chip_list[ 18 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_019;
	_chip_list[ 19 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_020;
	_chip_list[ 20 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_021;
	_chip_list[ 21 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_022;
	_chip_list[ 22 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_023;
	_chip_list[ 23 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_024;
	_chip_list[ 24 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_025;
	_chip_list[ 25 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_026;
	_chip_list[ 26 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_027;
	_chip_list[ 27 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_028;
	_chip_list[ 28 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_029;
	_chip_list[ 29 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_030;
	_chip_list[ 30 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_031;
	_chip_list[ 31 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_032;
	_chip_list[ 32 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_033;
	_chip_list[ 33 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_034;
	_chip_list[ 34 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_035;
	_chip_list[ 35 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_036;
	_chip_list[ 36 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_037;
	_chip_list[ 37 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_038;
	_chip_list[ 38 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_039;
	_chip_list[ 39 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_040;
	_chip_list[ 40 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_041;
	_chip_list[ 41 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_042;
	_chip_list[ 42 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_043;
	_chip_list[ 43 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_044;
	_chip_list[ 44 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_045;
	_chip_list[ 45 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_046;
	_chip_list[ 46 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_047;
	_chip_list[ 47 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_048;
	_chip_list[ 48 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_049;
	_chip_list[ 49 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_050;
	_chip_list[ 50 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_051;
	_chip_list[ 51 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_052;
	_chip_list[ 52 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_053;
	_chip_list[ 53 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_054;
	_chip_list[ 54 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_055;
	_chip_list[ 55 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_056;
	_chip_list[ 56 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_057;
	_chip_list[ 57 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_058;
	_chip_list[ 58 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_059;
	_chip_list[ 59 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_060;
	_chip_list[ 60 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_061;
	_chip_list[ 61 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_062;
	_chip_list[ 62 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_063;
	_chip_list[ 63 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_064;
	_chip_list[ 64 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_065;
	_chip_list[ 65 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_066;
	_chip_list[ 66 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_067;
	_chip_list[ 67 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_068;
	_chip_list[ 68 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_069;
	_chip_list[ 69 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_070;
	_chip_list[ 70 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_071;
	_chip_list[ 71 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_072;
	_chip_list[ 72 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_073;
	_chip_list[ 73 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_074;
	_chip_list[ 74 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_075;
	_chip_list[ 75 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_076;
	_chip_list[ 76 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_077;
	_chip_list[ 77 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_078;
	_chip_list[ 78 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_079;
	_chip_list[ 79 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_080;
	_chip_list[ 80 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_081;
	_chip_list[ 81 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_082;
	_chip_list[ 82 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_083;
	_chip_list[ 83 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_084;
	_chip_list[ 84 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_085;
	_chip_list[ 85 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_086;
	_chip_list[ 86 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_087;
	_chip_list[ 87 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_088;
	_chip_list[ 88 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_089;
	_chip_list[ 89 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_090;
	_chip_list[ 90 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_091;
	_chip_list[ 91 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_092;
	_chip_list[ 92 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_093;
	_chip_list[ 93 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_094;
	_chip_list[ 94 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_095;
	_chip_list[ 95 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_096;
	_chip_list[ 96 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_097;
	_chip_list[ 97 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_098;
	_chip_list[ 98 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_099;
	_chip_list[ 99 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_100;
	_chip_list[ 100 ] = ChipDrawer::CHIP::CHIP_TAROSUKE_101;
}


Tarosuke::~Tarosuke( ) {

}

void Tarosuke::debugChip( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "Q" ) ) {
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

void Tarosuke::updateAccel( ) {
	setAccelX( 0 );
	manipulate( );
	fall( );
}

void Tarosuke::manipulate( ) {
	const int MOVE_SPEED = 10;
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		setAccelX( -MOVE_SPEED );
	}
	if ( keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		setAccelX( MOVE_SPEED );
	}

}