#include "EnemyStoneRote.h"

static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 4;
static const int MOVE_SPEED = 10;

EnemyStoneRote::EnemyStoneRote( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyStoneRote::~EnemyStoneRote( ) {
}

void EnemyStoneRote::act( ) {
	actMove( );
	updateChip( );
}

void EnemyStoneRote::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyStoneRote::updateChip( ) {
	const int MAX_ANIME_PATTERN = 8;
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _act_count / WAIT_ANIME_TIME;
	setChipGraph( GRAPH_ENEMY_COMMON_SMALL, pattern, 2 );
}
