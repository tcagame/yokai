#include "EnemyBat.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int MOVE_SPEED = 2;
static const int WAIT_ANIME_TIME = 4;
static const int RANGE = 5;

EnemyBat::EnemyBat( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ),
_vy( 0 ),
_dir( 1 ){
}


EnemyBat::~EnemyBat( ) {
}

void EnemyBat::act( ) {
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

	const int ANIME[ ] = { 0, 1, 2, 3 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _anime_count / WAIT_ANIME_TIME % anime_num ];
	int v = 7;
	setChipGraph( GRAPH_ENEMY_SMALL, u, v );
}
