#include "EnemyFlog.h"
#include "EnemyFlogSmall.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 10;
static const int WAIT_ANIME_TIME = 10;
static const int MAX_RAND = 600;
static const int WAIT_ATTACK_TIME = 20;
static const int MAX_CREATE_NUM = 100;

EnemyFlog::EnemyFlog( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_enemy_stock( enemy_stock ) {
}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::act( ) {
	_act_count++;
	actAttack( );
	updateChip( );
}

void EnemyFlog::updateChip( ) {
	const int WIDTH_NUM = 3;
	const int MAX_ANIME_PATTERN = 5;
	int u = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN % WIDTH_NUM;
	int v = _act_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN / WIDTH_NUM;
	setChipGraph( GRAPH_ENEMY_FLOG, u, v );
}

void EnemyFlog::actAttack( ) {
	if ( _act_count % WAIT_ATTACK_TIME == 0 ) {
		if ( _act_count < WAIT_ATTACK_TIME * MAX_CREATE_NUM ) {
			EnemyPtr enemy = EnemyPtr( new EnemyFlogSmall( _enemy_stock, getX( ) - rand( ) % MAX_RAND + MAX_RAND / 3, 100 ) );
			_enemy_stock->addEnemy( enemy );
		}
	}
}