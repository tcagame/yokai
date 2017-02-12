#include "EnemyStoneFly.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const double ACCEL = 0.3;
static const double SPEED = 10.0;

EnemyStoneFly::EnemyStoneFly( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ),
_pos( x, y ),
_vec( 0, 0 ) {
}


EnemyStoneFly::~EnemyStoneFly( ) {
}

void EnemyStoneFly::act( ) {
	Vector target( getTargetX( ), getTargetY( ) );
	Vector vec = target - _pos;
	vec = vec.normalize( ) * ACCEL;
	_vec += vec;
	if ( getY( ) < CHIP_SIZE ) {
		_vec.y = ACCEL;
	}
	if ( getY( ) > BG_SIZE + CHIP_SIZE ) {
		_vec.y = -ACCEL;
	}
	if ( _vec.getLength2( ) > SPEED * SPEED ) {
		_vec = _vec.normalize( ) * SPEED;
	}
	_pos += _vec;
	
	setX( ( int )_pos.x );
	setY( ( int )_pos.y );

	_act_count++;
	const int MAX_ANIME_PATTERN = 4;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int u = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}