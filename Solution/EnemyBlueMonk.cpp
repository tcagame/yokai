#include "EnemyBlueMonk.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;
static const int MOVE_SPEED = 1;
static const int WAIT_ANIME_TIME = 6;
static const int MAX_ANIME_PATTERN = 4;

EnemyBlueMonk::EnemyBlueMonk( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}

EnemyBlueMonk::~EnemyBlueMonk( ) {
}

void EnemyBlueMonk::act( ) {
	setAccelX( -MOVE_SPEED );
	
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	const int v = 11;
	const int MOTION[ 4 ] = { 0, 1, 2, 3 };
	int u = MOTION[ ( _count / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}