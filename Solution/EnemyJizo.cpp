#include "EnemyJizo.h"
#include "EnemyJizoAttack.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 2;
static const int MOVE_SPEED = 1;
static const int WAIT_ANIME_TIME = 6;
static const int WAIT_ATTACK_TIME = 100;
static const int WAIT_APPEAR_TIME = 10;
static const int ATTACK_FOOT = 100;

EnemyJizo::EnemyJizo( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_stock( stock ),
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
}

void EnemyJizo::actNomal( ) {
	setAccelX( -MOVE_SPEED );
	if ( _act_count % WAIT_ATTACK_TIME == 0 ) {
		EnemyPtr enemy = EnemyPtr( new EnemyJizoAttack( getX( ), getY( ) - ATTACK_FOOT ) );
		_stock->addEnemy( enemy );
	}
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