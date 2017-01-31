#include "EnemyHellFire.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 4;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 5;

EnemyHellFire::EnemyHellFire( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyHellFire::~EnemyHellFire( ) {
}


void EnemyHellFire::act( ) {
	setAccelX( -MOVE_SPEED );
	const int ANIME[ ] { 4, 5, 6, 5, 7, 4, 7 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
}
