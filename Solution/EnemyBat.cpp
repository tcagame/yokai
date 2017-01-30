#include "EnemyBat.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int MOVE_SPEED = 2;
static const int WAIT_ANIME_TIME = 4;

EnemyBat::EnemyBat( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyBat::~EnemyBat( ) {
}

void EnemyBat::act( ) {
	setAccelX( -MOVE_SPEED );
	const int ANIME[ ] = { 0, 1, 2, 3 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 7;
	setChipGraph( GRAPH_ENEMY_SMALL, u, v );
}
