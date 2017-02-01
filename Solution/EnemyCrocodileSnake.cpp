#include "EnemyCrocodileSnake.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 4;
static const int POW = 6;
static const int MOVE_SPEED = 2;
static const int WAIT_ANIME_TIME = 10;

EnemyCrocodileSnake::EnemyCrocodileSnake( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
}


EnemyCrocodileSnake::~EnemyCrocodileSnake( ) {
}

void EnemyCrocodileSnake::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	actMove( );
	updateChip( );
}

void EnemyCrocodileSnake::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyCrocodileSnake::updateChip( ) {
	const int MAX_ANIME_PATTERN = 8;
	int u = 4 + getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 8;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}