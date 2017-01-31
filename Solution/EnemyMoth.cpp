#include "EnemyMoth.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 2;
static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;
static const int RANGE = 7;

EnemyMoth::EnemyMoth( int x, int y ) :
Enemy( x, y - 30, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ),
_vy( 0 ),
_dir( 1 ) {
}


EnemyMoth::~EnemyMoth( ) {
}

void EnemyMoth::act( ) {
	_anime_count++;
	setAccelY( MOVE_SPEED );
	
	_vy += _dir;
	setAccelY( _vy );

	if ( _vy < -RANGE ) {
		_dir = 1;
	}
	if ( _vy > RANGE ) {
		_dir = -1;
	}


	const int MAX_ANIME_PATTERN = 2;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 1 );
}
