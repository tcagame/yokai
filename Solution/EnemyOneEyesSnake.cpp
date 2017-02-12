#include "EnemyOneEyesSnake.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 15;
static const int MOVE_SPEED = 4;
static const int JUMP_POWER = -50;

EnemyOneEyesSnake::EnemyOneEyesSnake( int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) ,
_move_speed( -MOVE_SPEED ),
_count( 0 ) {
	if ( dir_right ) {
		_move_speed *= -1;
	}
}


EnemyOneEyesSnake::~EnemyOneEyesSnake( ) {
}

void EnemyOneEyesSnake::act( ) {
	actMove( );
	updateChip( );
}

void EnemyOneEyesSnake::actMove( ) {
	_count++;
	if ( _count > 15 * 4 ) {
		if ( isStanding( ) ) {
			_count = 0;
		}
	} else {
		setAccelX( 0 );
		setAccelY( 0 );
	}
	if ( _count == 14 * 4 ) {
		setAccelX( _move_speed );
		setAccelY( JUMP_POWER );
	}

}

void EnemyOneEyesSnake::updateChip( ) {
	const int ANIME[ 16 ] = { 0, 1, 2, 3, 4, 5, 6, 7, 7, 6, 5, 4, 3, 2, 1, 0 };
	int idx = _count / 4;
	if ( idx > 15 ) {
		idx = 15;
	}
	int u = ANIME[ idx ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}