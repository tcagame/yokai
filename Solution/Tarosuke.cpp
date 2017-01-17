#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Keyboard.h"
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
	manipulate( );
	updateChip( );
}

void Tarosuke::manipulate( ) {
	_action = ACTION_WAIT;
	DevicePtr device = Device::getTask( );
	int accel_x = device->getDirX( DEVICE_1 ) / CHARA_MOVE_RATIO; 
	setAccelX( accel_x );

	if ( accel_x != 0 ) {
		_action = ACTION_WALK;
	}

	if ( isStanding( ) ) {
		if ( device->getPush( ) == BUTTON_C  ) {
			_action = ACTION_JUMP;
			setAccelY( -JUMP_POWER );
		}
	}
	if ( !isStanding( ) ) {
		_action = ACTION_FLOAT;
	}
	if ( device->getPush( ) == BUTTON_A  ) {
		_action = ACTION_JUMP;
		_psychic_mgr->shooting( getX( ), getY( ), true );
	}
}

void Tarosuke::updateChip( ) {
	const int WALK[ WALK_PATTERN ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
	switch ( _action ) {
	case ACTION_WAIT:
		setChipUV( 0, 0 );
		break;
	case ACTION_WALK:
		setChipUV( WALK[ ( getX( ) / WAIT_TIME ) % WALK_PATTERN ], 0 );
		break;
	case ACTION_FLOAT:
		setChipUV( 5, 0 );
		break;
	}
}
