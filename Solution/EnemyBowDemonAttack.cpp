#include "EnemyBowDemonAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 6;
static const int MOVE_SPEED = 20;

EnemyBowDemonAttack::EnemyBowDemonAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_NORMAL, 28, 10 );
}


EnemyBowDemonAttack::~EnemyBowDemonAttack( ) {
}

void EnemyBowDemonAttack::act( ) {
	setAccelX( -MOVE_SPEED );
}