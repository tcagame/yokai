#include "EnemyGhoul.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 6;
static const int POW = 3;
static const int WAIT_ANIME_TIME = 6;

EnemyGhoul::EnemyGhoul( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ),
_speed( -2 ) {
}

EnemyGhoul::~EnemyGhoul( ) {
}

void EnemyGhoul::act( ) {
	_count++;

	if ( _count % 24 == 0 ) {
		_speed *= -1;
	}
	
	setAccelX( _speed );
	
	const int MAX_ANIME_PATTERN = 4;
	const int v = 10;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, v );
}