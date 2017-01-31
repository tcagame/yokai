#include "EnemyOnyudo.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 6;
static const int POW = 6;
static const int MOVE_SPEED = 3;
static const int WAIT_ANIME_TIME = 20;

EnemyOnyudo::EnemyOnyudo( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyOnyudo::~EnemyOnyudo( ) {
}

void EnemyOnyudo::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 4;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 0, 1, 2, 1 };
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 0;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}
