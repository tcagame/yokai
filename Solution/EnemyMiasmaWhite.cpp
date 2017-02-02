#include "EnemyMiasmaWhite.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int MOVE_SPEED = 3;
static const int WAIT_ANIME_TIME = 6;
static const int RANGE = 10;

EnemyMiasmaWhite::EnemyMiasmaWhite( int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_move_speed( -MOVE_SPEED ),
_vy( 0 ),
_dir( 1 ){
	if ( dir_right ) {
		_move_speed *= -1;
	}
}


EnemyMiasmaWhite::~EnemyMiasmaWhite( ) {
}

void EnemyMiasmaWhite::act( ) {
	setAccelX( _move_speed );
	setAccelY( MOVE_SPEED );
	
	_vy += _dir;
	setAccelY( _vy );

	if ( _vy < -RANGE ) {
		_dir = 1;
	}
	if ( _vy > RANGE ) {
		_dir = -1;
	}

	const int MAX_ANIME_PATTERN = 4;
	int u = getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 6;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}
