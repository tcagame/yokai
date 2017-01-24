#include "EnemyFlog.h"

static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 40;

EnemyFlog::EnemyFlog( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {

}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::act( ) {
	actMove( );
	updateChip( );
}

void EnemyFlog::actMove( ) {
	setAccelY( 3 );
}

void EnemyFlog::updateChip( ) {
	const int MAX_ANIME_PATTERN = 2;
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _act_count / WAIT_ANIME_TIME;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 0 );
}
