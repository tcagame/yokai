#include "EnemyStoneMortgage.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int MOVE_SPEED = 20;
static const int HP = 20;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 3;

EnemyStoneMortgage::EnemyStoneMortgage( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_moveing( false ),
_back( false ),
_start_x( x ),
_start_y( y ),
_count( 0 ) {
}

EnemyStoneMortgage::~EnemyStoneMortgage( ) {
}

void EnemyStoneMortgage::act( ) {
	if ( _moveing ) {
		actMove( );
	} else {
		actStop( );
	}
	updateChip( );
}

void EnemyStoneMortgage::setMove( bool moveing ) {
	_moveing = moveing;
}

void EnemyStoneMortgage::actMove( ) {
	setAccelX( MOVE_SPEED );
	if ( _back ) {
		setAccelX( -MOVE_SPEED );
	}
	_count++;
}

void EnemyStoneMortgage::actStop( ) {
	_count = 0;
	_back = false;
	setAccelX( 0 );
	setAccelY( 0 );
	setX( _start_x );
	setY( _start_y );
}

void EnemyStoneMortgage::updateChip( ) {
	const int ANIME[ ] = { 0, 1, 2, 3 };
	const int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _count / WAIT_ANIME_TIME % anime_num ];

	setChipGraph( GRAPH_ENEMY_EFFECT_SMALL, u, 3 );
}

void EnemyStoneMortgage::back( ) {
	_back = true;
}