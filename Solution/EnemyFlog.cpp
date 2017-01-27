#include "EnemyFlog.h"

static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 40;
static const int SMASHED_COUNT = 5;

EnemyFlog::EnemyFlog( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_smashed_count( 0 ) {

}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::steppedOn( ) {
	if ( _smashed_count == 0 ) {
		_smashed_count = 1;
	}
}

void EnemyFlog::act( ) {
	if ( _smashed_count > 0 ) {
		_smashed_count ++;
		setChipGraph( GRAPH_ENEMY_SMALL, 3, 3 );
		if ( _smashed_count > SMASHED_COUNT ) {
			damage( -1 );
		}
	} else {
		setAccelY( 3 );
		const int MAX_ANIME_PATTERN = 2;
		_act_count++;
		_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
		int pattern = _act_count / WAIT_ANIME_TIME;
		setChipGraph( GRAPH_ENEMY_SMALL, pattern, 4 );
	}
}
