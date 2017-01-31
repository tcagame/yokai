#include "EnemyStoneMortgage.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int MOVE_SPEED = 20;
static const int HP = 99;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 3;

EnemyStoneMortgage::EnemyStoneMortgage( int x, int y, int type ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_moveing( false ),
_start_x( x ),
_start_y( y ),
_type( type ),
_count( 0 ) {
	if ( rand( ) % 2 ) {
		_move_speed = MOVE_SPEED;
	} else {
		_move_speed = -MOVE_SPEED;
	}
}

EnemyStoneMortgage::~EnemyStoneMortgage( ) {
}

void EnemyStoneMortgage::act( ) {
	if ( _moveing ) {
	}
	actMove( );
	updateChip( );
}

void EnemyStoneMortgage::setMove( bool moveing ) {
	_moveing = moveing;
}

void EnemyStoneMortgage::actMove( ) {
	setAccelX( MOVE_SPEED );
	if ( _count >= 10 ) {
		setAccelX( -MOVE_SPEED );
	}
	_count++;
	_count %= 20;
}

void EnemyStoneMortgage::updateChip( ) {
	int u = _type % 2 * 4 + _count / WAIT_ANIME_TIME % 4;
	int v = 4 + _type / 2;
	setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );
}
