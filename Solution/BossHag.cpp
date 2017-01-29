#include "BossHag.h"
#include "define.h"
#include "EnemyCrow.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 100;
static const int HP  = 20;
static const int POW = 10;
static const int CREATE_COUNT_CROW = 60;
static const double RADIUS = 50;

BossHag::BossHag( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ) {

}


BossHag::~BossHag( ) {

}

void BossHag::act( ) {
	setChipGraph( GRAPH_BOSS, 0, 0 );
}

void BossHag::attack( ) {
	_count++;
	if ( _count % CREATE_COUNT_CROW == 0 ) {
		int x = getX( ) - rand( ) % SCREEN_WIDTH;
		int y = rand( ) % 150 + 100;
		Vector target( getX( ) - SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
		_stock->addEnemy( EnemyPtr( new EnemyCrow( x, y, target ) ) );
	}
}

double BossHag::getOverlappedRadius( ) const {
	return RADIUS;
}