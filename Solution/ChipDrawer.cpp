#include "ChipDrawer.h"
#include "Drawer.h"

ChipDrawer::ChipDrawer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER, "Yokai_OBJ_myCharacter.png" );
	_chip_pos[ CHIP_TAROSUKE_001 ] = CHIP_POS(  0,  0 );
	_chip_pos[ CHIP_TAROSUKE_002 ] = CHIP_POS(  1,  0 );
	_chip_pos[ CHIP_TAROSUKE_003 ] = CHIP_POS(  2,  0 );
	_chip_pos[ CHIP_TAROSUKE_004 ] = CHIP_POS(  3,  0 );
	_chip_pos[ CHIP_TAROSUKE_005 ] = CHIP_POS(  4,  0 );
	_chip_pos[ CHIP_TAROSUKE_006 ] = CHIP_POS(  5,  0 );
	_chip_pos[ CHIP_TAROSUKE_007 ] = CHIP_POS(  6,  0 );
	_chip_pos[ CHIP_TAROSUKE_008 ] = CHIP_POS(  0,  1 );
	_chip_pos[ CHIP_TAROSUKE_009 ] = CHIP_POS(  1,  1 );
	_chip_pos[ CHIP_TAROSUKE_010 ] = CHIP_POS(  2,  1 );
	_chip_pos[ CHIP_TAROSUKE_011 ] = CHIP_POS(  3,  1 );
	_chip_pos[ CHIP_TAROSUKE_012 ] = CHIP_POS(  4,  1 );
	_chip_pos[ CHIP_TAROSUKE_013 ] = CHIP_POS(  5,  1 );
	_chip_pos[ CHIP_TAROSUKE_014 ] = CHIP_POS(  6,  1 );
	_chip_pos[ CHIP_TAROSUKE_015 ] = CHIP_POS(  7,  1 );
	_chip_pos[ CHIP_TAROSUKE_016 ] = CHIP_POS(  8,  1 );
	_chip_pos[ CHIP_TAROSUKE_017 ] = CHIP_POS(  9,  1 );
	_chip_pos[ CHIP_TAROSUKE_018 ] = CHIP_POS(  0,  1 );
	_chip_pos[ CHIP_TAROSUKE_019 ] = CHIP_POS(  1,  2 );
	_chip_pos[ CHIP_TAROSUKE_020 ] = CHIP_POS(  2,  2 );
	_chip_pos[ CHIP_TAROSUKE_021 ] = CHIP_POS(  3,  2 );
	_chip_pos[ CHIP_TAROSUKE_022 ] = CHIP_POS(  4,  2 );
	_chip_pos[ CHIP_TAROSUKE_023 ] = CHIP_POS(  5,  2 );
	_chip_pos[ CHIP_TAROSUKE_024 ] = CHIP_POS(  6,  2 );
	_chip_pos[ CHIP_TAROSUKE_025 ] = CHIP_POS(  7,  2 );
	_chip_pos[ CHIP_TAROSUKE_026 ] = CHIP_POS(  8,  2 );
	_chip_pos[ CHIP_TAROSUKE_027 ] = CHIP_POS(  9,  2 );
	_chip_pos[ CHIP_TAROSUKE_028 ] = CHIP_POS( 10,  2 );
	_chip_pos[ CHIP_TAROSUKE_029 ] = CHIP_POS( 11,  2 );
	_chip_pos[ CHIP_TAROSUKE_030 ] = CHIP_POS(  0,  3 );
	_chip_pos[ CHIP_TAROSUKE_031 ] = CHIP_POS(  1,  3 );
	_chip_pos[ CHIP_TAROSUKE_032 ] = CHIP_POS(  2,  3 );
	_chip_pos[ CHIP_TAROSUKE_033 ] = CHIP_POS(  3,  3 );
	_chip_pos[ CHIP_TAROSUKE_034 ] = CHIP_POS(  4,  3 );
	_chip_pos[ CHIP_TAROSUKE_035 ] = CHIP_POS(  5,  3 );
	_chip_pos[ CHIP_TAROSUKE_036 ] = CHIP_POS(  0,  4 );
	_chip_pos[ CHIP_TAROSUKE_037 ] = CHIP_POS(  1,  4 );
	_chip_pos[ CHIP_TAROSUKE_038 ] = CHIP_POS(  2,  4 );
	_chip_pos[ CHIP_TAROSUKE_039 ] = CHIP_POS(  3,  4 );
	_chip_pos[ CHIP_TAROSUKE_040 ] = CHIP_POS(  4,  4 );
	_chip_pos[ CHIP_TAROSUKE_041 ] = CHIP_POS(  5,  4 );
	_chip_pos[ CHIP_TAROSUKE_042 ] = CHIP_POS(  6,  4 );
	_chip_pos[ CHIP_TAROSUKE_043 ] = CHIP_POS(  7,  4 );
	_chip_pos[ CHIP_TAROSUKE_044 ] = CHIP_POS(  8,  4 );
	_chip_pos[ CHIP_TAROSUKE_045 ] = CHIP_POS(  9,  4 );
	_chip_pos[ CHIP_TAROSUKE_046 ] = CHIP_POS(  0,  5 );
	_chip_pos[ CHIP_TAROSUKE_047 ] = CHIP_POS(  1,  5 );
	_chip_pos[ CHIP_TAROSUKE_048 ] = CHIP_POS(  2,  5 );
	_chip_pos[ CHIP_TAROSUKE_049 ] = CHIP_POS(  3,  5 );
	_chip_pos[ CHIP_TAROSUKE_050 ] = CHIP_POS(  4,  5 );
	_chip_pos[ CHIP_TAROSUKE_051 ] = CHIP_POS(  5,  5 );
	_chip_pos[ CHIP_TAROSUKE_052 ] = CHIP_POS(  6,  5 );
	_chip_pos[ CHIP_TAROSUKE_053 ] = CHIP_POS(  7,  5 );
	_chip_pos[ CHIP_TAROSUKE_054 ] = CHIP_POS(  8,  5 );
	_chip_pos[ CHIP_TAROSUKE_055 ] = CHIP_POS(  0,  6 );
	_chip_pos[ CHIP_TAROSUKE_056 ] = CHIP_POS(  1,  6 );
	_chip_pos[ CHIP_TAROSUKE_057 ] = CHIP_POS(  2,  6 );
	_chip_pos[ CHIP_TAROSUKE_058 ] = CHIP_POS(  3,  6 );
	_chip_pos[ CHIP_TAROSUKE_059 ] = CHIP_POS(  4,  6 );
	_chip_pos[ CHIP_TAROSUKE_060 ] = CHIP_POS(  5,  6 );
	_chip_pos[ CHIP_TAROSUKE_061 ] = CHIP_POS(  6,  6 );
	_chip_pos[ CHIP_TAROSUKE_062 ] = CHIP_POS(  0, 10 );
	_chip_pos[ CHIP_TAROSUKE_063 ] = CHIP_POS(  1, 10 );
	_chip_pos[ CHIP_TAROSUKE_064 ] = CHIP_POS(  2, 10 );
	_chip_pos[ CHIP_TAROSUKE_065 ] = CHIP_POS(  3, 10 );
	_chip_pos[ CHIP_TAROSUKE_066 ] = CHIP_POS(  4, 10 );
	_chip_pos[ CHIP_TAROSUKE_067 ] = CHIP_POS(  5, 10 );
	_chip_pos[ CHIP_TAROSUKE_068 ] = CHIP_POS(  6, 10 );
	_chip_pos[ CHIP_TAROSUKE_069 ] = CHIP_POS(  7, 10 );
	_chip_pos[ CHIP_TAROSUKE_070 ] = CHIP_POS(  8, 10 );
	_chip_pos[ CHIP_TAROSUKE_071 ] = CHIP_POS(  0, 11 );
	_chip_pos[ CHIP_TAROSUKE_072 ] = CHIP_POS(  1, 11 );
	_chip_pos[ CHIP_TAROSUKE_073 ] = CHIP_POS(  2, 11 );
	_chip_pos[ CHIP_TAROSUKE_074 ] = CHIP_POS(  3, 11 );
	_chip_pos[ CHIP_TAROSUKE_075 ] = CHIP_POS(  4, 11 );
	_chip_pos[ CHIP_TAROSUKE_076 ] = CHIP_POS(  5, 11 );
	_chip_pos[ CHIP_TAROSUKE_077 ] = CHIP_POS(  6, 11 );
	_chip_pos[ CHIP_TAROSUKE_078 ] = CHIP_POS(  7, 11 );
	_chip_pos[ CHIP_TAROSUKE_079 ] = CHIP_POS(  0, 12 );
	_chip_pos[ CHIP_TAROSUKE_080 ] = CHIP_POS(  1, 12 );
	_chip_pos[ CHIP_TAROSUKE_081 ] = CHIP_POS(  2, 12 );
	_chip_pos[ CHIP_TAROSUKE_082 ] = CHIP_POS(  3, 12 );
	_chip_pos[ CHIP_TAROSUKE_083 ] = CHIP_POS(  4, 12 );
	_chip_pos[ CHIP_TAROSUKE_084 ] = CHIP_POS(  5, 12 );
	_chip_pos[ CHIP_TAROSUKE_085 ] = CHIP_POS(  6, 12 );
	_chip_pos[ CHIP_TAROSUKE_086 ] = CHIP_POS(  7, 12 );
	_chip_pos[ CHIP_TAROSUKE_087 ] = CHIP_POS(  0, 13 );
	_chip_pos[ CHIP_TAROSUKE_088 ] = CHIP_POS(  1, 13 );
	_chip_pos[ CHIP_TAROSUKE_089 ] = CHIP_POS(  2, 13 );
	_chip_pos[ CHIP_TAROSUKE_090 ] = CHIP_POS(  3, 13 );
	_chip_pos[ CHIP_TAROSUKE_091 ] = CHIP_POS(  4, 13 );
	_chip_pos[ CHIP_TAROSUKE_092 ] = CHIP_POS(  5, 13 );
	_chip_pos[ CHIP_TAROSUKE_093 ] = CHIP_POS(  6, 13 );
	_chip_pos[ CHIP_TAROSUKE_094 ] = CHIP_POS(  7, 13 );
	_chip_pos[ CHIP_TAROSUKE_095 ] = CHIP_POS(  8, 13 );
	_chip_pos[ CHIP_TAROSUKE_096 ] = CHIP_POS(  9, 13 );
	_chip_pos[ CHIP_TAROSUKE_097 ] = CHIP_POS(  0, 14 );
	_chip_pos[ CHIP_TAROSUKE_098 ] = CHIP_POS(  1, 14 );
	_chip_pos[ CHIP_TAROSUKE_099 ] = CHIP_POS(  2, 14 );
	_chip_pos[ CHIP_TAROSUKE_100 ] = CHIP_POS(  3, 14 );
	_chip_pos[ CHIP_TAROSUKE_101 ] = CHIP_POS(  4, 14 );

	_chip_pos[ CHIP_MOMOTARO_1 ] = CHIP_POS( 0, 7 );
	_chip_pos[ CHIP_MOMOTARO_2 ] = CHIP_POS( 1, 7 );
	_chip_pos[ CHIP_MOMOTARO_3 ] = CHIP_POS( 2, 7 );
	_chip_pos[ CHIP_MOMOTARO_4 ] = CHIP_POS( 3, 7 );
	_chip_pos[ CHIP_MOMOTARO_5 ] = CHIP_POS( 4, 7 );
	_chip_pos[ CHIP_MOMOTARO_6 ] = CHIP_POS( 5, 7 );
	_chip_pos[ CHIP_MOMOTARO_7 ] = CHIP_POS( 6, 7 );
}


ChipDrawer::~ChipDrawer( ) {
}

void ChipDrawer::draw( CHIP chip, int sx, int sy, bool reverse ) {
	DrawerPtr drawer = Drawer::getTask( );

	int tx = _chip_pos[ chip ].cx * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠx
	int ty = _chip_pos[ chip ].cy * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠy

	int sx2 = sx + CHIP_SIZE;
	int sy2 = sy + CHIP_SIZE;

	
	if ( reverse ) {
		int tmp = sx;
		sx = sx2;
		sx2 = tmp;
	}

	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
	Drawer::Sprite sprite( trans, GRAPH_CHARACTER, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );

}