#include "EnemyMoth.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 1;
static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 3;

EnemyMoth::EnemyMoth( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
}


EnemyMoth::~EnemyMoth( ) {
}

void EnemyMoth::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 2;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 1 );
}
