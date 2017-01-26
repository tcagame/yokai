#include "EnemyGhostWater.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;

EnemyGhostWater::EnemyGhostWater( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ) {
}


EnemyGhostWater::~EnemyGhostWater( ) {
}

void EnemyGhostWater::act( ) {
	updateChip( );
}

void EnemyGhostWater::updateChip( ) {
	const int MAX_ANIME_PATTERN = 15;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 0, 1, 2, 3, 4, 3, 4, 3, 4, 3, 4, 5, 6 , 0 , 0 };
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 9;
	setChipGraph( GRAPH_ENEMY_COMMON, u, v );
}