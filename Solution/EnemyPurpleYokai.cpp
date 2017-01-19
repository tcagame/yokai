#include "EnemyPurpleYokai.h"

static const int SIZE = 204;
static const int FOOT = 0;
static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;

EnemyPurpleYokai::EnemyPurpleYokai( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY_PURPLE_YOKAI, SIZE, FOOT ) {
}


EnemyPurpleYokai::~EnemyPurpleYokai( ) {
}

void EnemyPurpleYokai::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MOTION[ 4 ] = { 0, 1, 2, 1 };
	int u = MOTION[ ( getX( ) / WAIT_TIME ) % MAX_PATTERN ];
	setChipUV( u, 0 );
}