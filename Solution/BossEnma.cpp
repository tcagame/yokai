#include "BossEnma.h"
#include "EnemyBowDemon.h"
#include "EnemyNoFace.h"
#include "EnemyOnyudo.h"

static const int WAIT_ANIME_TIME = 10;
static const int CHIP_SIZE = 128;
static const int OFFSET_X = 192 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 265;
static const int HP  = 20;
static const int POW = 10;
static const int CREATE_COUNT_ENEMY = 60;
static const double RADIUS = 12;

BossEnma::BossEnma( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ) {
}


BossEnma::~BossEnma( ) {
}

void BossEnma::act( ) {
	updateChip( );
}

void BossEnma::attack( ) {
	const int pattern = 3;
	if ( _count % CREATE_COUNT_ENEMY == 0 ) {
		int x = getX( ) - 200;
		int y = getY( ) + 100;
		
		switch ( rand( ) % pattern ) {
		case 0:
			_stock->addEnemy( EnemyPtr( new EnemyBowDemon( _stock, x, y ) ) );
			break;
		case 1:
			_stock->addEnemy( EnemyPtr( new EnemyNoFace( x, y ) ) );
			break;
		case 2:
			_stock->addEnemy( EnemyPtr( new EnemyOnyudo( x, y ) ) );
			break;
		}
	}
}

void BossEnma::updateChip( ) {
	const int WIDTH_NUM = 2;
	const int MOTION[ ] = { 0, 2, 1, 2 };
	int pattern = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _count / WAIT_ANIME_TIME ) % pattern ] % WIDTH_NUM;
	int v = MOTION[ ( _count / WAIT_ANIME_TIME ) % pattern ] / WIDTH_NUM;
	_count++;

	setChipGraph( GRAPH_ENEMY_BOSS, u, v );
}

double BossEnma::getOverlappedRadius( ) const {
	return RADIUS;
}