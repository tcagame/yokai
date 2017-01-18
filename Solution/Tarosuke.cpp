#include "Tarosuke.h"
#include "Device.h"
#include "define.h"
#include "PsychicMgr.h"
#include "Camera.h"
#include "Drawer.h"
#include "PsychicTarosuke.h"

static const int MAX_TAROSUKE_CHIP_NUM = 101;
static const int JUMP_COUNT = 10;
static const int JUMP_POWER = 20;
static const int START_X = 400;
static const int START_Y = 200;
static const int JUNP_PATTERN  = 2;
static const int WALK_PATTERN = 8;
static const int WAIT_TIME = 30;
static const int CHIP_SIZE = 34 * 6;
static const int CHIP_FOOT = 25;
static const int MAX_SPEED = 15;
static const int ACCEL_SPEED = 2;
static const int BRAKE_SPEED = 6;
static const int CAPACITY_SAVING_POWER = 40;
static const int SHOOT_FOOT = 80;

Tarosuke::Tarosuke( PsychicMgrPtr psychic ) : 
Character( START_X, START_Y, GRAPH_CHARACTER, CHIP_SIZE, CHIP_FOOT ) {
	_psychic_mgr = psychic;
	_jump_count = 0;
	_action = ACTION_FLOAT;
	_motion_count = 0;
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
	case ACTION_BRAKE:
		actOnBraking( );
		break;
	case ACTION_SHOOT:
		actOnShooting( );
		break;
	case ACTION_BURST:
		actOnBursting( );
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
	
	_action = ACTION_STAND;
	
	bool accel = false;
	bool moving = false;

	if ( device->getDirX( ) > 90 ) {
		moving = true;
		if ( getAccelX( ) < 0 ) {
			_action = ACTION_BRAKE;
		} else if ( getAccelX( ) < MAX_SPEED ) {
			accel = true;
			int ax = getAccelX( ) + ACCEL_SPEED;
			if ( ax > MAX_SPEED ) {
				ax = MAX_SPEED;
			}
			setAccelX( ax );
		}
	}
	
	if ( device->getDirX( ) < -90 ) {
		moving = true;
		if ( getAccelX( ) > 0 ) {
			_action = ACTION_BRAKE;
		} else if ( getAccelX( ) > -MAX_SPEED ) {
			accel = true;
			int ax = getAccelX( ) - ACCEL_SPEED;
			if ( ax < -MAX_SPEED ) {
				ax = -MAX_SPEED;
			}
			setAccelX( ax );
		}
	}


	if ( device->getPush( ) == BUTTON_C ) {
		_jump_count = JUMP_COUNT;
		_action = ACTION_JUMP;
		setAccelY( -JUMP_POWER );
	}
	
	if ( device->getPush( ) == BUTTON_A ) {
		_action = ACTION_SHOOT;
	}

	if ( !accel ) {
		int ax = getAccelX( );

		if ( ax < 0 ) {
			ax += ACCEL_SPEED;
			if ( ax > 0 ) {
				ax = 0;
			}
		}
		
		if ( ax > 0 ) {
			ax += -ACCEL_SPEED;
			if ( ax < 0 ) {
				ax = 0;
			}
		}

		setAccelX( ax );
	}

	if ( !moving ) {
		if ( device->getDirY( ) > 90 && !isInWater( ) ) {
			_saving_power++;
			if ( _saving_power >= CAPACITY_SAVING_POWER ) {
				_action = ACTION_BURST;
			}
		} else {
			_saving_power -= 4;
			if ( _saving_power < 0 ) {
				_saving_power = 0;
			}
		}
	}
}

void Tarosuke::actOnJumping( ) {
	DevicePtr device = Device::getTask( );
	
	_action = ACTION_FLOAT;
	if ( ( device->getButton( ) & BUTTON_C ) == 0 ) {
		return;
	}
	
	_jump_count--;
	if ( _jump_count < 0 ) {
		return;
	}
		
	if ( device->getPush( ) & BUTTON_A ) {
		_action = ACTION_SHOOT;
		return;
	}

	_action = ACTION_JUMP;
	setAccelY( -JUMP_POWER );
}

