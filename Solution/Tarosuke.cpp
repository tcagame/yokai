#include "Tarosuke.h"
#include "Device.h"
#include "define.h"
#include "PsychicMgr.h"
#include "Camera.h"
#include "Drawer.h"
#include "PsychicTarosuke.h"
#include "Momotaro.h"
#include "Sound.h"
#include "Power.h"
#include "Game.h"
#include "Enemy.h"

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
static const int BURST_COUNT = 40;
static const int SHOOT_FOOT = 40;
static const int MOMO_SPEED = 10;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 18;
static const int FALTER_COUNT = 6;
static const int INVINCIBLE_COUNT = 30;
static const int JET_POWER = 70;
static const int FALLOUT_POW = 6;


Tarosuke::Tarosuke( PsychicMgrPtr psychic, PowerPtr power, MomotaroPtr momotaro ) : 
Character( START_X, START_Y, CHIP_SIZE, CHIP_FOOT, true ),
_momotaro( momotaro ),
_power( power ) {
	_psychic_mgr = psychic;
	_jump_count = 0;
	_action = ACTION_FLOAT;
	_act_count = 0;
	_invincible_count = 0;
	setChipReverse( true );
}

Tarosuke::~Tarosuke( ) {

}

void Tarosuke::warp( int v ) {
	int x = getX( ) + v * BG_SIZE;
	setX( x );
	setY( 0 );
}

void Tarosuke::adjust( CameraConstPtr camera ) {
	if ( getX( ) < camera->getX( ) + CHIP_SIZE / 2 ) {
		setX( camera->getX( ) + CHIP_SIZE / 2 );
	}
	if ( getX( ) > camera->getX( ) + SCREEN_WIDTH - CHIP_SIZE / 2 ) {
		setX( camera->getX( ) + SCREEN_WIDTH - CHIP_SIZE / 2 );
	}
}

bool Tarosuke::isCalling( ) const {
	return
		_action == ACTION_CALL ||
		_action == ACTION_APPEAR;
}

void Tarosuke::act( ) {
	GamePtr game = Game::getTask( );
	game->addDebugMessage( "Tarosuke x:%05d(%03d) y:%03d", getX( ), getX( ) % BG_SIZE, getY( ) );
	_act_count++;
	_invincible_count--;
	if ( _invincible_count < 0 ) {
		_invincible_count = 0;
	}

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
	case ACTION_FALLOUT:
		actOnFallingOut( );
		break;
	case ACTION_BRAKE:
		actOnBraking( );
		break;
	case ACTION_FALTER:
		actOnFaltering( );
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
	
	// –³“G’†‚Í“_–Å‚·‚é
	if ( _invincible_count % 2 == 1 ) { 
		setChipGraph( GRAPH_CHARACTER_2, 7, 7 );
	}

	if ( _action != ACTION_DEAD && _power->get( ) == 0 ) {
		_action = ACTION_DEAD;
		_act_count = 0;
		if ( _momotaro ) {
			_momotaro->hide( );
		}
		SoundPtr sound = Sound::getTask( );
		sound->playBGM( "yokai_se_31.wav" );
		sound->stopSE( "yokai_se_02.wav" );
		return;
	}
}

