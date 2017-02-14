#include "EnemyAnimal.h"

static const int MOVE_SPEED = 5;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 0;

EnemyAnimal::EnemyAnimal( int x, int y, bool right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}

EnemyAnimal::~EnemyAnimal( ) {
}

void EnemyAnimal::act( ) {
	//const int MOTION[ 4 ] = { 3, 4, 5, 4 };
	// int u = MOTION[ ( _act_count / WAIT_TIME ) % MAX_PATTERN ];
	setChipGraph( GRAPH_ENEMY_ANIMAL, 1, 1 );
}

void EnemyAnimal::damage( int pow ) {
}

Vector EnemyAnimal::getOverlappedPos( ) const {
	return Vector( -100, -100 );
}