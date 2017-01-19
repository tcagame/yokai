#include "EnemyPurpleYokai.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 20;

EnemyPurpleYokai::EnemyPurpleYokai( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_PURPLE_YOKAI ) {
}


EnemyPurpleYokai::~EnemyPurpleYokai( ) {
}

void EnemyPurpleYokai::act( ) {
	actMove( );
	updateChip( );
}

void EnemyPurpleYokai::actMove( ) {
	setAccelX( -MOVE_SPEED );
}


void EnemyPurpleYokai::updateChip( ) {
	int pattern = ( getX( ) / WAIT_TIME ) % MAX_PATTERN;
	if ( pattern == MAX_PATTERN - 1 ) {
		pattern = 1;
	}
}