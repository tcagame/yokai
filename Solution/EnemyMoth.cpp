#include "EnemyMoth.h"

static const int WAIT_ANIME_TIME = 20;
static const int MOVE_SPEED = 1;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;

EnemyMoth::EnemyMoth( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY, CHIP_SIZE, CHIP_FOOT, false ),
_anime_count( 0 ) {
}


EnemyMoth::~EnemyMoth( ) {
}

void EnemyMoth::act( ) {
	actMove( );
	updateChip( );
}

void EnemyMoth::actMove( ) {
	int add_x = 0;
	int add_y = 0;
	if ( getX( ) % 4 == 0 ) {
		add_x = 1;
	}
	if ( getX( ) % 4 == 1 ) {
		add_y = -1;
	}
	if ( getX( ) % 4 == 2 ) {
		add_x = -1;
	}
	if ( getX( ) % 4 == 3 ) {
		add_y = 1;
	}
	setAccelX( MOVE_SPEED + add_x );
}

void EnemyMoth::updateChip( ) {
	const int MAX_ANIME_PATTERN = 3;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME% ( MAX_ANIME_PATTERN - 1 );
	setChipUV( pattern, 0 );
}