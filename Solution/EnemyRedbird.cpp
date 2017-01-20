#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"

static const int SIZE = 204;
static const int FOOT = 0;
static const int MAX_PATTERN = 5;
static const int MOVE_SPEED = 10;
static const int WAIT_PATTERN_TIME = 20;
static const int WAIT_ATTACK_TIME = 25;

EnemyRedbird::EnemyRedbird( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY_REDBIRD, SIZE, FOOT, false ),
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
	setAccelX( -MOVE_SPEED );
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
	int pattern = ( getX( ) / WAIT_PATTERN_TIME ) % MAX_PATTERN;
	setChipUV( pattern, 0 );
}