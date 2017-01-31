#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"
#include "Camera.h"
#include "mathmatics.h"
#include "PsychicMgr.h"
#include "PsychicMomotaro.h"
#include "Sound.h"
#include "Power.h"
#include "Game.h"

static const int MOVE_SPEED = 20;
static const int CHIP_MOMOTARO_NUM = 101;
static const int START_X = -100;
static const int START_Y = -100;
static const int SHOOT_SPEED = 10;
static const int COOL_TIME = 3;
static const int WAIT_PATTERN_TIME = 3;
static const int CHIP_SIZE = 128;
static const int FALTER_COUNT = 30;

Momotaro::Momotaro( PsychicMgrPtr mgr, PowerPtr power ) :
Character( START_X, START_Y, CHIP_SIZE, CHIP_SIZE / 2, false ),
_psychic_mgr( mgr ),
_power( power ) {
	_shoot_x = SHOOT_SPEED;
	_shoot_y = 0;
	_cool = 0;
	_device_num = DEVICE_2;
	_action = ACTION_MOVE;
	_act_count = 0;
	_falter_count = 0;

	_device_num = DEVICE_2;
	GamePtr game = Game::getTask( );
	if ( game->isSolo( ) ) {
		_device_num = DEVICE_1;
		hide( );
	}
}

Momotaro::~Momotaro( ) {
}

void Momotaro::hide( ) {
	_action = ACTION_HIDE;
	_act_count = 0;
}

void Momotaro::adjust( CameraConstPtr camera ) {
	if ( _action == ACTION_HIDE ) {
		return;
	}

	if ( getX( ) < camera->getX( ) + CHIP_SIZE / 2 ) {
		setAccelX( 0 );
		setX( camera->getX( ) + CHIP_SIZE / 2 );
	}
	if ( getX( ) > camera->getX( ) + SCREEN_WIDTH - CHIP_SIZE / 2 ) {
		setAccelX( 0 );
		setX( camera->getX( ) + SCREEN_WIDTH - CHIP_SIZE / 2 );
	}
	if ( getY( ) < CHIP_SIZE / 2 ) {
		setAccelY( 0 );
		setY( CHIP_SIZE / 2 );
	}
	if ( getY( ) > BG_SIZE - CHIP_SIZE / 2) {
		setAccelY( 0 );
		setY( BG_SIZE - CHIP_SIZE / 2 );
	}
}

void Momotaro::appear( int x, int y, bool reverse ) {
	_action = ACTION_MOVE;
	_falter_count = FALTER_COUNT;
	setX( x );
	setY( y );
	setChipReverse( reverse );
	_vec = Vector( -MOVE_SPEED, -MOVE_SPEED / 2 );
	if ( reverse ) {
		_vec = Vector( MOVE_SPEED, -MOVE_SPEED / 2 );
	}
}

void Momotaro::act( ) {
	_act_count++;

	switch ( _action ) {
	case ACTION_MOVE:
		actOnMove( );
		break;
	case ACTION_HIDE:
		actOnHide( );
		break;
	};
}

void Momotaro::actOnHide( ) {
	double length = _vec.getLength( );
	_vec = _vec.normalize( ) * ( length * 0.9 );
	setAccelX( ( int )_vec.x );
	setAccelY( ( int )_vec.y );
	int idx = 8 - _act_count;
	if ( idx < 0 ) {
		idx = 8;
		setX( START_X );
	}
	setChipGraph( GRAPH_CHARACTER_2, idx % 8, 6 + idx / 8 );
}

void Momotaro::actOnMove( ) {
	DevicePtr device = Device::getTask( );
	SoundPtr sound = Sound::getTask( );
	
	Vector vec( device->getDirX( _device_num ), device->getDirY( _device_num ) );
	
	if ( vec.isOrijin( ) || device->getButton( ) == BUTTON_A ) {
		double length = _vec.getLength( );
		_vec = _vec.normalize( ) * ( length * 0.8 );
		setAccelX( ( int )_vec.x );
		setAccelY( ( int )_vec.y );
	}
	

	_falter_count --;
	if ( _falter_count < 0 ) {
		_falter_count = 0;
	}

	if ( _falter_count % 2 == 0 ) {
		setChipGraph( GRAPH_CHARACTER_2, _act_count / WAIT_PATTERN_TIME % 3 + 3, 5 );
	} else {
		setChipGraph( GRAPH_CHARACTER_2, 7, 7 );
	}

	_cool--;
	if ( device->getButton( _device_num ) == BUTTON_A ) {
		sound->playSE( "yokai_se_27.wav" );
		if ( _cool < 0 ) {
			PsychicPtr psychic( new PsychicMomotaro( getX( ), getY( ), isChipReverse( ) ) ); 
			_psychic_mgr->shoot( psychic );
			_cool = COOL_TIME;
		}
		return;
	}

	if ( !vec.isOrijin( ) ) {
		_vec = ( _vec + vec).normalize( ) * MOVE_SPEED;
		setAccelX( ( int )_vec.x );
		setAccelY( ( int )_vec.y );
	}

	if ( !vec.isOrijin( ) ) {
		vec = vec.normalize( ) * SHOOT_SPEED;
		_shoot_x = ( int )vec.x;
		_shoot_y = ( int )vec.y;
	}
}

void Momotaro::damage( int pow ) {
	if ( _action != ACTION_MOVE || _falter_count > 0 ) {
		return;
	}

	_falter_count = FALTER_COUNT;
	_power->decrease( pow );
}
