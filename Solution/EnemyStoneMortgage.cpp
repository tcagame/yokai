#include "EnemyStoneMortgage.h"
#include "Sound.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int MOVE_SPEED = 20;
static const int HP = 1;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 3;

EnemyStoneMortgage::EnemyStoneMortgage( int x, int y, int type ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_base_pos( x, y ),
_type( type ),
_moveing( false ),
_count( rand( ) % 4 ) {
	_return_pos = _base_pos;
}

EnemyStoneMortgage::~EnemyStoneMortgage( ) {
}

void EnemyStoneMortgage::act( ) {
	actMove( );
	updateChip( );
}

void EnemyStoneMortgage::setMove( bool moveing ) {
	_moveing = moveing;
	if ( !_moveing ) {
		_return_pos = Vector( getX( ), getY( ) );
	} else {
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_voice_37.wav" );
		setAccelX( rand( ) % 20 - 10 );
		setAccelY( -40 );
		_vy = -40;
	}
}

bool EnemyStoneMortgage::isOutSideScreen( CameraConstPtr camera ) const {
	return false;
}

void EnemyStoneMortgage::actMove( ) {
	if ( _moveing ) {
		_count++;
		if ( isStanding( ) ) {
			_vy *= 0.8;
			setAccelY( ( int )_vy );
		}
	} else {
		setAccelX( 0 );
		setAccelY( 0 );
		Vector v = _base_pos - _return_pos;
		double length = v.getLength( );
		_return_pos += v.normalize( ) * length * 0.1;
		setX( ( int )_return_pos.x );
		setY( ( int )_return_pos.y );
	}
}

void EnemyStoneMortgage::updateChip( ) {
	int u = _type % 2 * 4 + _count / WAIT_ANIME_TIME % 4;
	int v = 4 + _type / 2;
	setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );
}

void EnemyStoneMortgage::damage( int pow ) {
	if ( pow < 0 ) {
		Enemy::damage( pow );
	}
}