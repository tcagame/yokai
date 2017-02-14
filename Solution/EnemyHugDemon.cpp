#include "EnemyHugDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 4;
static const int JUMP_POWER = -40;

EnemyHugDemon::EnemyHugDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_old_x( 0 ),
_old_y( 0 ),
_act_count( 0 ) {
}


EnemyHugDemon::~EnemyHugDemon( ) {
}

void EnemyHugDemon::act( ) {
	actMove( );
	updateChip( );
	_old_x = getX( );
	_old_y = getY( );
	_act_count++;
}

void EnemyHugDemon::actMove( ) {
	setAccelX( -MOVE_SPEED );
	if ( _old_x == getX( ) &&
		 _old_y == getY( ) ) {
		setAccelY( JUMP_POWER );
		_act_count = 0;
	}
	if ( isStanding( ) && getTargetY( ) < getY( ) ) {
		setAccelY( JUMP_POWER );
	}
}

void EnemyHugDemon::updateChip( ) {
	int u = 0;
	int v = 7;
	int y = getY( );
	if ( _old_y == y ) {
		const int ANIME[ ] = { 4, 5, 6, 5 };
		int max_anime =  sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
		u = ANIME[ _act_count / WAIT_ANIME_TIME % max_anime ];
	}
	if ( _old_y != y ) {
		const int ANIME[ ] = { 7, 8, 9, 10 };
		int max_anime =  sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
		u = ANIME[ _act_count / WAIT_ANIME_TIME % max_anime ];
	}
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}