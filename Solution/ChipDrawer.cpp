#include "ChipDrawer.h"
#include "Drawer.h"

ChipDrawer::ChipDrawer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( 0, "Yokai_OBJ_myCharacter.png" );

	_chip_pos[ CHIP_TAROSUKE ] = ChipPos( 0, 0 );
	_chip_pos[ CHIP_MOMOTARO ] = ChipPos( 6, 7 );
}


ChipDrawer::~ChipDrawer( ) {
}

void ChipDrawer::draw( CHIP chip, int sx, int sy ) {
	DrawerPtr drawer = Drawer::getTask( );
	const int CHIP_SIZE = 34;

	int tx = _chip_pos[ chip ].cx * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠx
	int ty = _chip_pos[ chip ].cy * CHIP_SIZE;//‰æ‘œ“à‚ÌêŠy

	int sx2 = sx + CHIP_SIZE;
	int sy2 = sy + CHIP_SIZE;

	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
	Drawer::Sprite sprite( trans, 0, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );

}