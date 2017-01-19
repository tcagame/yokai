#include "EnemyRedbird.h"

static const int MAX_PATTERN = 5;
static const int MOVE_SPEED = 10;
static const int WAIT_PATTERN_TIME = 20;

EnemyRedbird::EnemyRedbird( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_REDBIRD, false ) {
}


EnemyRedbird::~EnemyRedbird( ) {
}

void EnemyRedbird::act( ) {
	actMove( );
	updateChip( );
}

void EnemyRedbird::actMove( ) {
	setAccelX( MOVE_SPEED );
}

void EnemyRedbird::updateChip( ) {
	int pattern = ( getX( ) / WAIT_PATTERN_TIME ) % MAX_PATTERN;
	setChipUV( pattern, 0 );
}

