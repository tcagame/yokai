#include "EnemyLittleBlueDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 4;
static const int SPEED = 5;
static const int JUMP_POW = 25;
static const int WAIT_ANIME_TIME = 6;

EnemyLittleBlueDemon::EnemyLittleBlueDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}

EnemyLittleBlueDemon::~EnemyLittleBlueDemon( ) {
}

void EnemyLittleBlueDemon::act( ) {
	setAccelX( -SPEED );
	if ( isStanding( ) ) {
		setAccelY( - rand( ) % JUMP_POW );
	}

	_count++;
	const int ANIM[ 4 ] = { 4, 5, 8, 9 };
	int pattern = ANIM[ _count / WAIT_ANIME_TIME % 4 ];
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 6 );
}