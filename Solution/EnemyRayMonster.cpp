#include "EnemyRayMonster.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 5;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 2;
static const int MOVE_COUNT = 60;

EnemyRayMonster::EnemyRayMonster( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
	_revers = false;
}


EnemyRayMonster::~EnemyRayMonster( ) {
}

void EnemyRayMonster::act( ) {
	_count++;
	setAccelX( -MOVE_SPEED );
	if ( _count >= 150 ) {
		_revers = true;
	}
	if ( _revers ) {
			setAccelX( MOVE_SPEED );
	}
	const int ANIME[ ] = { 0, 1, 2, 3 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 6;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}