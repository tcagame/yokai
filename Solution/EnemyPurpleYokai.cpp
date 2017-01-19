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
	actMove( );
	updateChip( );
}

void EnemyPurpleYokai::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyPurpleYokai::updateChip( ) {
	int pattern = ( getX( ) / WAIT_TIME ) % MAX_PATTERN;

	switch( pattern ) {
	case 0:
		setChipUV( 0, 0 );
		break;
	case 1:
		setChipUV( 1, 0 );
		break;
	case 2:
		setChipUV( 2, 0 );
		break;
	case 3:
		setChipUV( 1, 0 );
		break;
	}
}