void Tarosuke::actOnBraking( ) {
	int ax = getAccelX( );
	
	if ( ax < 0 ) {
		ax += BRAKE_SPEED;
		if ( ax > 0 ) {
			ax = 0;
		}
	}
		
	if ( ax > 0 ) {
		ax += -BRAKE_SPEED;
		if ( ax < 0 ) {
			ax = 0;
		}
	}

	setAccelX( ax );

	if ( ax == 0 ) {
		_action = ACTION_STAND;
	}
}

void Tarosuke::actOnFloating( ) {
	DevicePtr device = Device::getTask( );

	if ( isStanding( ) ) {
		_action = ACTION_STAND;
		return;
	}
	
	if ( device->getPush( ) & BUTTON_A ) {
		_action = ACTION_SHOOT;
	}

	int ax = getAccelX( );

	bool push = false;
	if ( device->getDirX( ) > 90 ) {
		if ( MAX_SPEED > ax ) {
			ax += ACCEL_SPEED;
		}
		push = true;
	}
	
	if ( device->getDirX( ) < -90 ) {
		if ( -MAX_SPEED < ax ) {
			ax += -ACCEL_SPEED;
		}
		push = true;
	}

	if ( !push ) {
		if ( ax > 0 ) { 
			ax += -ACCEL_SPEED / 2;
		}

		if ( ax < 0 ) { 
			ax += ACCEL_SPEED / 2;
		}
	}

	setAccelX( ax );
}

void Tarosuke::actOnBursting( ) {
	_saving_power--;
	if ( _saving_power <= 0 ) {
		_saving_power = 0;
		_action = ACTION_STAND;
	}
}

void Tarosuke::actOnShooting( ) {
	_psychic_mgr->shoot( PsychicPtr( new PsychicTarosuke(
		getX( ), getY( ) - SHOOT_FOOT, isChipReverse( ), _saving_power / ( CAPACITY_SAVING_POWER / 4 ) ) ) );
	_saving_power = 0;
	_action = ACTION_STAND;
}

void Tarosuke::updateChip( ) {
	_motion_count++;

	switch ( _action ) {
	case ACTION_STAND:
		if ( !isInWater( ) ) {
			if ( getAccelX( ) == 0 ) {
				if ( _saving_power == 0 ) {
					setChipUV( 0, 0 );
				} else {
					setChipUV( _saving_power / ( CAPACITY_SAVING_POWER / 7 ), 4 );
				}
			} else {
				const int WALK[ WALK_PATTERN ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
				setChipUV( WALK[ ( getX( ) / WAIT_TIME ) % WALK_PATTERN ], 0 );
			}
		} else {
			const int SWIM[ 4 ] = { 0, 1, 2, 1 };
			int idx = 8;
			if ( getAccelX( ) == 0 ) {
				idx = 0;
			}
			setChipUV( SWIM[ ( _motion_count / 4 ) % 4 ] + idx, 2 );
		}
		break;
	case ACTION_JUMP:
	case ACTION_FLOAT:
		setChipUV( 5, 0 );
		break;
	case ACTION_SAVE:
		setChipUV( _saving_power / ( CAPACITY_SAVING_POWER / 7 ), 4 );
		break;
	case ACTION_BURST:
		{
			const int TIRED[ 11 ] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
			setChipUV( 7 + TIRED[ _saving_power / 10 ], 4 );
		}
		break;
	}
}

void Tarosuke::drawOverlapped( CameraConstPtr camera ) const {
	if ( _action == ACTION_BURST || _saving_power == 0 ) {
		return;
	}

	int power = _saving_power / ( CAPACITY_SAVING_POWER / 6 );

	int idx = power * 2 + _motion_count % 2;
	int tx = ( 3 + idx % 4 ) * CHIP_SIZE;
	int ty = (     idx / 4 ) * CHIP_SIZE;

	int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE + CHIP_FOOT;

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, 1.0 );
	drawer->setSprite( sprite );
}

