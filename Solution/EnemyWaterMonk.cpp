#include "EnemyWaterMonk.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int WAIT_ANIME_TIME  = 10;

EnemyWaterMonk::EnemyWaterMonk( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ) {
}


EnemyWaterMonk::~EnemyWaterMonk( ) {
}

void EnemyWaterMonk::act( ) {
	updateChip( );
}

void EnemyWaterMonk::updateChip( ) {
	const int MAX_ANIME_PATTERN = 16;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 0, 1, 2, 3, 4, 5, 4, 5, 4, 5, 4, 3, 2, 1, 0, 0 };
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_COMMON_BIG, u, v );
}
