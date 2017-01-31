#include "EnemyFire.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 6;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 1;

EnemyFire::EnemyFire( const Vector& pos, const Vector& vec ) : 
Enemy( ( int )pos.x, ( int )pos.y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_pos( pos ),
_vec( vec ) {
	setNoHead( );
}


EnemyFire::~EnemyFire( ) {
}

void EnemyFire::act( ) {
	_pos += _vec;

	setX( ( int )_pos.x );
	setY( ( int )_pos.y );

	Vector up( 0, -1 );
	double angle = up.angle( _vec );
	if ( up.cross( _vec ).z < 0 ) {
		angle = PI2 - angle;
	}
	int n = ( int )( angle / ( PI2 / 16 ) );
	const int MAX_ANIME_PATTERN = 2;
	int u = n % 4;
	int v = n / 4;
	setChipGraph( GRAPH_ENEMY_FIREBALL, u, v );
}