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

static const int CROW_NUM = 11;
static const Vector CROW_POS[ CROW_NUM ] = {
	Vector(   0, 100 ),
	Vector(  30, 100 ),
	Vector(  60, 100 ),
	Vector(  90, 100 ),
	Vector( 120, 100 ),
	Vector( 150, 100 ),
	Vector( 180, 100 ),
	Vector( 210, 100 ),
	Vector( 240, 100 ),
	Vector( 270, 100 ),
	Vector( 300, 100 ),
};
BossHag::BossHag( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ),
_count( 0 ) {
	
}


BossHag::~BossHag( ) {

}

void BossHag::act( ) {
	setChipGraph( GRAPH_ENEMY_BOSS, 0, 0 );
}

void BossHag::attack( ) {
	if ( _count == 0 ) {
		for ( int i = 0; i < 5; i++ ) {
			int x = getX( ) - ( int )CROW_POS[ i ].x;
			int y =           ( int )CROW_POS[ i ].y;
			Vector target( getX( ) - SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
			_stock->addEnemy( EnemyPtr( new EnemyCrow( x, y, target ) ) );
		}
		_count = CREATE_COUNT_CROW * 4;
	}

	_count++;
	if ( _count % CREATE_COUNT_CROW == 0 ) {
		int idx = _count / CREATE_COUNT_CROW % CROW_NUM;
		int x = getX( ) - ( int )CROW_POS[ idx ].x;
		int y =           ( int )CROW_POS[ idx ].y;
		Vector target( getX( ) - SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
		_stock->addEnemy( EnemyPtr( new EnemyCrow( x, y, target ) ) );
	}
}

double BossHag::getOverlappedRadius( ) const {
	return RADIUS;
}