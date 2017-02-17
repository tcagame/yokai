#include "EnemyRayMonster.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 4;
static const int MOVE_COUNT = 60;
static const int REVERS_TIME = 110;

EnemyRayMonster::EnemyRayMonster( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_speed( -MOVE_SPEED ){
	_revers = false;
}


EnemyRayMonster::~EnemyRayMonster( ) {
}

void EnemyRayMonster::act( ) {
	_count++;
	if ( _count % REVERS_TIME == 0 ) {
		_speed *= -1;
	}
	setAccelX( _speed );

	const int ANIME[ ] = { 0, 1, 2, 3 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 6;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}

Vector EnemyRayMonster::getOverlappedPos( ) const {
	Vector pos( getX( ) - CHIP_SIZE / 5, getY( ) + CHIP_FOOT - CHIP_SIZE / 10 );
	if ( isChipReverse( ) ) {
		pos += Vector( 150, 0 );
	}
	return pos;
}

double EnemyRayMonster::getOverlappedRadius( ) const {
	return CHIP_SIZE / 2 * 0.3;
}