#include "EnemyRockMassShell.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 20;
static const int POW = 1;

EnemyRockMassShell::EnemyRockMassShell( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyRockMassShell::~EnemyRockMassShell( ) {
}

void EnemyRockMassShell::act( ) {
	int u = 5;
	int v = 4;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );	
}