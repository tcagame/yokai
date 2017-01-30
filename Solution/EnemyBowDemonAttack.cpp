#include "EnemyBowDemonAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 2;
static const int MOVE_SPEED = 6;

EnemyBowDemonAttack::EnemyBowDemonAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_EFFECT_SMALL, 0, 5 );
}


EnemyBowDemonAttack::~EnemyBowDemonAttack( ) {
}

void EnemyBowDemonAttack::act( ) {
	setAccelX( -MOVE_SPEED );
}