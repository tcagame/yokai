#include "EnemyWaterMonk.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 13;
static const int POW = 6;
static const int WAIT_ANIME_TIME  = 4;

EnemyWaterMonk::EnemyWaterMonk( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_in_water( false ) {
}


EnemyWaterMonk::~EnemyWaterMonk( ) {
}

void EnemyWaterMonk::act( ) {
	const int ANIME[ ] = { 0, 1, 2, 3, 4, 3, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	_over_lapped_pos = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	if ( _over_lapped_pos == 4 ) {
		_over_lapped_pos = 3;
	}
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );

	if ( u == 0 ) {
		_in_water = true;
	} else {
		_in_water = false;
	}
	_act_count++;
}

double EnemyWaterMonk::getOverlappedRadius( ) const {
	return CHIP_SIZE / 4 * 0.8;
}


Vector EnemyWaterMonk::getOverlappedPos( ) const {
	if ( _in_water ) {
		return Vector( );
	}
	return Vector( getX( ), getY( ) + CHIP_FOOT - ( CHIP_SIZE / 4 ) * _over_lapped_pos );
}
