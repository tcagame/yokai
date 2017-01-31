#include "EnemyDeceasedGreen.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 3;

EnemyDeceasedGreen::EnemyDeceasedGreen( int x, int y, bool right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( MOVE_SPEED ) {
	if ( right ) {
		_move_speed *= -1;
	}
}


EnemyDeceasedGreen::~EnemyDeceasedGreen( ) {
}

void EnemyDeceasedGreen::act( ) {
	setAccelX( -_move_speed );

	const int MOTION[ 4 ] = { 0, 1, 2, 1 };
	int u = MOTION[ ( getX( ) / WAIT_TIME ) % MAX_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, u, 1 );
}