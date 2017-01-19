#include "EnemyPurpleYokai.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;

EnemyPurpleYokai::EnemyPurpleYokai( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_PURPLE_YOKAI ) {
}


EnemyPurpleYokai::~EnemyPurpleYokai( ) {
}

void EnemyPurpleYokai::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MOTION[ 4 ] = { 0, 1, 2, 1 };
	int u = MOTION[ ( getX( ) / WAIT_TIME ) % MAX_PATTERN ];
	setChipUV( u, 0 );
}