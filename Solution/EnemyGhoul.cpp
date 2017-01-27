#include "EnemyGhoul.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;
static const int MOVE_SPEED = 1;
static const int WAIT_ANIME_TIME = 6;

EnemyGhoul::EnemyGhoul( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}

EnemyGhoul::~EnemyGhoul( ) {
}

void EnemyGhoul::act( ) {
	actMove( );
	updateChip( );
}

void EnemyGhoul::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyGhoul::updateChip( ) {
	const int MAX_ANIME_PATTERN = 4;
	const int v = 12;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 ) + 8;
	setChipGraph( GRAPH_ENEMY_NOMAL, pattern, v );
}