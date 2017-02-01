#include "EnemyLittleRedDemon.h"

static const int MOVE_SPEED = 5;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;
static const int IDLING_COUNT = 60;
static const int SPEED = 5;
static const int WAIT_ANIME_TIME = 6;


EnemyLittleRedDemon::EnemyLittleRedDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
}


EnemyLittleRedDemon::~EnemyLittleRedDemon( ) {
}

void EnemyLittleRedDemon::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );
	_count++;

	const int ANIM[ 4 ] = { 1, 2, 2, 3 };
	int u = ANIM[ _count / WAIT_ANIME_TIME % 4 ];
	int v = ( _count / WAIT_ANIME_TIME % 4 ) % 2 + 2;
	setChipGraph( GRAPH_ENEMY_BOSS, u, v );
}