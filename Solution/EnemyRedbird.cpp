#include "EnemyRedbird.h"

static const int MAX_PATTERN = 7;
static const int MOVE_SPEED = 10;

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

}

