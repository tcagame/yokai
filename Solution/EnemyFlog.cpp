#include "EnemyFlog.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 10;
static const int WAIT_ANIME_TIME = 10;

EnemyFlog::EnemyFlog( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::act( ) {
	updateChip( );
}

void EnemyFlog::updateChip( ) {
	const int WIDTH_NUM = 3;
	const int MAX_ANIME_PATTERN = 8;
	int u = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN % WIDTH_NUM;
	int v = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN / WIDTH_NUM;
	setChipGraph( GRAPH_ENEMY_FLOG, u, v );
}