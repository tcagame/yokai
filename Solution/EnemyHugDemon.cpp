#include "EnemyHugDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 10;
static const int JUMP_POWER = -40;

EnemyHugDemon::EnemyHugDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_old_x( 0 ),
_old_y( 0 ) {
}


EnemyHugDemon::~EnemyHugDemon( ) {
}

void EnemyHugDemon::act( ) {
	actMove( );
	updateChip( );
	_old_x = getX( );
	_old_y = getY( );
}

void EnemyHugDemon::actMove( ) {
	setAccelX( -MOVE_SPEED );
	if ( _old_x == getX( ) &&
		 _old_y == getY( ) ) {
		setAccelY( JUMP_POWER );
	}
}

void EnemyHugDemon::updateChip( ) {
	const int WALK_ANIME[ ] = { 4, 5, 6, 5 };
	int max_walk_anime =  sizeof( WALK_ANIME ) / sizeof( WALK_ANIME[ 0 ] );
	int u = WALK_ANIME[ getX( ) / WAIT_ANIME_TIME % max_walk_anime ];
	int v = 7;
	setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
}