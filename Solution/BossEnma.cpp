#include "BossEnma.h"

static const int CHIP_SIZE = 128;
static const int OFFSET_X = 192 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 265;
static const int HP  = 20;
static const int POW = 10;
static const int CREATE_COUNT_ENEMY = 60;
static const double RADIUS = 12;

BossEnma::BossEnma( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ) {
}


BossEnma::~BossEnma( ) {
}

void BossEnma::act( ) {
	setChipGraph( GRAPH_BOSS, 0, 0 );
}

void BossEnma::attack( ) {
}

double BossEnma::getOverlappedRadius( ) const {
	return RADIUS;
}