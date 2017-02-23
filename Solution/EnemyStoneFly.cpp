#include "EnemyStoneFly.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const double SPEED = 10.0;

EnemyStoneFly::EnemyStoneFly( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_pos( x, y ),
_vec( 0, 0 ) {
}


EnemyStoneFly::~EnemyStoneFly( ) {
}

void EnemyStoneFly::act( ) {
	_count++;

	Vector pos( getX( ), getY( ) );
	Vector target(
		getCameraX( ) + SCREEN_WIDTH / 2 + ( int )( sin( _count * PI / 150 ) * BG_SIZE + BG_SIZE / 2),
		BG_SIZE / 2 + ( int )( sin( _count * PI / 100 ) * BG_SIZE / 2 ) );
	Vector vec = target - pos;
	if ( vec.getLength( ) > SPEED ) {
		vec = vec.normalize( ) * SPEED;
	}

	setAccelX( ( int )vec.x );
	setAccelY( ( int )vec.y );

	const int ANIME[ 6 ] { 0, 1, 2, 3, 2, 1 };
	int u =ANIME[ _count / 4 % 6 ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}