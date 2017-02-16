#include "EnemyShishimaiDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 25;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 20;
static const int MOVE_SPEED = 5;
static const int WAIT_JUMP_TIME = 40;
static const int JUMP_POWER = -40;
static const int RANGE = 250;

EnemyShishimaiDemon::EnemyShishimaiDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_move_speed( -MOVE_SPEED ),
_before_x( 0 ) {
}


EnemyShishimaiDemon::~EnemyShishimaiDemon( ) {
}

void EnemyShishimaiDemon::act( ) {
	_act_count++;
	move( );
	updateChip( );
}

void EnemyShishimaiDemon::move( ) {
	// 止まったら反転
	if ( _before_x == getX( ) ) {
		_move_speed *= -1;
	}
	_before_x = getX( );

	// たろすけと距離を保つ
	int lengh = getX( ) - getTargetX( );
	// たろすけより右側の時は離れる たろすけより左側の時は近づく
	if ( lengh < RANGE ) {
		_move_speed = MOVE_SPEED;
	}
	lengh = getTargetX( ) + RANGE * 2;
	// たろすけより右側の時のみ近づく
	if ( lengh < getX( ) ) {
		_move_speed = -MOVE_SPEED;
	}
	
	setAccelX( _move_speed );

	// たろすけがジャンプしたらジャンプ
	if ( isStanding( ) && getY( ) > getTargetY( ) ) {
		setAccelY( JUMP_POWER );
	}
}

void EnemyShishimaiDemon::updateChip( ) {
	const int ANIME[ ] = { 12, 13, 14, 15, 14, 13 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % anime_num ];
	int v = 12;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );
}