#include "Tarosuke.h"
#include "Device.h"
#include "define.h"
#include "PsychicMgr.h"

static const int MAX_TAROSUKE_CHIP_NUM = 101;
static const int JUMP_COUNT = 3;
static const int JUMP_POWER = 18;
static const int START_X = 400;
static const int START_Y = 200;
static const int JUNP_PATTERN  = 2;
static const int WALK_PATTERN = 8;
static const int WAIT_TIME = 30;
static const int CHIP_SIZE = 34 * 6;
static const int CHIP_FOOT = 25;

Tarosuke::Tarosuke( PsychicMgrPtr psychic ) : 
Character( START_X, START_Y, GRAPH_CHARACTER, CHIP_SIZE, CHIP_FOOT ) {
	_psychic_mgr = psychic;
}

Tarosuke::~Tarosuke( ) {

}

void Tarosuke::act( ) {
	switch ( _action ) {
	case ACTION_STAND:
		actOnStanding( );
		break;
	case ACTION_JUMP:
		actOnJumping( );
		break;
	case ACTION_FLOAT:
		actOnFloating( );
		break;
	case ACTION_SAVE:
		actOnSaving( );
		break;
	}
	
	updateChip( );
}

void Tarosuke::actOnStanding( ) {
	
	DevicePtr device = Device::getTask( );

	if ( !isStanding( ) ) {
		_action = ACTION_FLOAT;
		return;
	}
	
	if ( device->getDirY( ) > 50 && abs( device->getDirX( ) ) < 10 ) {
		_action = ACTION_SAVE;
		return;
	}
	
	_action = ACTION_STAND;
	
	setAccelX( device->getDirX( DEVICE_1 ) / 10 );

	if ( device->getPush( DEVICE_1 ) == BUTTON_C ) {
		_action = ACTION_JUMP;
		setAccelY( -JUMP_POWER );
	}

	if ( device->getPush( ) == BUTTON_A  ) {
		_action = ACTION_JUMP;
		_psychic_mgr->shooting( getX( ), getY( ), true );
	}
}

void Tarosuke::actOnJumping( ) {
	_action = ACTION_FLOAT;
}

void Tarosuke::actOnFloating( ) {
	if ( isStanding( ) ) {
		_action = ACTION_STAND;
		return;
	}
}

void Tarosuke::actOnSaving( ) {
	DevicePtr device = Device::getTask( );
	if ( device->getDirY( ) < 50 ) {
		_action = ACTION_STAND;
	}
}

void Tarosuke::updateChip( ) {
	switch ( _action ) {
	case ACTION_STAND:
		if ( getAccelX( ) == 0 ) {
			setChipUV( 0, 0 );
		} else {
			const int WALK[ WALK_PATTERN ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
			setChipUV( WALK[ ( getX( ) / WAIT_TIME ) % WALK_PATTERN ], 0 );
		}
		break;
	case ACTION_JUMP:
	case ACTION_FLOAT:
		setChipUV( 5, 0 );
		break;
	}
}
