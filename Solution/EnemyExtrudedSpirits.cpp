#include "EnemyExtrudedSpirits.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int MOVE_SPEED_X = 10;
static const int MOVE_SPEED_Y = 4;

EnemyExtrudedSpirits::EnemyExtrudedSpirits( int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_appears( false ) {
	_move_speed = -MOVE_SPEED_X;
	if ( dir_right ) {
		_move_speed *= -1;
	}
}

EnemyExtrudedSpirits::~EnemyExtrudedSpirits( ) {
}

void EnemyExtrudedSpirits::act( ) {
	if ( _appears ) {
		actMove( );
		updateChip( );
	} else {
		appearing( );
	}
}

void EnemyExtrudedSpirits::actMove( ) {
	setAccelX( _move_speed );
	setAccelY( MOVE_SPEED_Y );
}

void EnemyExtrudedSpirits::updateChip( ) {
	const int MAX_ANIME_PATTERN = 2;
	const int ANIME_PATTERN_START = 2;
	const int v = 8;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN + ANIME_PATTERN_START;
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, v );
}

void EnemyExtrudedSpirits::appearing( ) {
	const int v = 8;
	_count++;
	if ( _count < WAIT_ANIME_TIME ) {
		setChipGraph( GRAPH_ENEMY_NORMAL, 0, v );
	} else if ( _count < WAIT_ANIME_TIME * 2 ) {
		setChipGraph( GRAPH_ENEMY_NORMAL, 1, v );
	}

	if ( _count >= WAIT_ANIME_TIME * 2 ) {
		_count = 0;
		_appears = true;
	}
}