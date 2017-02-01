#include "EnemyEyeSpector.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 2;
static const int WAIT_JUMP_TIME = 40;
static const int JUMP_POWER = -30;

EnemyEyeSpector::EnemyEyeSpector( int x, int y) :
Enemy( x - 400, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ),
_act_count( 0 ) {
}


EnemyEyeSpector::~EnemyEyeSpector( ) {
}

void EnemyEyeSpector::act( ) {
	_act_count++;

	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	setAccelX( -MOVE_SPEED );
	if ( _act_count % WAIT_JUMP_TIME == 0 ) {
		setAccelY( JUMP_POWER );
		if ( _act_count != 0 ) {
			_act_count = -WAIT_JUMP_TIME / 4;
		}
	}

	const int MAX_ANIME_PATTERN = 4;
	int u = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 5;
	setChipGraph( GRAPH_ENEMY_SMALL, u, v );
}
