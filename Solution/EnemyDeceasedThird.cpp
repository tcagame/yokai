#include "EnemyDeceasedThird.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;

EnemyDeceasedThird::EnemyDeceasedThird( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ) {
	setNoHead( );
}


EnemyDeceasedThird::~EnemyDeceasedThird( ) {
}

void EnemyDeceasedThird::act( ) {
	const int ANIM[ 8 ] = { 0, 1, 2, 1 };
	_count++;
	int pattern = ANIM[ _count / WAIT_ANIME_TIME % 4 ];
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 14 );
}

void EnemyDeceasedThird::damage( int pow ) {

}
