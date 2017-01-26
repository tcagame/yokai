#include "EnemyStone.h"

static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 4;
static const int MOVE_SPEED = 10;

EnemyStone::EnemyStone( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyStone::~EnemyStone( ) {
}

void EnemyStone::act( ) {
	actMove( );
	updateChip( );
}

void EnemyStone::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyStone::updateChip( ) {
	const int MAX_ANIME_PATTERN = 8;
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _act_count / WAIT_ANIME_TIME;
	setChipGraph( GRAPH_ENEMY_COMMON_SMALL, pattern, 2 );
}
