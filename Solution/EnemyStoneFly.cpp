#include "EnemyStoneFly.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 4;

EnemyStoneFly::EnemyStoneFly( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ) {
}


EnemyStoneFly::~EnemyStoneFly( ) {
}

void EnemyStoneFly::act( ) {
	_act_count++;
	actMove( );
	updateChip( );
}

void EnemyStoneFly::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyStoneFly::updateChip( ) {
	const int MAX_ANIME_PATTERN = 4;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int u = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 12;
	setChipGraph( GRAPH_ENEMY_COMMON, u, v );
}