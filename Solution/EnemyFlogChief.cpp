#include "EnemyFlogChief.h"

static const int WAIT_ANIME_TIME = 3;
static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyFlogChief::EnemyFlogChief(int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_anime_count( 0 ) {
}

EnemyFlogChief::~EnemyFlogChief( ) {
}

void EnemyFlogChief::act( ) {
	setChipGraph( GRAPH_ENEMY_FLOG_RED, 0, 0 );
}