#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Keyboard.h"
#include "Device.h"
#include "define.h"

static const int JUMP_COUNT = 3;
static const int JUMP_POWER = 20;

Tarosuke::Tarosuke( int x, int y, PsychicMgrPtr psychic ) : 
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_TAROSUKE_001 );
	_psychic_mgr = psychic;
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
	manipulate( );
	//fall( );
}


void Tarosuke::updateChip( ) {
	const int JUNP_PATTERN  = 2;
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
	case ACTION_JUMP:
		
		setChip( ChipDrawer::CHIP( ChipDrawer::CHIP_TAROSUKE_006 ) );
		
	default:
		break;
	}
}

void Tarosuke::manipulate( ) {

	_action = ACTION_WAIT;
	DevicePtr device = Device::getTask( );
	int accel_x = device->getDirX( DEVICE_1 ) / CHARA_MOVE_RATIO; 
	setAccelX( accel_x );

	if ( accel_x != 0 ) {
		_action = ACTION_WALK;
	}
	setAccelX( accel_x );
	if ( device->getButton( ) == BUTTON_C  ) {
		_action = ACTION_JUMP;
		setAccelY( -JUMP_POWER );
	}
	if ( device->getButton( ) == BUTTON_A  ) {
		_action = ACTION_JUMP;
		bool right = false;
		if ( getDir( ) == DIR_RIGHT ) {
			right = true;
		}
		_psychic_mgr->shooting( getX( ), getY( ), right );
	}
}

void Tarosuke::adjustX( ) {
	if ( getX( ) < 0 ) {
		setX( 0 );
	}
}
void Tarosuke::adjustY( ) {
	if ( getY( ) < 0 ) {
		setY( 0 );
	}
}

