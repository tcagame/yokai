#include "EnemyFireball.h"

static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 8;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 1;

EnemyFireball::EnemyFireball( const Vector& pos, const Vector& vec ) :
Enemy( -CHIP_SIZE, -CHIP_SIZE, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_pos( pos ),
_vec( vec ) {
}


EnemyFireball::~EnemyFireball( ) {
}

void EnemyFireball::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 2;
	int u = getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 3;
	setChipGraph( GRAPH_ENEMY_EFFECT_JIZO, u, v );
}
