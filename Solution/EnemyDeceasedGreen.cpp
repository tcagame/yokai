#include "EnemyDeceasedGreen.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;
static const int WAIT_JUMP_TIME = 40;
static const int JUMP_POWER = -30;

EnemyDeceasedGreen::EnemyDeceasedGreen( int x, int y, bool right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
	if ( right ) {
		_move_speed *= -1;
	}
}


EnemyDeceasedGreen::~EnemyDeceasedGreen( ) {
}

void EnemyDeceasedGreen::act( ) {
	_act_count++;
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	if ( _act_count % WAIT_JUMP_TIME == 0 ) {
		setAccelY( JUMP_POWER );
	}

	const int MOTION[ 4 ] = { 0, 1, 2, 1 };
	int u = MOTION[ ( getX( ) / WAIT_TIME ) % MAX_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, u, 1 );
}