#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"

static const int MOVE_SPEED = 10;
static const int WAIT_ANIME_TIME = 40;
static const int WAIT_ATTACK_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 3;
static const int EXTIT_TIME = 80;

EnemyRedbird::EnemyRedbird( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_stock( stock ),
_accel( 0 ) {
}


EnemyRedbird::~EnemyRedbird( ) {
}

void EnemyRedbird::act( ) {
	_count++;

	setAccelX( MOVE_SPEED );
	if ( _count >= EXTIT_TIME ) {
		setAccelY( -MOVE_SPEED );
	}

	if ( _count % WAIT_ATTACK_TIME == 0 ) {
		_stock->addEnemy( EnemyPtr( new EnemyRedbirdAttack( getX( ), getY( ) ) ) );
	}

	const int MAX_ANIME_PATTERN = 9;
	const int ANIME_PATTERN[ MAX_ANIME_PATTERN ] = { 0, 4, 1, 0, 4, 2, 0, 4, 3  };
	int pattern = ANIME_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 5 );
}