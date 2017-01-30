#include "EnemyBranchMonsterAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 2;
static const int MOVE_SPEED = 20;
static const int WAIT_ANIME_TIME = 3;

EnemyBranchMonsterAttack::EnemyBranchMonsterAttack(  int x, int y  ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ){
}


EnemyBranchMonsterAttack::~EnemyBranchMonsterAttack( ) {
}

void EnemyBranchMonsterAttack::act( ) {
	_anime_count++;
	setAccelX( -MOVE_SPEED );
	const int SEED_PATTERN[ ] = { 0, 1, 2 };
	int pattern_num = sizeof( SEED_PATTERN ) / sizeof( SEED_PATTERN[ 0 ] );
	int u = SEED_PATTERN[ ( _anime_count / WAIT_ANIME_TIME ) % pattern_num ];
	setChipGraph( GRAPH_ENEMY_EFFECT_SMALL, u, 1 );
}