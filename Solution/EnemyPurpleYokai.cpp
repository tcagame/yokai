#include "EnemyPurpleYokai.h"

static const int SIZE = 204;
static const int FOOT = 0;
static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;

EnemyPurpleYokai::EnemyPurpleYokai( EnemyStockPtr enemy_stock, int x, int y, bool right ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY_PURPLE_YOKAI, SIZE, FOOT ),
_move_speed( MOVE_SPEED ) {
	if ( right ) {
		_move_speed *= -1;
	}
}


EnemyPurpleYokai::~EnemyPurpleYokai( ) {
}

void EnemyPurpleYokai::act( ) {
	setAccelX( -_move_speed );

	const int MOTION[ 4 ] = { 0, 1, 2, 1 };
	int u = MOTION[ ( getX( ) / WAIT_TIME ) % MAX_PATTERN ];
	setChipUV( u, 0 );
}