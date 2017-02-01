#include "EnemyWaterGhost.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 5;

EnemyWaterGhost::EnemyWaterGhost( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_in_water( true ){
}


EnemyWaterGhost::~EnemyWaterGhost( ) {
}

void EnemyWaterGhost::act( ) {

	const int MAX_ANIME_PATTERN = 15;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 0, 1, 2, 3, 4, 3, 4, 3, 4, 3, 4, 5, 6 , 0 , 0 };
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 9;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );

	if( u == 0 || u == 6 ) {
		_in_water = true;
	} else {
		_in_water = false;
	}
}

Vector EnemyWaterGhost::getOverlappedPos( ) const {
	if ( _in_water ) {
		return Vector( );
	}
	return Vector( getX( ), getY( ) + CHIP_FOOT - CHIP_SIZE / 2 );
}
