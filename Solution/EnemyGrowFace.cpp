#include "EnemyGrowFace.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 8;
static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyGrowFace::EnemyGrowFace( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
	_action = ACTION_GROW;
}


EnemyGrowFace::~EnemyGrowFace( ) {
}

void EnemyGrowFace::act( ) {
	switch( _action ) {
	case ACTION_GROW: {
		const int MAX_GROW_PATTERN = 6;
		const int GROW_PATTERN[ MAX_GROW_PATTERN ] = { 0, 1, 2, 3, 4 , 5};
		int pattern = GROW_PATTERN[ ( getX( ) / 2 ) % MAX_GROW_PATTERN ];
		setChipGraph( GRAPH_ENEMY_SMALL, pattern, 6 );
	}
		_action = ACTION_ATTACK;
		break;
	case ACTION_ATTACK:
		setAccelX( -MOVE_SPEED );
		const int MAX_ATTACK_PATTERN = 2;
		const int ATTACK_PATTERN[ MAX_ATTACK_PATTERN ] = { 6, 7 };
		int pattern = ATTACK_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ATTACK_PATTERN ];
		setChipGraph( GRAPH_ENEMY_SMALL, pattern, 5 );
		break;
	}
}
