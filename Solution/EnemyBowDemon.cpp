#include "EnemyBowDemon.h"
#include "EnemyBowDemonAttack.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 8;
static const int ATTACK_FOOT = 30;

EnemyBowDemon::EnemyBowDemon( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_stock( enemy_stock ),
_act_count( 0 ) {
}


EnemyBowDemon::~EnemyBowDemon( ) {
}

void EnemyBowDemon::act( ) {
	setAccelX( -MOVE_SPEED );

	const int ANIME[ ] = { 7, 8, 9, 8, 7, 8, 9, 8, 7, 8, 9, 10, 11, 12, 13 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 5;
	if ( u > 10 && u < 13 ) {
		setAccelX( 0 );
	}
	if ( u == 12 ) {
		if ( _act_count % WAIT_ANIME_TIME == 0 ) {
			_stock->addEnemy( EnemyPtr( new EnemyBowDemonAttack( getX( ), getY( ) - ATTACK_FOOT ) ) );
		}
	}
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
	_act_count++;
}