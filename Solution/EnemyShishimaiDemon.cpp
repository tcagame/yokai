#include "EnemyShishimaiDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 20;
static const int MOVE_SPEED = 5;

EnemyShishimaiDemon::EnemyShishimaiDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyShishimaiDemon::~EnemyShishimaiDemon( ) {
}

void EnemyShishimaiDemon::act( ) {
	setAccelX( -MOVE_SPEED );
	const int ANIME[ ] = { 12, 13, 14, 15, 14, 13 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
}