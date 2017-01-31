#include "EnemyRollOverNeckWoman.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 5;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 30;
static const int MOVE_SPEED = 12;

EnemyRollOverNeckWoman::EnemyRollOverNeckWoman( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyRollOverNeckWoman::~EnemyRollOverNeckWoman( ) {
}

void EnemyRollOverNeckWoman::act( ) {
	setAccelX( -MOVE_SPEED );
	const int ANIME[ ] = { 5, 7, 6, 7 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}

Vector EnemyRollOverNeckWoman::getOverlappedPos( ) const {
	return Vector( getX( ) - CHIP_SIZE / 3, getY( ) + CHIP_FOOT - CHIP_SIZE / 5 );
}

double EnemyRollOverNeckWoman::getOverlappedRadius( ) const {
	return CHIP_SIZE / 2 * 0.3;
}