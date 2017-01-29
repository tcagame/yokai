#include "EnemyBloodPondDemon.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 2;

EnemyBloodPondDemon::EnemyBloodPondDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyBloodPondDemon::~EnemyBloodPondDemon( ) {
}

void EnemyBloodPondDemon::act( ) {
	updateChip( );
}

void EnemyBloodPondDemon::updateChip( ) {
	setChipGraph( GRAPH_ENEMY_BIG_2, 4, 3 );
}
