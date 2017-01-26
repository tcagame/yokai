#include "EnemyExtrudedSpirits.h"

static const int WAIT_ANIME_TIME = 6;
static const int MOVE_SPEED = 3;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyExtrudedSpirits::EnemyExtrudedSpirits( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_appears( false ) {
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
	setAccelX( -MOVE_SPEED );
}

void EnemyExtrudedSpirits::updateChip( ) {
	const int MAX_ANIME_PATTERN = 2;
	const int ANIME_PATTERN_START = 2;
	const int v = 4;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN + ANIME_PATTERN_START;
	setChipGraph( GRAPH_ENEMY_1, pattern, v );
}

void EnemyExtrudedSpirits::appearing( ) {
	const int v = 4;
	_count++;
	if ( _count < WAIT_ANIME_TIME ) {
		setChipGraph( GRAPH_ENEMY_1, 0, v );
	} else if ( _count < WAIT_ANIME_TIME * 2 ) {
		setChipGraph( GRAPH_ENEMY_1, 1, v );
	}

	if ( _count >= WAIT_ANIME_TIME * 2 ) {
		_count = 0;
		_appears = true;
	}
}