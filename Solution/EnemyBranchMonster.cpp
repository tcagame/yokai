#include "EnemyBranchMonster.h"

static const int WAIT_ANIME_TIME = 5;
static const int MOVE_SPEED = 8;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyBranchMonster::EnemyBranchMonster( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
	setAccelX( 1 );
	_action = ACTION_GROW;
}


EnemyBranchMonster::~EnemyBranchMonster( ) {
}

void EnemyBranchMonster::act( ) {
	_anime_count++;
	switch( _action ) {
	case ACTION_GROW: 
		actGrow( );
		break;
	}
	setAccelX( 0 );
}

void EnemyBranchMonster::actGrow( ) {
	const int GROW_PATTERN[ ] = { 0, 1, 2, 3 };
	int pattern_num = sizeof( GROW_PATTERN ) / sizeof( GROW_PATTERN[ 0 ] );
	int u = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_NOMAL, u, 2 );
	if( u == 4 ) {
		_action = ACTION_ATTACK;
	}
}