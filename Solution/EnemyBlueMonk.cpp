#include "EnemyBlueMonk.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 6;
static const int MAX_ANIME_PATTERN = 4;

EnemyBlueMonk::EnemyBlueMonk( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
}

EnemyBlueMonk::~EnemyBlueMonk( ) {
}

void EnemyBlueMonk::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );
	
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	const int v = 11;
	const int MOTION[ 4 ] = { 0, 1, 2, 3 };
	int u = MOTION[ ( _count / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}