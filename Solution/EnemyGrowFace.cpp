#include "EnemyGrowFace.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 12;
static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 3;
static const int JUMP_POWER = 40;

EnemyGrowFace::EnemyGrowFace( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
	_action = ACTION_GROW;
}


EnemyGrowFace::~EnemyGrowFace( ) {
}

void EnemyGrowFace::act( ) {
	_anime_count++;
	switch( _action ) {
	case ACTION_GROW: 
		actGrow( );
		break;
	case ACTION_ATTACK:
		actAttack( );
		break;
	}
}

void EnemyGrowFace::actGrow( ) {
	const int GROW_PATTERN[ ] = { 0, 1, 2, 3, 4, 5 };
	int pattern_num = sizeof( GROW_PATTERN ) / sizeof( GROW_PATTERN[ 0 ] );
	int u = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_SMALL, u, 3 );
	if( u == 5 ) {
		_action = ACTION_ATTACK;
	}
}

void EnemyGrowFace::actAttack( ) {
	setAccelX( -MOVE_SPEED );
	setAccelY( MOVE_SPEED );

	const int GROW_PATTERN[ ] = { 6, 6, 6, 7, 7, 7 };
	int pattern_num = sizeof( GROW_PATTERN ) / sizeof( GROW_PATTERN[ 0 ] );
	int u = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_SMALL, u, 3 );
	if ( u == 7 ) {
		setAccelY( -MOVE_SPEED );
	}
}
