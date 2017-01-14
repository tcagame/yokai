#include "Psychic.h"
#include "define.h"
#include "Drawer.h"
#include "Camera.h"

Psychic::Psychic( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_EFFECT_0, "Yokai_OBJ_effect0.png" );

	_chip_pos[ STATE_CHARGE ][ PSYCHIC_BLUE ] = CHIP_POS( 7, 2 );
	_chip_pos[ STATE_CHARGE ][ PSYCHIC_YELLOW ] = CHIP_POS( 6, 2 );
	_chip_pos[ STATE_RELEASE ][ PSYCHIC_BLUE ] = CHIP_POS( 7, 3 );
	_chip_pos[ STATE_RELEASE ][ PSYCHIC_YELLOW ] = CHIP_POS( 6, 3 );

	_state = STATE_WAIT;
}

Psychic::~Psychic( ) {
}

void Psychic::update( ) {
	switch ( _state ) {
	case STATE_WAIT:
		break;
	case STATE_CHARGE:
		_state = STATE_RELEASE;
		break;
	case STATE_RELEASE:
		move( );
		break;
	}
}

void Psychic::move( ) {
	const int move_speed = 30;

	if ( _right ) {
		_x += move_speed;
	} else {
		_x += -move_speed;
	}
}

void Psychic::draw( CameraConstPtr camera ) {
	DrawerPtr drawer = Drawer::getTask( );
	int x1 = _x - camera->getX( ) - CHIP_SIZE / 2;
	int y1 = _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK;
	int x2 = x1 + CHIP_SIZE;
	int y2 = y1 + CHIP_SIZE;

	if ( _right ) {
		int tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	for ( int i = 0; i < MAX_PSYCHIC; i++ ) {
		int tx = _chip_pos[ _state ][ i ].cx * CHIP_SIZE;
		int ty = _chip_pos[ _state ][ i ].cy * CHIP_SIZE;
		Drawer::Transform trans( x1, y1, tx, ty, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_EFFECT_0 );
		drawer->setSprite( sprite );
	}
}

void Psychic::shooting( int x, int y, bool right ) {
	_x = x;
	_y = y;
	_right = right;
	_state = STATE_CHARGE;
}