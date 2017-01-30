#include "EnemyBloodPondDemon.h"
#include "EnemyFireball.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 20;
static const int POW = 2;
static const int WAIT_AINME_TIME = 10;
static const int SPEED = 3;
static const int ACCEL = 5;
static const int CREATE_COUNT_FIREBALL = 15;

EnemyBloodPondDemon::EnemyBloodPondDemon( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_stock( stock ),
_action( ACTION_WAIT ),
_count( 0 ) {
}


EnemyBloodPondDemon::~EnemyBloodPondDemon( ) {
}

void EnemyBloodPondDemon::act( ) {
	attack( );
	setChipGraph( GRAPH_ENEMY_BIG, 0, 5 );
}

void EnemyBloodPondDemon::attack( ) {
	_count++;
	if ( _count % CREATE_COUNT_FIREBALL == 0 ) {
		if ( rand( ) % 2 ) {
			Vector pos( getX( ) + rand( ) % SCREEN_WIDTH - SCREEN_WIDTH / 3, -32 );
			Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, -1 ), rand( ) % 1000 * PI / 2 / 1000 );
			Vector vec = mat.multiply( Vector( 0, SPEED + rand( ) % ACCEL ) );
			_stock->addEnemy( EnemyPtr( new EnemyFireball( pos, vec ) ) );
		} else {
			Vector pos( getX( ) + SCREEN_WIDTH / 5, rand( ) % SCREEN_HEIGHT - SCREEN_HEIGHT / 3 );
			Vector vec = Vector( -SPEED - rand( ) % ACCEL, 0, 0 );
			_stock->addEnemy( EnemyPtr( new EnemyFireball( pos, vec ) ) );
		}
	}
}