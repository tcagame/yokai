#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Keyboard.h"



const int MAX_CHIP_NUM = 103;
ChipDrawer::CHIP _chip_list[ MAX_CHIP_NUM ] {
	ChipDrawer::CHIP::CHIP_TAROSUKE_001,
	ChipDrawer::CHIP::CHIP_TAROSUKE_002,
	ChipDrawer::CHIP::CHIP_TAROSUKE_003,
	ChipDrawer::CHIP::CHIP_TAROSUKE_004,
	ChipDrawer::CHIP::CHIP_TAROSUKE_005,
	ChipDrawer::CHIP::CHIP_TAROSUKE_006,
	ChipDrawer::CHIP::CHIP_TAROSUKE_007,
	ChipDrawer::CHIP::CHIP_TAROSUKE_008,
	ChipDrawer::CHIP::CHIP_TAROSUKE_009,
	ChipDrawer::CHIP::CHIP_TAROSUKE_010,
	ChipDrawer::CHIP::CHIP_TAROSUKE_011,
	ChipDrawer::CHIP::CHIP_TAROSUKE_012,
	ChipDrawer::CHIP::CHIP_TAROSUKE_013,
	ChipDrawer::CHIP::CHIP_TAROSUKE_014,
	ChipDrawer::CHIP::CHIP_TAROSUKE_015,
	ChipDrawer::CHIP::CHIP_TAROSUKE_016,
	ChipDrawer::CHIP::CHIP_TAROSUKE_017,
	ChipDrawer::CHIP::CHIP_TAROSUKE_018,
	ChipDrawer::CHIP::CHIP_TAROSUKE_019,
	ChipDrawer::CHIP::CHIP_TAROSUKE_020,
	ChipDrawer::CHIP::CHIP_TAROSUKE_021,
	ChipDrawer::CHIP::CHIP_TAROSUKE_022,
	ChipDrawer::CHIP::CHIP_TAROSUKE_023,
	ChipDrawer::CHIP::CHIP_TAROSUKE_024,
	ChipDrawer::CHIP::CHIP_TAROSUKE_025,
	ChipDrawer::CHIP::CHIP_TAROSUKE_026,
	ChipDrawer::CHIP::CHIP_TAROSUKE_027,
	ChipDrawer::CHIP::CHIP_TAROSUKE_028,
	ChipDrawer::CHIP::CHIP_TAROSUKE_029,
	ChipDrawer::CHIP::CHIP_TAROSUKE_030,
	ChipDrawer::CHIP::CHIP_TAROSUKE_031,
	ChipDrawer::CHIP::CHIP_TAROSUKE_032,
	ChipDrawer::CHIP::CHIP_TAROSUKE_033,
	ChipDrawer::CHIP::CHIP_TAROSUKE_034,
	ChipDrawer::CHIP::CHIP_TAROSUKE_035,
	ChipDrawer::CHIP::CHIP_TAROSUKE_036,
	ChipDrawer::CHIP::CHIP_TAROSUKE_037,
	ChipDrawer::CHIP::CHIP_TAROSUKE_038,
	ChipDrawer::CHIP::CHIP_TAROSUKE_039,
	ChipDrawer::CHIP::CHIP_TAROSUKE_040,
	ChipDrawer::CHIP::CHIP_TAROSUKE_041,
	ChipDrawer::CHIP::CHIP_TAROSUKE_042,
	ChipDrawer::CHIP::CHIP_TAROSUKE_043,
	ChipDrawer::CHIP::CHIP_TAROSUKE_044,
	ChipDrawer::CHIP::CHIP_TAROSUKE_045,
	ChipDrawer::CHIP::CHIP_TAROSUKE_047,
	ChipDrawer::CHIP::CHIP_TAROSUKE_048,
	ChipDrawer::CHIP::CHIP_TAROSUKE_049,
	ChipDrawer::CHIP::CHIP_TAROSUKE_050,
	ChipDrawer::CHIP::CHIP_TAROSUKE_051,
	ChipDrawer::CHIP::CHIP_TAROSUKE_052,
	ChipDrawer::CHIP::CHIP_TAROSUKE_053,
	ChipDrawer::CHIP::CHIP_TAROSUKE_054,
	ChipDrawer::CHIP::CHIP_TAROSUKE_055,
	ChipDrawer::CHIP::CHIP_TAROSUKE_056,
	ChipDrawer::CHIP::CHIP_TAROSUKE_057,
	ChipDrawer::CHIP::CHIP_TAROSUKE_058,
	ChipDrawer::CHIP::CHIP_TAROSUKE_059,
	ChipDrawer::CHIP::CHIP_TAROSUKE_060,
	ChipDrawer::CHIP::CHIP_TAROSUKE_061,
	ChipDrawer::CHIP::CHIP_TAROSUKE_062,
	ChipDrawer::CHIP::CHIP_TAROSUKE_063,
	ChipDrawer::CHIP::CHIP_TAROSUKE_064,
	ChipDrawer::CHIP::CHIP_TAROSUKE_065,
	ChipDrawer::CHIP::CHIP_TAROSUKE_066,
	ChipDrawer::CHIP::CHIP_TAROSUKE_067,
	ChipDrawer::CHIP::CHIP_TAROSUKE_068,
	ChipDrawer::CHIP::CHIP_TAROSUKE_069,
	ChipDrawer::CHIP::CHIP_TAROSUKE_070,
	ChipDrawer::CHIP::CHIP_TAROSUKE_071,
	ChipDrawer::CHIP::CHIP_TAROSUKE_072,
	ChipDrawer::CHIP::CHIP_TAROSUKE_073,
	ChipDrawer::CHIP::CHIP_TAROSUKE_074,
	ChipDrawer::CHIP::CHIP_TAROSUKE_075,
	ChipDrawer::CHIP::CHIP_TAROSUKE_076,
	ChipDrawer::CHIP::CHIP_TAROSUKE_077,
	ChipDrawer::CHIP::CHIP_TAROSUKE_078,
	ChipDrawer::CHIP::CHIP_TAROSUKE_079,
	ChipDrawer::CHIP::CHIP_TAROSUKE_080,
	ChipDrawer::CHIP::CHIP_TAROSUKE_081,
	ChipDrawer::CHIP::CHIP_TAROSUKE_082,
	ChipDrawer::CHIP::CHIP_TAROSUKE_083,
	ChipDrawer::CHIP::CHIP_TAROSUKE_084,
	ChipDrawer::CHIP::CHIP_TAROSUKE_085,
	ChipDrawer::CHIP::CHIP_TAROSUKE_086,
	ChipDrawer::CHIP::CHIP_TAROSUKE_087,
	ChipDrawer::CHIP::CHIP_TAROSUKE_088,
	ChipDrawer::CHIP::CHIP_TAROSUKE_089,
	ChipDrawer::CHIP::CHIP_TAROSUKE_090,
	ChipDrawer::CHIP::CHIP_TAROSUKE_091,
	ChipDrawer::CHIP::CHIP_TAROSUKE_092,
	ChipDrawer::CHIP::CHIP_TAROSUKE_093,
	ChipDrawer::CHIP::CHIP_TAROSUKE_094,
	ChipDrawer::CHIP::CHIP_TAROSUKE_095,
	ChipDrawer::CHIP::CHIP_TAROSUKE_096,
	ChipDrawer::CHIP::CHIP_TAROSUKE_097,
	ChipDrawer::CHIP::CHIP_TAROSUKE_098,
	ChipDrawer::CHIP::CHIP_TAROSUKE_099,
	ChipDrawer::CHIP::CHIP_TAROSUKE_100,
	ChipDrawer::CHIP::CHIP_TAROSUKE_101,
	ChipDrawer::CHIP::CHIP_TAROSUKE_102,
	ChipDrawer::CHIP::CHIP_TAROSUKE_103,
};

Tarosuke::Tarosuke( int x, int y ) : 
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_TAROSUKE_001 );

}


Tarosuke::~Tarosuke( ) {

}

void Tarosuke::debugChip( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "Q" ) ||
		keyboard->isPushKey( "W" ) ) {
		for ( int i = 0; i < MAX_CHIP_NUM; i++ ) {
			if ( getChip( ) == _chip_list[ i ] ) {
				_chip_num = i;
				break;
			}
		}
		if ( keyboard->isPushKey( "Q" ) ) {
			_chip_num++;
		}
		_chip_num %= ( MAX_CHIP_NUM - 1 );
		setChip( _chip_list[ _chip_num ] );
	}

}