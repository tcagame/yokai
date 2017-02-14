#include "EnemyCrow.h"
#include "Sound.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int SPEED = 10;
static const int ANIMATION_WAIT_TIME = 6;
static const int WAIT_COUNT = 180;

EnemyCrow::EnemyCrow( int x, int y, int pattern, const Vector& target ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_pattern( pattern ),
_pos( x, y ),
_target( target ) {
	_vec = _target - _pos;
	_vec.y = 0;
	_vec = _vec.normalize( ) * SPEED;
	_action = ACTION_APPEAR;

	setX( ( int )_pos.x );
	setY( ( int )_pos.y );

	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_voice_02.wav" );
}

EnemyCrow::~EnemyCrow( ) {
}

void EnemyCrow::act( ) {
	_count++;
	
	switch ( _action ) {
	case ACTION_APPEAR:
		actOnAppearing( );
		break;
	case ACTION_WAIT:
		actOnWaiting( );
		break;
	case ACTION_MOVE:
		actOnMoving( );
		break;
	}
}
	
void EnemyCrow::actOnAppearing( ) {
	const int ANIM[ 8 ] = { 13, 12, 11, 10, 9, 8, 8, 9 };
	int u = ANIM[ _count / ANIMATION_WAIT_TIME % 8 ] % 4;
	int v = ANIM[ _count / ANIMATION_WAIT_TIME % 8 ] / 4;
	int idx = _count / ANIMATION_WAIT_TIME;
	if ( idx >= 8 - 1 ) {
		_action = ACTION_WAIT;
	}

	setChipGraph( GRAPH_ENEMY_CROW, u, v );
}

void EnemyCrow::actOnWaiting( ) {
	int u = 2;
	int v = 0;
	if ( _count % 100 < 30 ) {
		u = 3;
	}
	if ( _count % 123 < 5 ) {
		u = 0;
		v = 1;
	}
	if ( _count > WAIT_COUNT ) {
		_action = ACTION_MOVE;
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_voice_02.wav" );
	}
	setChipGraph( GRAPH_ENEMY_CROW, u, v );
}

void EnemyCrow::actOnMoving( ) {
	//_pattern = 1;
	switch ( _pattern ) {
	case 0:
		{
			Vector v = Vector( SCREEN_WIDTH * 4 / 5, SCREEN_HEIGHT / 2 );
			_vec += v.normalize( ) * ( SPEED * 0.07 );
			_vec = _vec.normalize( ) * SPEED * 2;
			break;
		}
	case 1:
		{
			Vector v = Vector( SCREEN_WIDTH / 2, SCREEN_HEIGHT * 2 );
			if ( _pos.x < SCREEN_WIDTH*12/10 ) {
				v = Vector( 0, -SCREEN_HEIGHT );
			}
			_vec += v.normalize( ) * ( SPEED * 0.05 );
			_vec = _vec.normalize( ) * SPEED;
			break;
		}
	default:
		{
			Vector v = _target - _pos;
			_vec += v.normalize( ) * ( SPEED * 0.05 );
			_vec = _vec.normalize( ) * SPEED;
			break;
		}
	}
	_pos += _vec;
	setX( ( int )_pos.x );
	setY( ( int )_pos.y );

	if ( _vec.x > 0 ) {
		setChipReverse( true );
	} else {
		setChipReverse( false );
	}
	setChipGraph( GRAPH_ENEMY_CROW, _count / ANIMATION_WAIT_TIME % 2, 0 );
}

