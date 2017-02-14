#include "EnemyNoNeckGhost.h"

static const int MOVE_SPEED = 10;
static const int WAIT_ANIME_TIME = 40;
static const int WAIT_ATTACK_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int REVERS_TIME = 80;
static const int RANGE = 5;

EnemyNoNeckGhost::EnemyNoNeckGhost( int x, int y ):
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_speed( -10 ),
_vy( 0 ),
_dir( 1 ) {

}


EnemyNoNeckGhost::~EnemyNoNeckGhost( ) {
}

void EnemyNoNeckGhost::act( ) {
	_count++;
	if ( _count % REVERS_TIME == 0 ) {
		_speed *= -1;
	}
	setAccelX( _speed );
	setAccelY( MOVE_SPEED );
	
	_vy += _dir;
	setAccelY( _vy );

	if ( _vy < -RANGE ) {
		_dir = 1;
	}
	if ( _vy > RANGE ) {
		_dir = -1;
	}

	const int MAX_ATTACK_PATTERN = 4;
	const int ATTACK_PATTERN[ MAX_ATTACK_PATTERN ] = { 4, 5, 6, 7 };
	int pattern = ATTACK_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ATTACK_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 11 );
}
