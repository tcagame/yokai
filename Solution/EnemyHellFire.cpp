#include "EnemyHellFire.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 4;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 10;

EnemyHellFire::EnemyHellFire( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
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
	Vector vec = ( target - pos ).normalize( ) * MOVE_SPEED;

	setAccelX( ( int )vec.x );
	setAccelY( ( int )vec.y );

	const int ANIME[ ] { 4, 5, 6, 5, 7, 4, 7 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}
