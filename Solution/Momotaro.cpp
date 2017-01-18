#include "Momotaro.h"
#include "Keyboard.h"
#include "device.h"
#include "define.h"
#include "Camera.h"
#include "mathmatics.h"
#include "PsychicMgr.h"
#include "PsychicMomotaro.h"

static const int MOVE_SPEED = 20;
static const int MAX_CHIP_PATTERN = 7;
static const int CHIP_MOMOTARO_NUM = 101;
static const int START_X = 360;
static const int START_Y = 360;
static const int CHIP_SIZE = 34 * 6;
static const int CHIP_FOOT = CHIP_SIZE / 2;
static const int SHOOT_SPEED = 10;
static const int COOL_TIME = 5;

Momotaro::Momotaro( CameraConstPtr camera, PsychicMgrPtr mgr ) :
Character( START_X, START_Y, GRAPH_CHARACTER, CHIP_SIZE, CHIP_FOOT, false ),
_camera( camera ),
_psychic_mgr( mgr ) {
	_shoot_x = SHOOT_SPEED;
	_shoot_y = 0;
	_cool = 0;
}

Momotaro::~Momotaro( ) {
}

void Momotaro::act( ) {
	DevicePtr device = Device::getTask( );
	
	Vector vec( device->getDirX( ), device->getDirY( ) );
	
	if ( vec.isOrijin( ) || device->getButton( ) == BUTTON_A ) {
		double length = _vec.getLength( );
		_vec = _vec.normalize( ) * ( length * 0.9 );
		setAccelX( ( int )_vec.x );
		setAccelY( ( int )_vec.y );
	}

	_cool--;
	if ( device->getButton( ) == BUTTON_A ) {
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

	if ( getX( ) + getAccelX( ) < _camera->getX( ) ) {
		setAccelX( 0 );
	}
	if ( getX( ) + getAccelX( ) > _camera->getX( ) + SCREEN_WIDTH ) {
		setAccelX( 0 );
	}
	if ( getY( ) + getAccelY( ) < _camera->getY( ) ) {
		setAccelY( 0 );
	}
	if ( getY( ) + getAccelY( ) > _camera->getY( ) + SCREEN_HEIGHT ) {
		setAccelY( 0 );
	}

	if ( !vec.isOrijin( ) ) {
		vec = vec.normalize( ) * SHOOT_SPEED;
		_shoot_x = ( int )vec.x;
		_shoot_y = ( int )vec.y;
	}

	setChipUV( 6, 7 );
}
