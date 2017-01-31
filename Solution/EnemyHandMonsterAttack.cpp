#include "EnemyHandMonsterAttack.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 1;
static const int POW = 2;
static const int MOVE_SPEED_Y = 40;
static const int INIT_MOVE_SPEED_Y = -12;
static const int FALL_ACCEL = 3;
static const int WAIT_ANIME_TIME = 3;

EnemyHandMonsterAttack::EnemyHandMonsterAttack( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_speed_y( INIT_MOVE_SPEED_Y ) {
}


EnemyHandMonsterAttack::~EnemyHandMonsterAttack( ) {
}

void EnemyHandMonsterAttack::act( ) {
	setAccelX( -MOVE_SPEED_Y );
	setAccelY( _speed_y );
	_speed_y += FALL_ACCEL;

	const int ANIME[ ] = { 0, 1, 2, 3 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 0;
	setChipGraph( GRAPH_ENEMY_EFFECT_SMALL, u, v ); 
}