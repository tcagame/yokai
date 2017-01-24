#include "EnemyDeceased.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 10;

EnemyDeceased::EnemyDeceased( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ) {
}

EnemyDeceased::~EnemyDeceased( ) {
}

void EnemyDeceased::act( ) {
	const int MAX_ANIME_PATTERN = 5;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 );
	setChipGraph( GRAPH_ENEMY_1, pattern, 2 );
}