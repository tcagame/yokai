#include "EnemyBranchMonster.h"
#include "EnemyBranchMonsterAttack.h"

static const int WAIT_ANIME_TIME = 5;
static const int MOVE_SPEED = 8;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 6;
static const int POW = 1;
static const int ATTACK_FOOT = 50;
static const int CREATE_COUNT_BRANCH = 60;

EnemyBranchMonster::EnemyBranchMonster( EnemyStockPtr stock,int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_stock( stock ),
_anime_count( 0 ) {
	_action = ACTION_GROW;
	focus( );
}


EnemyBranchMonster::~EnemyBranchMonster( ) {
}

void EnemyBranchMonster::act( ) {
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

void EnemyBranchMonster::actGrow( ) {
	const int GROW_PATTERN[ ] = { 0, 1 };
	int pattern_num = sizeof( GROW_PATTERN ) / sizeof( GROW_PATTERN[ 0 ] );
	int u = GROW_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_TREE_MONSTER_ITEM, u, 0 );
	if( u == 1 ) {
		_action = ACTION_ATTACK;
	}
}
void EnemyBranchMonster::actAttack( ) {
	const int ANIME[ ] = { 3, 4, 0, 1, 2, 4 , 5 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _anime_count / WAIT_ANIME_TIME % anime_num ];
	int v = 1;
	if ( u == 1 ) {
		if ( _anime_count % WAIT_ANIME_TIME == 1 ) {
			_stock->addEnemy( EnemyPtr( new EnemyBranchMonsterAttack( getX( ) - 40, getY( ) - ATTACK_FOOT ) ) );
		}
	}
	setChipGraph( GRAPH_ENEMY_TREE_MONSTER_ITEM, u, v );
	if( u == 5 ) {
		setY( -200 );
	}
}