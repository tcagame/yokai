#include "EnemyBowDemonAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 6;
static const int MOVE_SPEED = 20;

EnemyBowDemonAttack::EnemyBowDemonAttack( int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_move_speed( -MOVE_SPEED ) {
	setChipGraph( GRAPH_ENEMY_NORMAL, 28, 10 );
	if ( dir_right ) {
		_move_speed *= -1;
	}
}


EnemyBowDemonAttack::~EnemyBowDemonAttack( ) {
}

void EnemyBowDemonAttack::act( ) {
	setAccelX( _move_speed );
}