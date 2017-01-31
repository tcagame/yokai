#include "EnemyGrowFace.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 12;
static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
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
	const int PATTERN_NUM = 6;
	const int GROW_PATTERN[ PATTERN_NUM ] = { 0, 1, 2, 3, 4, 5 };
	int pattern = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) ];
	if( pattern == 5 ) {
		_action = ACTION_ATTACK;
	}
	int u = pattern % 4;
	int v = pattern / 4;
	setChipGraph( GRAPH_ENEMY_TREE_ITEM, u, v );
}

void EnemyGrowFace::actAttack( ) {
	setAccelX( -MOVE_SPEED );
	setAccelY( MOVE_SPEED );
	
	const int PATTERN_NUM = 6;
	const int GROW_PATTERN[ PATTERN_NUM ] = { 6, 6, 6, 7, 7, 7 };
	int pattern = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % PATTERN_NUM ];
	if ( pattern == 7 ) {
		setAccelY( -MOVE_SPEED );
	}
	int u = pattern % 4;
	int v = pattern / 4;
	setChipGraph( GRAPH_ENEMY_TREE_ITEM, u, v );
}
