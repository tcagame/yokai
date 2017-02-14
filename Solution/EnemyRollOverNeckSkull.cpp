#include "EnemyRollOverNeckSkull.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 5;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 10;
static const int MOVE_SPEED = 2;

EnemyRollOverNeckSkull::EnemyRollOverNeckSkull( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyRollOverNeckSkull::~EnemyRollOverNeckSkull( ) {
}

void EnemyRollOverNeckSkull::act( ) {
	setAccelX( -MOVE_SPEED );
	const int ANIME[ ] = { 4, 6, 5, 7 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 6;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}

Vector EnemyRollOverNeckSkull::getOverlappedPos( ) const {
	return Vector( getX( ) - CHIP_SIZE / 5, getY( ) + CHIP_FOOT - CHIP_SIZE / 10 );
}

double EnemyRollOverNeckSkull::getOverlappedRadius( ) const {
	return CHIP_SIZE / 2 * 0.4;
}