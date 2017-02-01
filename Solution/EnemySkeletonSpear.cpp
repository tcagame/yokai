#include "EnemySkeletonSpear.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int MOVE_SPEED = 7;
static const int WAIT_ANIME_TIME = 14;

EnemySkeletonSpear::EnemySkeletonSpear( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
}

EnemySkeletonSpear::~EnemySkeletonSpear( ) {
}

void EnemySkeletonSpear::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	const int MAX_ANIME_PATTERN = 6;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 5, 6, 7, 8, 7, 6 };
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 14;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}