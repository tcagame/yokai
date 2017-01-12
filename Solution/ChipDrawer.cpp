#include "ChipDrawer.h"
#include "Drawer.h"

ChipDrawer::ChipDrawer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( 0, "Yokai_OBJ_myCharacter.png" );
	_chip_pos[ CHIP_TAROSUKE_001 ] = ChipPos(  0,  0 );
	_chip_pos[ CHIP_TAROSUKE_002 ] = ChipPos(  1,  0 );
	_chip_pos[ CHIP_TAROSUKE_003 ] = ChipPos(  2,  0 );
	_chip_pos[ CHIP_TAROSUKE_004 ] = ChipPos(  3,  0 );
	_chip_pos[ CHIP_TAROSUKE_005 ] = ChipPos(  4,  0 );
	_chip_pos[ CHIP_TAROSUKE_006 ] = ChipPos(  5,  0 );
	_chip_pos[ CHIP_TAROSUKE_007 ] = ChipPos(  6,  0 );
	_chip_pos[ CHIP_TAROSUKE_008 ] = ChipPos(  0,  1 );
	_chip_pos[ CHIP_TAROSUKE_009 ] = ChipPos(  1,  1 );
	_chip_pos[ CHIP_TAROSUKE_010 ] = ChipPos(  2,  1 );
	_chip_pos[ CHIP_TAROSUKE_011 ] = ChipPos(  3,  1 );
	_chip_pos[ CHIP_TAROSUKE_012 ] = ChipPos(  4,  1 );
	_chip_pos[ CHIP_TAROSUKE_013 ] = ChipPos(  5,  1 );
	_chip_pos[ CHIP_TAROSUKE_014 ] = ChipPos(  6,  1 );
	_chip_pos[ CHIP_TAROSUKE_015 ] = ChipPos(  7,  1 );
	_chip_pos[ CHIP_TAROSUKE_016 ] = ChipPos(  8,  1 );
	_chip_pos[ CHIP_TAROSUKE_017 ] = ChipPos(  9,  1 );
	_chip_pos[ CHIP_TAROSUKE_018 ] = ChipPos(  0,  1 );
	_chip_pos[ CHIP_TAROSUKE_019 ] = ChipPos(  1,  2 );
	_chip_pos[ CHIP_TAROSUKE_020 ] = ChipPos(  2,  2 );
	_chip_pos[ CHIP_TAROSUKE_021 ] = ChipPos(  3,  2 );
	_chip_pos[ CHIP_TAROSUKE_022 ] = ChipPos(  4,  2 );
	_chip_pos[ CHIP_TAROSUKE_023 ] = ChipPos(  5,  2 );
	_chip_pos[ CHIP_TAROSUKE_024 ] = ChipPos(  6,  2 );
	_chip_pos[ CHIP_TAROSUKE_025 ] = ChipPos(  7,  2 );
	_chip_pos[ CHIP_TAROSUKE_026 ] = ChipPos(  8,  2 );
	_chip_pos[ CHIP_TAROSUKE_027 ] = ChipPos(  9,  2 );
	_chip_pos[ CHIP_TAROSUKE_028 ] = ChipPos( 10,  2 );
	_chip_pos[ CHIP_TAROSUKE_029 ] = ChipPos( 11,  2 );
	_chip_pos[ CHIP_TAROSUKE_030 ] = ChipPos(  0,  3 );
	_chip_pos[ CHIP_TAROSUKE_031 ] = ChipPos(  1,  3 );
	_chip_pos[ CHIP_TAROSUKE_032 ] = ChipPos(  2,  3 );
	_chip_pos[ CHIP_TAROSUKE_033 ] = ChipPos(  3,  3 );
	_chip_pos[ CHIP_TAROSUKE_034 ] = ChipPos(  4,  3 );
	_chip_pos[ CHIP_TAROSUKE_035 ] = ChipPos(  5,  3 );
	_chip_pos[ CHIP_TAROSUKE_036 ] = ChipPos(  0,  4 );
	_chip_pos[ CHIP_TAROSUKE_037 ] = ChipPos(  1,  4 );
	_chip_pos[ CHIP_TAROSUKE_038 ] = ChipPos(  2,  4 );
	_chip_pos[ CHIP_TAROSUKE_039 ] = ChipPos(  3,  4 );
	_chip_pos[ CHIP_TAROSUKE_040 ] = ChipPos(  4,  4 );
	_chip_pos[ CHIP_TAROSUKE_041 ] = ChipPos(  5,  4 );
	_chip_pos[ CHIP_TAROSUKE_042 ] = ChipPos(  6,  4 );
	_chip_pos[ CHIP_TAROSUKE_043 ] = ChipPos(  7,  4 );
	_chip_pos[ CHIP_TAROSUKE_044 ] = ChipPos(  8,  4 );
	_chip_pos[ CHIP_TAROSUKE_045 ] = ChipPos(  9,  4 );
	_chip_pos[ CHIP_TAROSUKE_046 ] = ChipPos(  0,  5 );
	_chip_pos[ CHIP_TAROSUKE_047 ] = ChipPos(  1,  5 );
	_chip_pos[ CHIP_TAROSUKE_048 ] = ChipPos(  2,  5 );
	_chip_pos[ CHIP_TAROSUKE_049 ] = ChipPos(  3,  5 );
	_chip_pos[ CHIP_TAROSUKE_050 ] = ChipPos(  4,  5 );
	_chip_pos[ CHIP_TAROSUKE_051 ] = ChipPos(  5,  5 );
	_chip_pos[ CHIP_TAROSUKE_052 ] = ChipPos(  6,  5 );
	_chip_pos[ CHIP_TAROSUKE_053 ] = ChipPos(  7,  5 );
	_chip_pos[ CHIP_TAROSUKE_054 ] = ChipPos(  8,  5 );
	_chip_pos[ CHIP_TAROSUKE_055 ] = ChipPos(  0,  6 );
	_chip_pos[ CHIP_TAROSUKE_056 ] = ChipPos(  1,  6 );
	_chip_pos[ CHIP_TAROSUKE_057 ] = ChipPos(  2,  6 );
	_chip_pos[ CHIP_TAROSUKE_058 ] = ChipPos(  3,  6 );
	_chip_pos[ CHIP_TAROSUKE_059 ] = ChipPos(  4,  6 );
	_chip_pos[ CHIP_TAROSUKE_060 ] = ChipPos(  5,  6 );
	_chip_pos[ CHIP_TAROSUKE_061 ] = ChipPos(  6,  6 );
	_chip_pos[ CHIP_TAROSUKE_062 ] = ChipPos(  0, 10 );
	_chip_pos[ CHIP_TAROSUKE_063 ] = ChipPos(  1, 10 );
	_chip_pos[ CHIP_TAROSUKE_064 ] = ChipPos(  2, 10 );
	_chip_pos[ CHIP_TAROSUKE_065 ] = ChipPos(  3, 10 );
	_chip_pos[ CHIP_TAROSUKE_066 ] = ChipPos(  4, 10 );
	_chip_pos[ CHIP_TAROSUKE_067 ] = ChipPos(  5, 10 );
	_chip_pos[ CHIP_TAROSUKE_068 ] = ChipPos(  6, 10 );
	_chip_pos[ CHIP_TAROSUKE_069 ] = ChipPos(  7, 10 );
	_chip_pos[ CHIP_TAROSUKE_070 ] = ChipPos(  8, 10 );
	_chip_pos[ CHIP_TAROSUKE_071 ] = ChipPos(  0, 11 );
	_chip_pos[ CHIP_TAROSUKE_072 ] = ChipPos(  1, 11 );
	_chip_pos[ CHIP_TAROSUKE_073 ] = ChipPos(  2, 11 );
	_chip_pos[ CHIP_TAROSUKE_074 ] = ChipPos(  3, 11 );
	_chip_pos[ CHIP_TAROSUKE_075 ] = ChipPos(  4, 11 );
	_chip_pos[ CHIP_TAROSUKE_076 ] = ChipPos(  5, 11 );
	_chip_pos[ CHIP_TAROSUKE_077 ] = ChipPos(  6, 11 );
	_chip_pos[ CHIP_TAROSUKE_078 ] = ChipPos(  7, 11 );
	_chip_pos[ CHIP_TAROSUKE_079 ] = ChipPos(  0, 12 );
	_chip_pos[ CHIP_TAROSUKE_080 ] = ChipPos(  1, 12 );
	_chip_pos[ CHIP_TAROSUKE_081 ] = ChipPos(  2, 12 );
	_chip_pos[ CHIP_TAROSUKE_082 ] = ChipPos(  3, 12 );
	_chip_pos[ CHIP_TAROSUKE_083 ] = ChipPos(  4, 12 );
	_chip_pos[ CHIP_TAROSUKE_084 ] = ChipPos(  5, 12 );
	_chip_pos[ CHIP_TAROSUKE_085 ] = ChipPos(  6, 12 );
	_chip_pos[ CHIP_TAROSUKE_086 ] = ChipPos(  7, 12 );
	_chip_pos[ CHIP_TAROSUKE_087 ] = ChipPos(  0, 13 );
	_chip_pos[ CHIP_TAROSUKE_088 ] = ChipPos(  1, 13 );
	_chip_pos[ CHIP_TAROSUKE_089 ] = ChipPos(  2, 13 );
	_chip_pos[ CHIP_TAROSUKE_090 ] = ChipPos(  3, 13 );
	_chip_pos[ CHIP_TAROSUKE_091 ] = ChipPos(  4, 13 );
	_chip_pos[ CHIP_TAROSUKE_092 ] = ChipPos(  5, 13 );
	_chip_pos[ CHIP_TAROSUKE_093 ] = ChipPos(  6, 13 );
	_chip_pos[ CHIP_TAROSUKE_094 ] = ChipPos(  7, 13 );
	_chip_pos[ CHIP_TAROSUKE_095 ] = ChipPos(  8, 13 );
	_chip_pos[ CHIP_TAROSUKE_096 ] = ChipPos(  9, 13 );
	_chip_pos[ CHIP_TAROSUKE_097 ] = ChipPos(  0, 14 );
	_chip_pos[ CHIP_TAROSUKE_098 ] = ChipPos(  1, 14 );
	_chip_pos[ CHIP_TAROSUKE_099 ] = ChipPos(  2, 14 );
	_chip_pos[ CHIP_TAROSUKE_100 ] = ChipPos(  3, 14 );
	_chip_pos[ CHIP_TAROSUKE_101 ] = ChipPos(  4, 14 );

	_chip_pos[ CHIP_MOMOTARO_1 ] = ChipPos( 0, 7 );
	_chip_pos[ CHIP_MOMOTARO_2 ] = ChipPos( 1, 7 );
	_chip_pos[ CHIP_MOMOTARO_3 ] = ChipPos( 2, 7 );
	_chip_pos[ CHIP_MOMOTARO_4 ] = ChipPos( 3, 7 );
	_chip_pos[ CHIP_MOMOTARO_5 ] = ChipPos( 4, 7 );
	_chip_pos[ CHIP_MOMOTARO_6 ] = ChipPos( 5, 7 );
	_chip_pos[ CHIP_MOMOTARO_7 ] = ChipPos( 6, 7 );
}


ChipDrawer::~ChipDrawer( ) {
}

void ChipDrawer::draw( CHIP chip, int sx, int sy ) {
	DrawerPtr drawer = Drawer::getTask( );
	const int CHIP_SIZE = 272;

	int tx = _chip_pos[ chip ].cx * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠx
	int ty = _chip_pos[ chip ].cy * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠy

	int sx2 = sx + CHIP_SIZE;
	int sy2 = sy + CHIP_SIZE;


	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
	Drawer::Sprite sprite( trans, 0, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );

}