#include "EnemyHellFire.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 10;

EnemyHellFire::EnemyHellFire( int x, int y, int hp ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, hp, POW ) {
	_count = 0;
}


EnemyHellFire::~EnemyHellFire( ) {
}


void EnemyHellFire::act( ) {
	_count++;

	Vector pos( getX( ), getY( ) );
	Vector target(
		getCameraX( ) + SCREEN_WIDTH / 2 + ( int )( sin( _count * PI / 150 ) * BG_SIZE + BG_SIZE / 2),
		BG_SIZE / 2 + ( int )( sin( _count * PI / 100 ) * BG_SIZE / 2 ) );
	Vector vec = target - pos;
	if ( vec.getLength( ) > MOVE_SPEED ) {
		vec = vec.normalize( ) * MOVE_SPEED;
	}

	setAccelX( ( int )vec.x );
	setAccelY( ( int )vec.y );

	const int ANIME[ 6 ] { 0, 1, 2, 3, 2, 1 };
	int u = 4 + ANIME[ _count / 4 % 6 ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}
