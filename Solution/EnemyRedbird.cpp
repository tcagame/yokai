#include "EnemyRedbird.h"
#include "smart_ptr.h"

static const int MAX_PATTERN = 5;
static const int MOVE_SPEED = 10;
static const int WAIT_PATTERN_TIME = 20;
static const int WAIT_ATTACK_TIME = 60;

EnemyRedbird::EnemyRedbird( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_REDBIRD, false ),
_attack_count( 0 ),
_accel( 0 ) {
}


EnemyRedbird::~EnemyRedbird( ) {
}

void EnemyRedbird::act( ) {
	actMove( );
	actAttack( );
	updateChip( );
}

void EnemyRedbird::actMove( ) {
	setAccelX( MOVE_SPEED );
}

void EnemyRedbird::actAttack( ) {
	_attack_count %= WAIT_ATTACK_TIME;
	if ( _attack_count == 0 ) {
		
	}
	_attack_count++;
}

void EnemyRedbird::updateChip( ) {
	int pattern = ( getX( ) / WAIT_PATTERN_TIME ) % MAX_PATTERN;
	setChipUV( pattern, 0 );
}