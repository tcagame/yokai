#include "EnemyRayMonster.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 5;
static const int POW = 2;

EnemyRayMonster::EnemyRayMonster( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyRayMonster::~EnemyRayMonster( ) {
}

void EnemyRayMonster::act( ) {
	setChipGraph( GRAPH_ENEMY_BIG, 0, 6 );
}