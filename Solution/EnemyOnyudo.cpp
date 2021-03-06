#include "EnemyOnyudo.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 8;
static const int POW = 6;
static const int MOVE_SPEED = 3;
static const int WAIT_ANIME_TIME = 20;
static const int WAIT_DAMAGE_TIME = 5;

EnemyOnyudo::EnemyOnyudo( int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ),
_before_hp( HP ),
_damage_count( 0 ) {
	if ( dir_right ) {
		_move_speed *= -1;
	}
}


EnemyOnyudo::~EnemyOnyudo( ) {
}

void EnemyOnyudo::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	const int ANIME[ ] = { 0, 1, 2, 3, 2, 1 };
	int anime = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime ];
	int v = 0;
	if ( _before_hp != getHp( ) || _damage_count > 0 ) {
		u = 4;
		_damage_count++;
	}
	if ( _damage_count > WAIT_DAMAGE_TIME ) {
		_damage_count = 0;
	}

	_before_hp = getHp( );
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
}
