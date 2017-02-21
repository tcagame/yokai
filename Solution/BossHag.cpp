#include "BossHag.h"
#include "define.h"
#include "EnemyCrow.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 100;
static const int HP  = 30;
static const int POW = 6;
static const int CREATE_COUNT_CROW = 30;
static const int ANIMESTON_TIME = 8;
static const double RADIUS = 50;

static const int CROW_NUM = 11;
static const Vector CROW_POS[ CROW_NUM ] = {
	Vector( -170,  400 ), // (ínñ )

	Vector(  130,  100 ), // 1(ç∂è„é})
	Vector(  300,  170 ), // 2(ç∂â∫é})
	Vector( -110,   80 ), // 3(âEè„ëæé})
	Vector( -120,  190 ), // 4(âEâ∫é})
	Vector(  -50,  290 ), // 5(îkå®)

	Vector(  200,  170 ), // 2
	Vector(   30,  200 ), // 5(îkì™)
	Vector( -170,  190 ), // 4
	Vector(  150,  160 ), // 2
	Vector(  180,   70 ), // 1

};
BossHag::BossHag( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ),
_count( 0 ) {
	
}


BossHag::~BossHag( ) {

}

void BossHag::act( ) {
	const int ANIME[ ] = { 0, 1, 0, 1, 0, 1, 0, 3, 4, 2, 3, 4, 0, 5, 5 };
	const int pattern = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _count / ANIMESTON_TIME % pattern ] % 3;
	int v = ANIME[ _count / ANIMESTON_TIME % pattern ] / 3;
	//Å@ç≈èâÇ…ÈÎÇ…éwé¶ÇèoÇ∑
//	if ( 100 < _count && _count < 120 ) {
//		u = 2;
//		v = 1;
//	}

	setChipGraph( GRAPH_ENEMY_BOSS, u, v );
}

void BossHag::attack( ) {
	if ( _count == 0 ) {
		for ( int i = 0; i < 5; i++ ) {
			int x = getX( ) - ( int )CROW_POS[ i ].x;
			int y =           ( int )CROW_POS[ i ].y;
			_stock->addEnemy( EnemyPtr( new EnemyCrow( x, y ) ) );
		}
		_count = CREATE_COUNT_CROW * 4;
	}

	_count++;
	if ( _count % CREATE_COUNT_CROW == 0 ) {
		int idx = _count / CREATE_COUNT_CROW % CROW_NUM;
		int x = getX( ) - ( int )CROW_POS[ idx ].x;
		int y =           ( int )CROW_POS[ idx ].y;
		_stock->addEnemy( EnemyPtr( new EnemyCrow( x, y ) ) );
	}
}

double BossHag::getOverlappedRadius( ) const {
	return RADIUS;
}