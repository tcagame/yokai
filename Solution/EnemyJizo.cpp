#include "EnemyJizo.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 2;
static const int MOVE_SPEED = 3;
static const int WAIT_ANIME_TIME = 10;
static const int WAIT_ATTACK_TIME = 100;
static const int WAIT_APPEAR_TIME = 50;

EnemyJizo::EnemyJizo( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_action( ACTION_WAIT ),
_act_count( 0 ) {
}


EnemyJizo::~EnemyJizo( ) {
}

void EnemyJizo::act( ) {
	_act_count++;
	switch ( _action ) {
	case ACTION_WAIT:
		actWait( );
		break;
	case ACTION_APPEAR:
		updateChip( );
		break;
	case ACTION_NOMAL:
		actNomal( );
		break;
	}
	actNomal( );
}

void EnemyJizo::actNomal( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyJizo::actWait( ) {
	if ( _act_count > WAIT_APPEAR_TIME ) {
		_action = ACTION_APPEAR;
		_act_count = 0;
	}
}

void EnemyJizo::updateChip( ) {
	const int MAX_WIDTH_NUM = 4;
	const int MAX_ANIME_PATTERN = 8;
	int u = _act_count / WAIT_ANIME_TIME % MAX_WIDTH_NUM;
	int v = _act_count / WAIT_ANIME_TIME / MAX_WIDTH_NUM + 2;
	setChipGraph( GRAPH_ENEMY_BIG_2, u, v );
	if ( u == 3 && v == 3 ) {
		_action = ACTION_NOMAL;
	}
}