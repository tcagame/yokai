#include "EnemyPurpleYokai.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 20;

EnemyPurpleYokai::EnemyPurpleYokai( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_1 ) {
}


EnemyPurpleYokai::~EnemyPurpleYokai( ) {
}

void EnemyPurpleYokai::act( ) {
	actMove( );
}

void EnemyPurpleYokai::actMove( ) {
	setAccelX( -MOVE_SPEED );
	updateChip( );
}


void EnemyPurpleYokai::updateChip( ) {
	int pattern = ( getX( ) / WAIT_TIME ) % MAX_PATTERN;
	if ( pattern == MAX_PATTERN - 1 ) {
		pattern = 1;
	}
	setChipGraph( GRAPH( GRAPH_ENEMY_1 + pattern ) );
}