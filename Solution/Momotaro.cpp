#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"
#include "Camera.h"
#include "mathmatics.h"
#include "PsychicMgr.h"
#include "PsychicMomotaro.h"

static const int MOVE_SPEED = 20;
static const int CHIP_MOMOTARO_NUM = 101;
static const int START_X = -100;
static const int START_Y = -100;
static const int SHOOT_SPEED = 10;
static const int COOL_TIME = 5;
static const int WAIT_PATTERN_TIME = 3;
static const int CHIP_SIZE = 128;

Momotaro::Momotaro( CameraConstPtr camera, PsychicMgrPtr mgr ) :
Character( START_X, START_Y, GRAPH_CHARACTER_2, CHIP_SIZE, CHIP_SIZE / 2, false ),
_camera( camera ),
_psychic_mgr( mgr ) {
	_shoot_x = SHOOT_SPEED;
	_shoot_y = 0;
	_cool = 0;
	_device_num = DEVICE_2;
	_action = ACTION_MOVE;
	_act_count = 0;
}

Momotaro::~Momotaro( ) {
}

void Momotaro::hide( ) {
	_act_count = 0;
	_device_num = DEVICE_1;
	_action = ACTION_HIDE;
}

void Momotaro::appear( int x, int y, bool reverse ) {
	_device_num = DEVICE_1;
	setX( x );
	setY( y );
	_action = ACTION_MOVE;
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
	setChipUV( idx % 8, 6 + idx / 8 );
}

void Momotaro::actOnMove( ) {
	DevicePtr device = Device::getTask( );
	
	Vector vec( device->getDirX( _device_num ), device->getDirY( _device_num ) );
	
	if ( vec.isOrijin( ) || device->getButton( ) == BUTTON_A ) {
		double length = _vec.getLength( );
		_vec = _vec.normalize( ) * ( length * 0.9 );
		setAccelX( ( int )_vec.x );
		setAccelY( ( int )_vec.y );
	}

	_cool--;
	if ( device->getButton( _device_num ) == BUTTON_A ) {
		if ( _cool < 0 ) {
			PsychicPtr psychic( new PsychicMomotaro( getX( ), getY( ), _shoot_x, _shoot_y ) ); 
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

	if ( getX( ) < _camera->getX( ) ) {
		setAccelX( 0 );
		setX( _camera->getX( ) );
	}
	if ( getX( ) > _camera->getX( ) + SCREEN_WIDTH ) {
		setAccelX( 0 );
		setX( _camera->getX( ) + SCREEN_WIDTH );
	}
	if ( getY( ) < _camera->getY( ) ) {
		setAccelY( 0 );
		setY( _camera->getY( ) );
	}
	if ( getY( ) > _camera->getY( ) + SCREEN_HEIGHT ) {
		setAccelY( 0 );
		setY( _camera->getY( ) + SCREEN_HEIGHT );
	}

	if ( !vec.isOrijin( ) ) {
		vec = vec.normalize( ) * SHOOT_SPEED;
		_shoot_x = ( int )vec.x;
		_shoot_y = ( int )vec.y;
	}

	setChipUV( _act_count / WAIT_PATTERN_TIME % 3 + 3, 5 );
}
