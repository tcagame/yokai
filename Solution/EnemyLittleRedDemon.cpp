#include "EnemyLittleRedDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;
static const int IDLING_COUNT = 60;
static const int SPEED = 5;
static const int WAIT_ANIME_TIME = 6;


EnemyLittleRedDemon::EnemyLittleRedDemon( EnemyStockPtr stock, int x, int y ) :
Enemy( stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}


EnemyLittleRedDemon::~EnemyLittleRedDemon( ) {
}

void EnemyLittleRedDemon::act( ) {
	setAccelX( -SPEED );

	const int MAX_ANIME_PATTERN = 5;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 );
	setChipGraph( GRAPH_ENEMY_MAP1, pattern, 0 );
}