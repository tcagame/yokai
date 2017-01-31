#include "EnemyShishimai.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 2;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 6;
static const int WAIT_RETURN_TIME = 100;
static const int JUMP_POWER = -40;

EnemyShishimai::EnemyShishimai( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_move_speed( MOVE_SPEED ),
_old_x( 0 ),
_old_y( 0 ) {
}


EnemyShishimai::~EnemyShishimai( ) {
}

void EnemyShishimai::act( ) {
	
	const int MOTION[ ] = { 8, 9, 10, 11 };
	int pattern = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _act_count / WAIT_ANIME_TIME ) % pattern ];
	
	if ( _act_count % WAIT_RETURN_TIME == 0 ) {
		_move_speed *= -2;
	}
	setAccelX( _move_speed );
	
	if ( _old_x == getX( ) &&
		 _old_y == getY( ) ) {
		setAccelY( JUMP_POWER );
		_act_count = 0;
	}


	setChipGraph( GRAPH_ENEMY_NORMAL, u, 12 );
	_old_x = getX( );
	_old_y = getY( );
	_act_count++;
}