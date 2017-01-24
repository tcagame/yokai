#include "EnemyDeceasedThird.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 10;

EnemyDeceasedThird::EnemyDeceasedThird( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ) {
}


EnemyDeceasedThird::~EnemyDeceasedThird( ) {
}

void EnemyDeceasedThird::act( ) {
	const int MAX_ANIME_PATTERN = 3;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 );
	setChipGraph( GRAPH_ENEMY_1, pattern, 3 );
}