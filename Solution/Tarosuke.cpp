#include "Tarosuke.h"
#include "Device.h"
#include "define.h"
#include "PsychicMgr.h"
#include "Camera.h"
#include "Drawer.h"
#include "PsychicTarosuke.h"
#include "Momotaro.h"
#include "Sound.h"

static const int MAX_TAROSUKE_CHIP_NUM = 101;
static const int JUMP_COUNT = 10;
static const int JUMP_POWER = 20;
static const int START_X = 400;
static const int START_Y = 200;
static const int JUNP_PATTERN  = 2;
static const int WALK_PATTERN = 8;
static const int WAIT_TIME = 30;
static const int MAX_SPEED = 15;
static const int ACCEL_SPEED = 3;
static const int BRAKE_SPEED = 6;
static const int CAPACITY_SAVING_POWER = 40;
static const int SHOOT_FOOT = 80;
static const int MOMO_SPEED = 10;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 18;

Tarosuke::Tarosuke( PsychicMgrPtr psychic ) : 
Character( START_X, START_Y, GRAPH_CHARACTER_1, CHIP_SIZE, CHIP_FOOT ) {
	_psychic_mgr = psychic;
	_jump_count = 0;
	_action = ACTION_FLOAT;
	_act_count = 0;
	setChipReverse( true );
}

Tarosuke::~Tarosuke( ) {

}

void Tarosuke::setSoloPlay( MomotaroPtr momotaro ) {
	_momotaro = momotaro;
	_momotaro->hide( );
}

void Tarosuke::act( ) {
	_act_count++;

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
	case ACTION_CALL:
		actOnCalling( );
		break;
	case ACTION_APPEAR:
		actOnAppearring( );
		break;
	case ACTION_PRAY:
		actOnPraying( );
		break;
	case ACTION_DEAD:
		actOnDying( );
		break;
	}
	
	updateChip( );

	// デバッグ
	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) == BUTTON_D ) {
		_action = ACTION_DEAD;
		_act_count = 0;
	}
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

	if ( device->getPush( ) == BUTTON_B ) {
		if ( _momotaro ) {
			SoundPtr sound = Sound::getTask( );
			sound->playSE( "yokai_voice_06.wav" );
			_action = ACTION_CALL;
			_act_count = 0;
			_momo_pos = Vector( getX( ), -CHIP_SIZE );
			if ( isChipReverse( ) ) {
				_momo_vec = Vector( -1, -0.1 ).normalize( ) * MOMO_SPEED;
			} else {
				_momo_vec = Vector( 1, -0.1 ).normalize( ) * MOMO_SPEED;
			}
			setAccelX( 0 );
		}
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
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_voice_17.wav" );
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
	
	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_se_20.wav" );
}

void Tarosuke::actOnCalling( ) {
	const int PRAY[ 14 ] = { 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 2, 1 };
	setChipUV( PRAY[ _act_count % 14 ], 1 );

	Vector v = Vector( getX( ), getY( ) - CHIP_SIZE ) - _momo_pos;
	_momo_vec += v.normalize( ) * ( MOMO_SPEED * 0.05 );
	_momo_vec = _momo_vec.normalize( ) * MOMO_SPEED;
	_momo_pos += _momo_vec;

	if ( ( Vector( getX( ), getY( ) ) - _momo_pos ).getLength( ) < CHIP_SIZE / 2 ) {
		_action = ACTION_APPEAR;
		_act_count = 0;
	}
}

void Tarosuke::actOnAppearring( ) {
	int u = 4 + _act_count;
	if ( u > 8 ) {
		u = 8;
	}
	setChipUV( u, 1 );

	if ( _act_count > 14 ) {
		_action = ACTION_PRAY;
		int x = getX( );
		int y = getY( ) - CHIP_SIZE / 2;
		if ( isChipReverse( ) ) {
			x += CHIP_SIZE;
		} else {
			x -= CHIP_SIZE;
		}
		_momotaro->appear( x, y, isChipReverse( ) );
	}
}

