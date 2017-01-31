#include "EnemyWindMonsterAttack.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 3;
static const int POW = 3;
static const int MOVE_SPEED_X = 15;
static const int MOVE_SPEED_Y = 3;
static const int WAIT_ANIME_TIME = 5;

EnemyWindMonsterAttack::EnemyWindMonsterAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ) {
}


EnemyWindMonsterAttack::~EnemyWindMonsterAttack( ) {
}

void EnemyWindMonsterAttack::act( ) {

	const int ANIME[ ] = { 10, 10, 10, 10, 10, 10, 10, 11, 12, 13 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 2;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );

	int move_speed_y = MOVE_SPEED_Y / ( u - 9 );
	setAccelX( -MOVE_SPEED_X );
	setAccelY( move_speed_y );
	if ( u == 13 ) {
		setAccelY( -1000 );
	}
	_act_count++;
}