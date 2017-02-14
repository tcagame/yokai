#include "EnemyAnimal.h"

static const int MOVE_SPEED = 8;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 0;
static const int RANGE = 80;

EnemyAnimal::EnemyAnimal( int x, int y, bool right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_act_count( 0 ) {
}

EnemyAnimal::~EnemyAnimal( ) {
}

void EnemyAnimal::act( ) {
	_act_count++;

	if ( getX( ) - RANGE > getTargetX( ) ) {
		setAccelX( _move_speed );
	} else if ( getX( ) + RANGE < getTargetX( ) ) {
		setAccelX( -_move_speed );
	} else {
		setAccelX( 0 );
	}

	const int MOTION[ ] = { 2, 3, 3, 3 };
	int anime_num = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _act_count / 10 ) % anime_num ];
	int v = 3;
	setChipGraph( GRAPH_ENEMY_ANIMAL, u, v );
}

void EnemyAnimal::damage( int pow ) {
}

Vector EnemyAnimal::getOverlappedPos( ) const {
	return Vector( -500, -500 );
}