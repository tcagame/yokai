#pragma once

#include <array>

class ChipDrawer {
public:
	enum CHIP {
		CHIP_TAROSUKE_001,//103
		CHIP_TAROSUKE_002,
		CHIP_TAROSUKE_003,
		CHIP_TAROSUKE_004,
		CHIP_TAROSUKE_005,
		CHIP_TAROSUKE_006,
		CHIP_TAROSUKE_007,
		CHIP_TAROSUKE_008,
		CHIP_TAROSUKE_009,
		CHIP_TAROSUKE_010,
		CHIP_TAROSUKE_011,
		CHIP_TAROSUKE_012,
		CHIP_TAROSUKE_013,
		CHIP_TAROSUKE_014,
		CHIP_TAROSUKE_015,
		CHIP_TAROSUKE_016,
		CHIP_TAROSUKE_017,
		CHIP_TAROSUKE_018,
		CHIP_TAROSUKE_019,
		CHIP_TAROSUKE_020,
		CHIP_TAROSUKE_021,
		CHIP_TAROSUKE_022,
		CHIP_TAROSUKE_023,
		CHIP_TAROSUKE_024,
		CHIP_TAROSUKE_025,
		CHIP_TAROSUKE_026,
		CHIP_TAROSUKE_027,
		CHIP_TAROSUKE_028,
		CHIP_TAROSUKE_029,//
		CHIP_TAROSUKE_030,
		CHIP_TAROSUKE_031,
		CHIP_TAROSUKE_032,
		CHIP_TAROSUKE_033,
		CHIP_TAROSUKE_034,
		CHIP_TAROSUKE_035,
		CHIP_TAROSUKE_036,
		CHIP_TAROSUKE_037,
		CHIP_TAROSUKE_038,
		CHIP_TAROSUKE_039,
		CHIP_TAROSUKE_040,
		CHIP_TAROSUKE_041,
		CHIP_TAROSUKE_042,
		CHIP_TAROSUKE_043,
		CHIP_TAROSUKE_044,
		CHIP_TAROSUKE_045,
		CHIP_TAROSUKE_046,
		CHIP_TAROSUKE_047,
		CHIP_TAROSUKE_048,
		CHIP_TAROSUKE_049,
		CHIP_TAROSUKE_050,
		CHIP_TAROSUKE_051,
		CHIP_TAROSUKE_052,
		CHIP_TAROSUKE_053,
		CHIP_TAROSUKE_054,
		CHIP_TAROSUKE_055,
		CHIP_TAROSUKE_056,
		CHIP_TAROSUKE_057,
		CHIP_TAROSUKE_058,
		CHIP_TAROSUKE_059,
		CHIP_TAROSUKE_060,
		CHIP_TAROSUKE_061,
		CHIP_TAROSUKE_062,
		CHIP_TAROSUKE_063,
		CHIP_TAROSUKE_064,
		CHIP_TAROSUKE_065,
		CHIP_TAROSUKE_066,
		CHIP_TAROSUKE_067,
		CHIP_TAROSUKE_068,
		CHIP_TAROSUKE_069,
		CHIP_TAROSUKE_070,
		CHIP_TAROSUKE_071,
		CHIP_TAROSUKE_072,
		CHIP_TAROSUKE_073,
		CHIP_TAROSUKE_074,
		CHIP_TAROSUKE_075,
		CHIP_TAROSUKE_076,
		CHIP_TAROSUKE_077,
		CHIP_TAROSUKE_078,
		CHIP_TAROSUKE_079,
		CHIP_TAROSUKE_080,
		CHIP_TAROSUKE_081,
		CHIP_TAROSUKE_082,
		CHIP_TAROSUKE_083,
		CHIP_TAROSUKE_084,
		CHIP_TAROSUKE_085,
		CHIP_TAROSUKE_086,
		CHIP_TAROSUKE_087,
		CHIP_TAROSUKE_088,
		CHIP_TAROSUKE_089,
		CHIP_TAROSUKE_090,
		CHIP_TAROSUKE_091,
		CHIP_TAROSUKE_092,
		CHIP_TAROSUKE_093,
		CHIP_TAROSUKE_094,
		CHIP_TAROSUKE_095,
		CHIP_TAROSUKE_096,
		CHIP_TAROSUKE_097,
		CHIP_TAROSUKE_098,
		CHIP_TAROSUKE_099,
		CHIP_TAROSUKE_100,
		CHIP_TAROSUKE_101,
		CHIP_TAROSUKE_102,
		CHIP_TAROSUKE_103,

		CHIP_MOMOTARO_1,
		CHIP_MOMOTARO_2,
		CHIP_MOMOTARO_3,
		CHIP_MOMOTARO_4,
		CHIP_MOMOTARO_5,
		CHIP_MOMOTARO_6,
		CHIP_MOMOTARO_7,
		
		MAX_CHIP
	};
	struct ChipPos {
		int cx;
		int cy;
		ChipPos( ) {
		};
		ChipPos( int x, int y ) :
			cx( x ), cy( y ) {
		}
	};
public:
	ChipDrawer( );
	~ChipDrawer( );
	void draw( CHIP chip, int sx, int sy );
private:
	std::array< ChipPos, MAX_CHIP > _chip_pos;
};

