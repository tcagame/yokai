#include "EnemyGhoul.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 6;
static const int POW = 3;
static const int MOVE_SPEED = 1;
static const int WAIT_ANIME_TIME = 6;

EnemyGhoul::EnemyGhoul( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}

EnemyGhoul::~EnemyGhoul( ) {
}

void EnemyGhoul::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 4;
	const int v = 10;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, v );
}