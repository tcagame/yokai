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
	const int ANIM[ 8 ] = { 5, 6, 7, 8, 9, 8, 7, 6 };
	_count++;
	int pattern = ANIM[ _count / WAIT_ANIME_TIME % 8 ];
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 13 );
}

void EnemyDeceasedSecond::damage( int pow ) {

}