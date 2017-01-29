#include "BossBuddha.h"

static const int OFFSET_X = 0;
static const int OFFSET_Y = 0;
static const int HP = 30;
static const int POW = 10;
static const int RADIUS = 100;

BossBuddha::BossBuddha( EnemyStockPtr stock, int x ) :
Boss( OFFSET_X + x, OFFSET_Y, 0, HP, POW ),
_stock( stock ) {
	
}

BossBuddha::~BossBuddha( ) {
}

void BossBuddha::act( ) {
}

void BossBuddha::attack( ) {
}

double BossBuddha::getOverlappedRadius( ) const {
	return RADIUS;
}
