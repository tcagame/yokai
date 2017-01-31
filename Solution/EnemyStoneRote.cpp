#include "EnemyStoneRote.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 4;
static const int MOVE_SPEED = 10;

EnemyStoneRote::EnemyStoneRote(int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyStoneRote::~EnemyStoneRote( ) {
}

void EnemyStoneRote::act( ) {
	setAccelX( -MOVE_SPEED );

	const int MAX_ANIME_PATTERN = 8;
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _act_count / WAIT_ANIME_TIME;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 6 );
}
