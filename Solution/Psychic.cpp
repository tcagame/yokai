#include "Psychic.h"
#include "define.h"
#include "Drawer.h"

Psychic::Psychic( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_EFFECT_0, "Yokai_OBJ_effect0.png" );
}

Psychic::~Psychic( ) {
}

void Psychic::update( ) {
}

void Psychic::draw( int x, int y, bool right ) {
	DrawerPtr drawer = Drawer::getTask( );
	const int CHIP_SIZE = 34;
	int x1 = x;
	int y1 = y;
	int tx = 0 * CHIP_SIZE;
	int ty = 2 * CHIP_SIZE;
	int x2 = x + CHIP_SIZE;
	int y2 = y + CHIP_SIZE;

	if ( right ) {
		x1 = x2;
		x2 = x;
	}

	Drawer::Transform trans( x1, y1, tx, ty, CHIP_SIZE, CHIP_SIZE, x2, y2 );
	Drawer::Sprite sprite( trans, GRAPH_EFFECT_0 );
	drawer->setSprite( sprite );
}