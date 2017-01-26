#include "EnemySkeletonSpear.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 14;

EnemySkeletonSpear::EnemySkeletonSpear( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemySkeletonSpear::~EnemySkeletonSpear( ) {
}

void EnemySkeletonSpear::act( ) {
	actMove( );
	updateChip( );
}

void EnemySkeletonSpear::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemySkeletonSpear::updateChip( ) {
	const int MAX_ANIME_PATTERN = 6;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 0, 1, 2, 3, 2, 1 };
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 15;
	setChipGraph( GRAPH_ENEMY_COMMON, u, v );
}