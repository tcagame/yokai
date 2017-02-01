#include "EnemyGhost.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 2;
static const int IDLING_COUNT = 60;
static const int SPEED = 5;

//target‚¢‚ç‚È‚¢
EnemyGhost::EnemyGhost( int x, int y ) : 
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_pos( x, y ) {
	_vec = Vector( getCameraX( ) + SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 ) - _pos;
	_vec.y = 0;
	_vec = _vec.normalize( ) * SPEED;
	setNoHead( );
}

EnemyGhost::~EnemyGhost( ) {
}

void EnemyGhost::act( ) {
	_count++;
	Vector target = Vector( getCameraX( ) + SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );

	if ( _vec.x > 0 ) {
		setChipReverse( true );
	} else {
		setChipReverse( false );
	}

	if ( _count / 2 < 3 ) {
		setChipGraph( GRAPH_ENEMY_NORMAL, _count / 2, 3 );
	} else {
		setChipGraph( GRAPH_ENEMY_NORMAL, 2 + _count / 2 % 2, 3 );
	}

	if ( _count > IDLING_COUNT ) {
		Vector v = target - _pos;
		_vec += v.normalize( ) * ( SPEED * 0.05 );
		_vec = _vec.normalize( ) * SPEED;
	}
	_pos += _vec;
	setX( ( int )_pos.x );
	setY( ( int )_pos.y );
}
