#include "EnemyBranchMonsterAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 3;
static const int MOVE_SPEED = 10;
static const int WAIT_ANIME_TIME = 3;
static const int JUMP_POWER = 40;

EnemyBranchMonsterAttack::EnemyBranchMonsterAttack(  int x, int y  ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_anime_count( 0 ) {
	setNoHead( );
}


EnemyBranchMonsterAttack::~EnemyBranchMonsterAttack( ) {
}

void EnemyBranchMonsterAttack::act( ) {
	_anime_count++;
	setAccelX( -MOVE_SPEED );
	if( isStanding( ) ) {
		setAccelY( -JUMP_POWER );
	}
		
	const int SEED_PATTERN[ ] = { 0, 1, 2 };
	int pattern_num = sizeof( SEED_PATTERN ) / sizeof( SEED_PATTERN[ 0 ] );
	int u = SEED_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_EFFECT_SMALL, u, 1 );
}