#include "EnemyMiasmaGray.h"
#include "Drawer.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 1;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int RANGE = 10;

EnemyMiasmaGray::EnemyMiasmaGray( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ), 
_vy( 0 ),
_dir( 1 ) {
}

EnemyMiasmaGray::~EnemyMiasmaGray( ) {
}

void EnemyMiasmaGray::act( ) {
	_anime_count++;
	setAccelX( -MOVE_SPEED );
	setAccelY( MOVE_SPEED );
	
	_vy += _dir;
	setAccelY( _vy );

	if ( _vy < -RANGE ) {
		_dir = 1;
	}
	if ( _vy > RANGE ) {
		_dir = -1;
	}

	const int MAX_ANIME_PATTERN = 4;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 7 );
}
