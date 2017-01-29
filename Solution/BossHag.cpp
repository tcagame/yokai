#include "BossHag.h"
#include "define.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 100;
static const int HP  = 20;
static const int POW = 10;
static const double RADIUS = 50;

BossHag::BossHag( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ) {

}


BossHag::~BossHag( ) {

}

void BossHag::act( ) {
	setChipGraph( GRAPH_BOSS, 0, 0 );
}

void BossHag::drawOverlapped( CameraConstPtr camera ) const {

}

void BossHag::attack( ) {

}

double BossHag::getOverlappedRadius( ) const {
	return RADIUS;
}