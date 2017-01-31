#include "EnemyShishimai.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 3;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 3;

EnemyShishimai::EnemyShishimai( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_anime_count( 0 ) {
}


EnemyShishimai::~EnemyShishimai( ) {
}

void EnemyShishimai::act( ) {
	setAccelX( -MOVE_SPEED );
	
	const int MOTION[ ] = { 8, 9, 10, 11 };
	int pattern = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _anime_count / WAIT_ANIME_TIME ) % pattern ];
	_anime_count %= WAIT_ANIME_TIME * pattern;
	_anime_count++;

	setChipGraph( GRAPH_ENEMY_NOMAL, u, 12 );
}