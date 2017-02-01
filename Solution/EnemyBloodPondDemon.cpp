#include "EnemyBloodPondDemon.h"
#include "EnemyFire.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 30;
static const int POW = 6;
static const int WAIT_AINME_TIME = 10;
static const int SPEED = 3;
static const int ACCEL = 5;
static const int CREATE_COUNT_FIREBALL = 15;

EnemyBloodPondDemon::EnemyBloodPondDemon( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_stock( stock ),
_action( ACTION_WAIT ),
_count( 0 ) {
}


EnemyBloodPondDemon::~EnemyBloodPondDemon( ) {
}

void EnemyBloodPondDemon::act( ) {
	attack( );
	updateChip( );
}

void EnemyBloodPondDemon::attack( ) {
	_count++;
	if ( _count % CREATE_COUNT_FIREBALL == 0 ) {
		if ( rand( ) % 2 ) {
			Vector pos( getX( ) + rand( ) % SCREEN_WIDTH - SCREEN_WIDTH / 3, -32 );
			Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, -1 ), rand( ) % 1000 * PI / 2 / 1000 );
			Vector vec = mat.multiply( Vector( 0, SPEED + rand( ) % ACCEL ) );
			_stock->addEnemy( EnemyPtr( new EnemyFire( pos, vec ) ) );
		} else {
			Vector pos( getX( ) + SCREEN_WIDTH / 5, rand( ) % SCREEN_HEIGHT - SCREEN_HEIGHT / 3 );
			Vector vec = Vector( -SPEED - rand( ) % ACCEL, 0, 0 );
			_stock->addEnemy( EnemyPtr( new EnemyFire( pos, vec ) ) );
		}
	}
}

void EnemyBloodPondDemon::updateChip( ) {
	const int ANIME[ ] = { 3, 2, 1, 0, 1, 0, 1, 0, 1, 2 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int pattern = ANIME[ _count / WAIT_AINME_TIME % anime_num ];
	int u = pattern % 2;
	int v = pattern / 2;	
	setChipGraph( GRAPH_ENEMY_BLOOD_POND, u, v );
}