#include "EnemyWindMonsterAttack.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 3;
static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED_X = 10;
static const int MOVE_SPEED_Y = 3;

EnemyWindMonsterAttack::EnemyWindMonsterAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyWindMonsterAttack::~EnemyWindMonsterAttack( ) {
}

void EnemyWindMonsterAttack::act( ) {
	setAccelX( MOVE_SPEED_X );
	setAccelY( MOVE_SPEED_Y );
	int u = 10;
	int v = 3;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}