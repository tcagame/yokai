#include "EnemyHellFire.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int SPEED = 10;
static const double ACCEL = 0.3;


EnemyHellFire::EnemyHellFire( int x, int y, int hp ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, hp, POW ) {
	_act_count = 0;
}


EnemyHellFire::~EnemyHellFire( ) {
}


void EnemyHellFire::act( ) {
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
	int u = 4 + _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );

}
