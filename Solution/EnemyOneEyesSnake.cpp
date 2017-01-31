#include "EnemyOneEyesSnake.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 5;
static const int MOVE_SPEED = 4;
static const int JUMP_POWER = -30;
static const int WAIT_JUMP_TIME = 40;

EnemyOneEyesSnake::EnemyOneEyesSnake( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyOneEyesSnake::~EnemyOneEyesSnake( ) {
}

void EnemyOneEyesSnake::act( ) {
	actMove( );
	updateChip( );
	_act_count++;
}

void EnemyOneEyesSnake::actMove( ) {
	setAccelX( -MOVE_SPEED );

	if ( _act_count % WAIT_JUMP_TIME == 0 ) {
		setAccelY( JUMP_POWER );
	}
}

void EnemyOneEyesSnake::updateChip( ) {
	const int ANIME[ ] = { 0, 1, 2, 3, 4, 5, 6 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}