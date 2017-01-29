#include "EnemyJizoAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 8;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 1;

EnemyJizoAttack::EnemyJizoAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyJizoAttack::~EnemyJizoAttack( ) {
}

void EnemyJizoAttack::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 2;
	int u = getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 3;
	setChipGraph( GRAPH_ENEMY_FIREBALL, u, v );
}
