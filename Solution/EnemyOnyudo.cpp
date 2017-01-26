#include "EnemyOnyudo.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 3;
static const int MOVE_SPEED = 3;

EnemyOnyudo::EnemyOnyudo( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyOnyudo::~EnemyOnyudo( ) {
}

void EnemyOnyudo::act( ) {
	actMove( );
	updateChip( );
}

void EnemyOnyudo::actMove( ) {

}

void EnemyOnyudo::updateChip( ) {
	int u = 0;
	int v = 0;
	setChipGraph( GRAPH_ENEMY_COMMON_BIG, u, v );
}
