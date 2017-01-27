#include "EnemyFlog.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 10;

EnemyFlog::EnemyFlog( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::act( ) {
	updateChip( );
}

void EnemyFlog::updateChip( ) {
	int u = 0;
	int v = 0;
	setChipGraph( GRAPH_ENEMY_FLOG, u, v );
}