void Tarosuke::actOnStanding( ) {
	DevicePtr device = Device::getTask( );
	SoundPtr sound = Sound::getTask( );

	if ( !isStanding( ) ) {
		_action = ACTION_FLOAT;
		return;
	}
	
	_air_jump = true;
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
		GamePtr game = Game::getTask( );
		if ( game->isSolo( ) ) {
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

	FLOOR floor = getFloor( );

	if ( !moving ) {
		if ( device->getDirY( ) > 90 && floor == FLOOR_ROAD ) {
			_saving_power++;
			if ( _saving_power >= CAPACITY_SAVING_POWER ) {
				_action = ACTION_BURST;
				_act_count = 0;
				return;
			}
		} else {
			_saving_power -= 4;
			if ( _saving_power < 0 ) {
				_saving_power = 0;
			}
		}
	}

	switch ( floor ) {
	case FLOOR_WATER:
		{
			_saving_power = 0;
			const int ANIM[ 4 ] = { 0, 1, 2, 1 };
			int u = ANIM[ ( _act_count / 4 ) % 4 ];
			if ( getAccelX( ) != 0 ) {
				u += 4;
				if ( _act_count % ( 4 * 4 / 2 ) == 0 ) {
					sound->playSE( "yokai_voice_14.wav" );
				}
			}
			setChipGraph( GRAPH_CHARACTER_1, u, 3 );
		}
		break;
	case FLOOR_BOG:
		{
			_saving_power = 0;
			const int ANIM[ 8 ] = { 1, 2, 4, 5, 3, 5, 4, 2 };
			int u = ANIM[ ( _act_count / 4 ) % 8 ];
			if ( getAccelX( ) == 0 ) {
				u = 4;
			}
			setChipGraph( GRAPH_CHARACTER_1, u, 7 );
		}
		break;
	default:
		{
			if ( getAccelX( ) == 0 ) {
				if ( _saving_power == 0 ) {
					setChipGraph( GRAPH_CHARACTER_1, 0, 0 );
				} else {
					setChipGraph( GRAPH_CHARACTER_1, _saving_power / ( CAPACITY_SAVING_POWER / 7 ), 4 );
				}
			} else {
				const int WALK[ WALK_PATTERN ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
				int u = WALK[ ( getX( ) / WAIT_TIME ) % WALK_PATTERN ];
				setChipGraph( GRAPH_CHARACTER_1, u, 0 );
				if ( _act_count % ( WALK_PATTERN ) == 0 ) {
					sound->playSE( "yokai_voice_15.wav" );
				}
			}
		}
		break;
	}
}

void Tarosuke::actOnJumping( ) {
	DevicePtr device = Device::getTask( );
	SoundPtr sound = Sound::getTask( );
	
	_action = ACTION_FLOAT;
	if ( ( device->getButton( ) & BUTTON_C ) == 0 ) {
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

	setChipGraph( GRAPH_CHARACTER_1, 6, 0 );
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
	
	if ( device->getPush( ) == BUTTON_C && _air_jump ) {
		_air_jump = false;
		_jump_count = JUMP_COUNT;
		_action = ACTION_JUMP;
		setAccelY( -JUMP_POWER );
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

	if ( getY( ) > SCREEN_HEIGHT + CHIP_SIZE ) {
		_action = ACTION_FALLOUT; 
	}

	setAccelX( ax );
	setChipGraph( GRAPH_CHARACTER_1, 5, 0 );
}

void Tarosuke::actOnFallingOut( ) {
	setY( SCREEN_HEIGHT + CHIP_SIZE - 1 ); // ‚Ü‚¾—Ž‚¿‚Ä‚È‚¢‚¬‚è‚¬‚è‚Ü‚Å–ß‚·
	setAccelY( -JET_POWER );
	damage( FALLOUT_POW );
}

void Tarosuke::actOnBursting( ) {
	if ( _act_count > BURST_COUNT ) {
		_saving_power = 0;
		_action = ACTION_STAND;
	}
	const int ANIM[ ] = { 39, 40, 41, 40, 41, 40, 41, 40, 41, 40, 41, 40, 41 };
	setChipGraph( GRAPH_CHARACTER_1, ANIM[ _act_count / 10 ] % 8, ANIM[ _act_count / 10 ] / 8 );
}

void Tarosuke::actOnFaltering( ) {
	switch ( getFloor( ) ) {
	case FLOOR_WATER:
		setChipGraph( GRAPH_CHARACTER_2, 0, 0 );
		break;
	case FLOOR_BOG:
		setChipGraph( GRAPH_CHARACTER_2, 0, 1 );
		break;
	default:
		setChipGraph( GRAPH_CHARACTER_2, 0, 2 );
		break;
	}

	if ( isChipReverse( ) ) {
		setAccelX( MAX_SPEED );
	} else {
		setAccelX( -MAX_SPEED );
	}

	if ( _act_count > FALTER_COUNT ) {
		_action = ACTION_STAND;
	}
}

void Tarosuke::actOnShooting( ) {
	int level = _saving_power / ( CAPACITY_SAVING_POWER / 4 );
	_psychic_mgr->shoot( PsychicPtr( new PsychicTarosuke(
		getX( ), getY( ) - SHOOT_FOOT, isChipReverse( ), level ) ) );
	_saving_power = 0;
	_action = ACTION_STAND;
	
	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_se_20.wav" );
}

void Tarosuke::actOnCalling( ) {
	_saving_power = 0;

	const int PRAY[ 14 ] = { 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 2, 1 };
	setChipGraph( GRAPH_CHARACTER_1, PRAY[ _act_count % 14 ], 1 );
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
	int n = 12 + _act_count / 2;
	if ( n > 17 ) {
		n = 17;
	}
	setChipGraph( GRAPH_CHARACTER_1, n % 8, n / 8 );

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
	setChipGraph( GRAPH_CHARACTER_1, CALL[ _act_count / 2 % 60 ], 6 );

	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) == BUTTON_B ) {
		_momotaro->hide( );
		_action = ACTION_STAND;
	}
}

void Tarosuke::actOnDying( ) {
	setAccelX( 0 );
	switch ( getFloor( ) ) {
	case FLOOR_WATER:
		{
			int idx = _act_count / 4;
			int u = idx % 8;
			int v = 0;
			if ( idx >= 8 ) {
				u = 8;
				v = 8;
			}
			setChipGraph( GRAPH_CHARACTER_2, u, v );
		}
		break;
	case FLOOR_BOG:
		{
			int idx = _act_count / 4;
			int u = idx % 8;
			int v = 1;
			if ( idx >= 8 ) {
				u = 8;
				v = 8;
			}
			setChipGraph( GRAPH_CHARACTER_2, u, v );
		}
		break;
	default:
		{
			const int DYING[ 23 ] = {
				0, 1, 2, 3, 5, 4,
				0, 1, 2, 3, 5, 4,
				0, 1, 2, 3, 5, 4,
				0, 1, 6, 7, 8,
			};
			int idx = _act_count / 4;
			if ( idx > 22 ) {
				idx = 22;
			}
			setChipGraph( GRAPH_CHARACTER_2, DYING[ idx ] % 8, DYING[ idx ] / 8 + 2 );
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
		int idx = _act_count - 4;
		if ( idx < 0 ) {
			return;
		}

		int tx = ( idx % 8     ) * CHIP_SIZE;
		int ty = ( idx / 8 + 6 ) * CHIP_SIZE;

		int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2 - CHIP_SIZE / 2;
		int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE;
		int sx2 = sx1 + CHIP_SIZE;
		int sy2 = sy1 + CHIP_SIZE;
		if ( isChipReverse( ) ) {
			sx1 += CHIP_SIZE;
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

	if ( _saving_power > 0 ) {
		int power = _saving_power / ( CAPACITY_SAVING_POWER / 6 );

		int idx = power * 2 + _act_count % 2;
		int tx = ( idx % 8 ) * CHIP_SIZE;
		int ty = ( idx / 8 ) * CHIP_SIZE;

		int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
		int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE;

		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_21.wav" );
		DevicePtr device = Device::getTask( );
		if ( device->getDirY( ) == 0 || _saving_power >= 25 ) {
			sound->stopSE( "yokai_se_21.wav" );
		}
		if ( _saving_power >= 25 && _saving_power <= 40 ) {
			sound->playSE( "yokai_se_22.wav" );
		}
		if ( device->getDirY( ) == 0 || _saving_power >= 40 ) {
			sound->stopSE( "yokai_se_22.wav" );
		}

		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, 1.0 );
		drawer->setSprite( sprite );
	}
}

void Tarosuke::damage( int pow ) {
	GamePtr game = Game::getTask( );
	if ( game->isDebug( ) ) {
		return;
	}

	switch ( _action ) {
	case ACTION_DEAD:
	case ACTION_APPEAR:
	case ACTION_CALL:
	case ACTION_PRAY:
		return;
	};

	if ( _invincible_count > 0 ) {
		return;
	}

	_invincible_count = INVINCIBLE_COUNT;
	_power->decrease( pow );
	_action = ACTION_FALTER;
	_act_count = 0;
	_saving_power = 0;
	setAccelX( 0 );
	setChipReverse( !isChipReverse( ) );

	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_voice_26.wav" );
}

bool Tarosuke::isOnHead( EnemyPtr target ) const {
	if ( !target->isHead( ) ) { 
		return false;
	}
	if ( _action != ACTION_FLOAT ) {
		return false;
	}
	Vector taro = getOverlappedPos( );
	Vector ene  = target->getOverlappedPos( );
	Vector vec = ene - taro;
	if ( vec.y < 0 ) {
		return false;
	}
	if ( vec.getLength( ) < target->getOverlappedRadius( ) ) {
		return false;
	}
	return true;
}

void Tarosuke::bound( ) {
	_jump_count = JUMP_COUNT;
	_action = ACTION_JUMP;
	setAccelY( -JUMP_POWER );
}
