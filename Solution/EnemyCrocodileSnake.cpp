#include "EnemyCrocodileSnake.h"
#include "EnemyStock.h"
#include "EnemyFireball.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 4;
static const int POW = 6;
static const int MOVE_SPEED = 2;
static const int WAIT_ANIME_TIME = 15;

EnemyCrocodileSnake::EnemyCrocodileSnake( EnemyStockPtr stock, int x, int y, bool dir_right ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ),
_stock( stock ) {
	if ( dir_right ) {
		_move_speed *= -1;
	}
}


EnemyCrocodileSnake::~EnemyCrocodileSnake( ) {
}

void EnemyCrocodileSnake::act( ) {
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );

	actMove( );
	updateChip( );
	attack( );
}

void EnemyCrocodileSnake::actMove( ) {
	setAccelX( _move_speed );
}

void EnemyCrocodileSnake::updateChip( ) {
	const int MAX_ANIME_PATTERN = 8;
	int u = 4 + getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	int v = 8;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}

void EnemyCrocodileSnake::attack( ) {
	const int MAX_ANIME_PATTERN = 8;
	int attack_timing = getX( ) % ( ( WAIT_ANIME_TIME * MAX_ANIME_PATTERN ) * 2 );
	if ( attack_timing == 0 ) {
		int ajust_x = 50;
		bool dir_right = false;
		if ( getAccelX( ) < 0 ) {
			ajust_x *= -1;
			dir_right = true;
		}

		Vector pos = Vector( getX( ) + ajust_x, getY( ) - CHIP_SIZE / 4 );
		Vector vec = Vector( MOVE_SPEED * 5 / 2, 0 );
		_stock->addEnemy( EnemyPtr( new EnemyFireball( pos, vec, dir_right ) ) );
	}
}
