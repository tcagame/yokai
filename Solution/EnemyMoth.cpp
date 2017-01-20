#include "EnemyMoth.h"

static const int WAIT_ANIME_TIME = 20;
static const int MOVE_SPEED = 1;

EnemyMoth::EnemyMoth( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY, false ),
_anime_count( 0 ) {
}


EnemyMoth::~EnemyMoth( ) {
}

void EnemyMoth::act( ) {
	actMove( );
	updateChip( );
}

void EnemyMoth::actMove( ) {

}

void EnemyMoth::updateChip( ) {
	const int MAX_ANIME_PATTERN = 3;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME% ( MAX_ANIME_PATTERN - 1 );
	setChipUV( pattern, 0 );
}