#include "EnemyNoFace.h"

static const int WAIT_ANIME_TIME = 5;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int RANGE = 15;

EnemyNoFace::EnemyNoFace( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_anime_count( 0 ),
_vx( 0 ),
_dir( 1 ) {
}

EnemyNoFace::~EnemyNoFace( ) {
}

void EnemyNoFace::act( ) {
	_vx += _dir;
	setAccelX( _vx );

	if ( _vx < -RANGE ) {
		_dir = 1;
	}
	if ( _vx > RANGE ) {
		_dir = -1;
	}

	const int MOTION[ ] = { 6, 7, 8, 9, 8, 7, 6 };
	int pattern = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _anime_count / WAIT_ANIME_TIME ) % pattern ];
	_anime_count %= WAIT_ANIME_TIME * pattern;
	_anime_count++;

	setChipGraph( GRAPH_ENEMY_NORMAL, u, 1 );
}