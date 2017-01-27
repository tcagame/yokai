#include "EnemyMoth.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 1;
static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyMoth::EnemyMoth( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
}


EnemyMoth::~EnemyMoth( ) {
}

void EnemyMoth::act( ) {
	actMove( );
	updateChip( );
}

void EnemyMoth::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyMoth::updateChip( ) {
	const int MAX_ANIME_PATTERN = 2;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 1 );
}