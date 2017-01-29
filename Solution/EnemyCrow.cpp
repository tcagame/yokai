#include "EnemyCrow.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;
static const int IDLING_COUNT = 60;
static const int SPEED = 10;
static const int ATTACK_RANGE = 10;
static const int ANIMATION_WAIT_TIME = 6;

EnemyCrow::EnemyCrow( int x, int y, const Vector& target ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_pos( x, y ),
_target( target ) {
	_vec = _target - _pos;
	_vec.y = 0;
	_vec = _vec.normalize( ) * SPEED;
}

EnemyCrow::~EnemyCrow( ) {
}

void EnemyCrow::act( ) {
	_count++;
	
	if ( _vec.x > 0 ) {
		setChipReverse( true );
	} else {
		setChipReverse( false );
	}

	setChipGraph( GRAPH_ENEMY_NOMAL, _count / ANIMATION_WAIT_TIME % 2, 15 );

	if ( _count > IDLING_COUNT ) {
		Vector v = _target - _pos;
		_vec += v.normalize( ) * ( SPEED * 0.05 );
		_vec = _vec.normalize( ) * SPEED;
	}
	_pos += _vec;
	setX( ( int )_pos.x );
	setY( ( int )_pos.y );
}