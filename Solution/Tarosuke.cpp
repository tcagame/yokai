#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Keyboard.h"

static const int JUMP_COUNT = 3;
static const int JUMP_POWER = 20;


Tarosuke::Tarosuke( int x, int y ) : 
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_TAROSUKE_001 );
}

Tarosuke::~Tarosuke( ) {

}

void Tarosuke::debugChip( ) {
	const int MAX_TAROSUKE_CHIP_NUM = 101;
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "Q" ) ) {
		setChip( ChipDrawer::CHIP( ( getChip( ) + 1 ) % ( MAX_TAROSUKE_CHIP_NUM - 1 ) ) ); 
	}

}

void Tarosuke::updateAccel( ) {
	setAccelX( 0 );
	manipulate( );
	//fall( );
}

void Tarosuke::updateChip( ) {
	const int WALK_PATTERN = 4;
	const int WAIT_TIME = 4;
	switch ( _action ) {
	case ACTION_WAIT:
		setChip( ChipDrawer::CHIP::CHIP_TAROSUKE_001 );
		break;
	case ACTION_WALK:
		setChip( ChipDrawer::CHIP( ChipDrawer::CHIP_TAROSUKE_002 +
				( getX( ) / WAIT_TIME ) % WALK_PATTERN ) );
		break;
	default:
		break;
	}
}

void Tarosuke::manipulate( ) {
	_action = ACTION_WAIT;
	const int MOVE_SPEED = 10;
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_action = ACTION_WALK;
		setAccelX( -MOVE_SPEED );
		setDir( DIR_LEFT );
	}
	if ( keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_action = ACTION_WALK;
		setAccelX( MOVE_SPEED );
		setDir( DIR_RIGHT );
	}
	if (keyboard->isPushKey( "SPACE" ) ) {
		_action = ACTION_JUMP;
		setAccelY( -JUMP_POWER );

	}
}