void Tarosuke::actOnPraying( ) {
	const int CALL[ 60 ] = {
		0, 1, 0, 1, 0, 1, 0, 1, 2, 3,
		4, 5, 4, 5, 4, 5, 4, 5, 3, 2,
		0, 1, 0, 1, 0, 1, 0, 1, 2, 3,
		4, 5, 4, 5, 4, 5, 4, 5, 3, 2,
		0, 1, 0, 1, 0, 1, 0, 1, 2, 3,
		6, 7, 7, 7, 7, 7, 7, 6, 3, 2,
	};
	setChipUV( CALL[ _act_count / 2 % 60 ], 6 );

	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) == BUTTON_B ) {
		_momotaro->hide( );
		_action = ACTION_STAND;
	}
}

void Tarosuke::actOnDying( ) {
	const int DYING[ 23 ] = {
		0, 1, 2, 3, 5, 4,
		0, 1, 2, 3, 5, 4,
		0, 1, 2, 3, 5, 4,
		0, 1, 6, 7, 9,
	};
	int idx = _act_count / 2;
	if ( idx > 22 ) {
		idx = 22;
	}
	setAccelX( 0 );
	setChipUV( DYING[ idx ] % 8, 3 + idx / 8 );// Character2.png
}

void Tarosuke::updateChip( ) {
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
			int idx = 4;
			if ( getAccelX( ) == 0 ) {
				idx = 0;
			}
			setChipUV( SWIM[ ( _act_count / 4 ) % 4 ] + idx, 3 );
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
			setChipUV( ( 7 + TIRED[ _saving_power / 10 ] ) % 8, 4 + ( 7 + TIRED[ _saving_power / 10 ] ) / 8 );
		}
		break;
	}
}

void Tarosuke::drawOverlapped( CameraConstPtr camera ) const {
	if ( _action == ACTION_CALL ) {
		const int ANIM[ 8 ] = { 0, 0, 0, 0, 0, 1, 2, 1 };

		int idx = ANIM[ _act_count / 2 % 8 ];
		int tx = idx * CHIP_SIZE;
		int ty =   5 * CHIP_SIZE;

		int sx1 = ( int )_momo_pos.x - camera->getX( ) - CHIP_SIZE / 2;
		int sy1 = ( int )_momo_pos.y - camera->getY( ) - CHIP_SIZE / 2;
		int sx2 = sx1 + CHIP_SIZE;
		int sy2 = sy1 + CHIP_SIZE;
		if ( _momo_vec.x > 0 ) {
			int tmp = sx1;
			sx1 = sx2;
			sx2 = tmp;
		}

		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
		Drawer::Sprite sprite( trans, GRAPH_CHARACTER_2, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
		return;
	}

	if ( _action == ACTION_APPEAR ) {
		int power = _saving_power / ( CAPACITY_SAVING_POWER / 6 );

		int idx = _act_count - 4;
		if ( idx < 0 ) {
			return;
		}

		int tx = ( idx % 8     ) * CHIP_SIZE;
		int ty = ( idx / 8 + 6 ) * CHIP_SIZE;

		int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2 - CHIP_SIZE;
		int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE;
		int sx2 = sx1 + CHIP_SIZE;
		int sy2 = sy1 + CHIP_SIZE;
		if ( isChipReverse( ) ) {
			sx1 += CHIP_SIZE * 2;
			sx2 = sx1 + CHIP_SIZE;
			int tmp = sx1;
			sx1 = sx2;
			sx2 = tmp;
		}

		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
		Drawer::Sprite sprite( trans, GRAPH_CHARACTER_2, Drawer::BLEND_ADD, 1.0 );
		drawer->setSprite( sprite );
		return;
	}

	if ( _action != ACTION_BURST && _saving_power > 0 ) {
		int power = _saving_power / ( CAPACITY_SAVING_POWER / 6 );

		int idx = power * 2 + _act_count % 2;
		int tx = ( idx % 8 ) * CHIP_SIZE;
		int ty = ( idx / 8 ) * CHIP_SIZE;

		int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
		int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE;

		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, 1.0 );
		drawer->setSprite( sprite );
	}
}

void Tarosuke::damage( ) {
	if ( _action != ACTION_DEAD ) {
		_action = ACTION_DEAD;
		_act_count = 0;
	}
}
