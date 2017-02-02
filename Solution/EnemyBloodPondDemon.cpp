#include "EnemyBloodPondDemon.h"
#include "EnemyFire.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 30;
static const int POW = 6;
static const int WAIT_AINME_TIME = 10;
static const double RANGE = 1500;

EnemyBloodPondDemon::EnemyBloodPondDemon( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_stock( stock ),
_regist( true ),
_count( 0 ) {
	focus( );
}

EnemyBloodPondDemon::~EnemyBloodPondDemon( ) {
	for ( int i = 0; i < FIRE_NUM; i++ ) {
		_fires[ i ]->damage( -1 );
	}
}

void EnemyBloodPondDemon::act( ) {
	_count++;
	if ( _regist ) {
		generate( );
		_regist  = false;
	}
	updateChip( );
}

void EnemyBloodPondDemon::generate( ) {
	Vector target = getOverlappedPos( ) ;
	target.y = BG_SIZE / 2;
	Vector offset( RANGE, 0 );
	Vector vec( 0, 1 );
	Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, 1 ), PI2 / FIRE_NUM );
	for ( int i = 0; i < FIRE_NUM / 2; i++ ) {
		offset = mat.multiply( offset );
		vec = mat.multiply( vec );
		EnemyFirePtr fire( new EnemyFire( target + offset, vec, target ) );
		_stock->addEnemy( fire );
		_fires[ i ] = fire;
	}
	
	offset *= 0.6;
	vec *= -1;
	for ( int i = 0; i < FIRE_NUM / 2; i++ ) {
		offset = mat.multiply( offset );
		vec = mat.multiply( vec );
		EnemyFirePtr fire( new EnemyFire( target + offset, vec, target ) );
		_stock->addEnemy( fire );
		_fires[ i + FIRE_NUM / 2 ] = fire;
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