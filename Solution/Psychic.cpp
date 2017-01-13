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
	std::array< CHIP_POS, MAX_PSYCHIC > chip_pos;
	chip_pos[ PSYCHIC_BLUE ] = CHIP_POS( 1, 2 );
	chip_pos[ PSYCHIC_YELLOW ] = CHIP_POS( 0, 2 );
	int x2 = x + CHIP_SIZE;
	int y2 = y + CHIP_SIZE;

	if ( right ) {
		int tmp = x;
		x = x2;
		x2 = tmp;
	}

	for ( int i = 0; i < MAX_PSYCHIC; i++ ) {
		int tx = chip_pos[ i ].cx * CHIP_SIZE;
		int ty = chip_pos[ i ].cy * CHIP_SIZE;
	
		Drawer::Transform trans( x, y, tx, ty, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_EFFECT_0 );
		drawer->setSprite( sprite );
	}
}