#include "EnemyDeceasedSecond.h"

static const int WAIT_ANIME_TIME = 10;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;

EnemyDeceasedSecond::EnemyDeceasedSecond( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ) {
	setNoHead( );
}

EnemyDeceasedSecond::~EnemyDeceasedSecond( ) {
}

void EnemyDeceasedSecond::act( ) {
	const int MAX_ANIME_PATTERN = 5;
	const int ANIME_PATTERN_START = 5;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 ) + ANIME_PATTERN_START;
	setChipGraph( GRAPH_ENEMY_NOMAL, pattern, 13 );
}