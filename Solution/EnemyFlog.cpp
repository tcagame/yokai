#include "EnemyFlog.h"
#include "EnemyFlogSmall.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 10;
static const int WAIT_ANIME_TIME = 10;
static const int MAX_RAND = 600;
static const int WAIT_ATTACK_TIME = 20;
static const int MAX_CREATE_NUM = 100;

EnemyFlog::EnemyFlog( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_stock( stock ) {
}


EnemyFlog::~EnemyFlog( ) {
}

void EnemyFlog::act( ) {
	_act_count++;
	actAttack( );
	updateChip( );
}

void EnemyFlog::updateChip( ) {
	const int WIDTH_NUM = 4;
	const int ANIME[ ] = { 0, 1, 3, 4, 3, 1, 0, 1, 2, 2, 3, 4, 3, 1 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ] % WIDTH_NUM;
	int v = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ] / WIDTH_NUM;
	setChipGraph( GRAPH_ENEMY_FLOG_GREEN, u, v );
}

void EnemyFlog::actAttack( ) {
	if ( _act_count % WAIT_ATTACK_TIME == 0 ) {
		if ( _act_count < WAIT_ATTACK_TIME * MAX_CREATE_NUM ) {
			EnemyPtr enemy = EnemyPtr( new EnemyFlogSmall( getX( ) - rand( ) % MAX_RAND + MAX_RAND / 3, 100 ) );
			_stock->addEnemy( enemy );
		}
	}
}