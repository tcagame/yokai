#include "EnemyGhost.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;
static const int IDLING_COUNT = 60;
static const int SPEED = 5;

EnemyGhost::EnemyGhost( EnemyStockPtr stock , int x, int y, const Vector& target ) : 
Enemy( stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_target( target ) {
	if ( rand( ) % 2 == 0 ) {
		setChipReverse( true );
	} else {
		setChipReverse( false );
	}
}

EnemyGhost::~EnemyGhost( ) {
}

void EnemyGhost::act( ) {
	_count++;
	
	setChipGraph( GRAPH_ENEMY_COMMON, 2 + _count / 2 % 2, 3 );

	if ( _count < IDLING_COUNT ) {
		if ( isChipReverse( ) ) {
			setAccelX( SPEED );
			_vec.x = SPEED;
		} else {
			setAccelX( -SPEED );
			_vec.x = -SPEED;
		}
	} else {
		Vector pos( getX( ), getY( ) );
		Vector v = _target - pos;
		_vec += v.normalize( ) * ( SPEED * 0.5 );
		_vec = _vec.normalize( ) * SPEED;

		setAccelX( ( int )_vec.x );
		setAccelY( ( int )_vec.y );
	}
}
/*
*/