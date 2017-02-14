#include "EnemyStoneRote.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 999;
static const int POW = 2;
static const int WAIT_ANIME_TIME = 4;
static const int MOVE_SPEED = 6;

EnemyStoneRote::EnemyStoneRote(int x, int y, bool right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ){
	if( right ) {
		_move_speed *= -1;
	}
}


EnemyStoneRote::~EnemyStoneRote( ) {
}

void EnemyStoneRote::act( ) {

	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );
	setAccelX( _move_speed );

	const int MAX_ANIME_PATTERN = 8;
	_act_count++;
	_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _act_count / WAIT_ANIME_TIME;
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 6 );
}
