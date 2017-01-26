#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"

static const int MOVE_SPEED = 10;
static const int WAIT_ANIME_TIME = 40;
static const int WAIT_ATTACK_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyRedbird::EnemyRedbird( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_attack_count( 0 ),
_accel( 0 ) {
}


EnemyRedbird::~EnemyRedbird( ) {
}

void EnemyRedbird::act( ) {
	actMove( );
	actAttack( );
	updateChip( );
}

void EnemyRedbird::actMove( ) {
	setAccelX( MOVE_SPEED );
}

void EnemyRedbird::actAttack( ) {
	_attack_count %= WAIT_ATTACK_TIME;
	if ( _attack_count == 0 ) {
		EnemyStockPtr enemy_stock = getEnemyStock( );
		enemy_stock->addEnemy( EnemyPtr( new EnemyRedbirdAttack( enemy_stock, getX( ), getY( ) ) ) );
	}
	_attack_count++;
}

void EnemyRedbird::updateChip( ) {
	const int MAX_ANIME_PATTERN = 9;
	const int ANIME_PATTERN[ MAX_ANIME_PATTERN ] = { 0, 4, 1, 0, 4, 2, 0, 4, 3  };
	int pattern = ANIME_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_COMMON, pattern, 5 );
}