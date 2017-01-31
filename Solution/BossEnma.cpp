#include "BossEnma.h"
#include "EnemyHandMonster.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyNoFace.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyRedbird.h"
#include "EnemyBowDemon.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyMiasmaGray.h"
#include "EnemyHugDemon.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyCrocodileSnake.h"
#include "EnemyGhoul.h"
#include "EnemyBlueMonk.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyStoneFly.h"
#include "EnemyHellFire.h"
#include "EnemyShishimai.h"
#include "EnemyShishimaiDemon.h"
#include "EnemySkeletonSpear.h"

static const int WAIT_ANIME_TIME = 10;
static const int CHIP_SIZE = 128;
static const int OFFSET_X = 192 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 265;
static const int HP  = 30;
static const int POW = 6;
static const int CREATE_COUNT_ENEMY = 20;
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
	const int ENEMY_NUM = 19;
	if ( _count % CREATE_COUNT_ENEMY == 0 ) {
		int x = getX( ) - 200;
		int y = getY( ) + 100;
		
		switch ( rand( ) % ENEMY_NUM ) {
		case 0:
			_stock->addEnemy( EnemyPtr( new EnemyHandMonster( _stock, x - 100, y ) ) );
			break;
		case 1:
			_stock->addEnemy( EnemyPtr( new EnemyDeceasedGreen( x, y ) ) );
			break;
		case 2:
			_stock->addEnemy( EnemyPtr( new EnemyDeceasedPurple( x, y ) ) );
			break;
		case 3:
			_stock->addEnemy( EnemyPtr( new EnemyNoFace( x, y ) ) );
			break;
		case 4:
			_stock->addEnemy( EnemyPtr( new EnemyOneEyesSnake(  x, y ) ) );
			break;
		case 5:
			_stock->addEnemy( EnemyPtr( new EnemyRedbird( _stock, x - BG_SIZE * 2, y - 100 ) ) );
			break;
		case 6:
			_stock->addEnemy( EnemyPtr( new EnemyBowDemon( _stock, x, y ) ) );
			break;
		case 7:
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaWhite( x, y - 50 ) ) );
			break;
		case 8:
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaGray( x, y - 50 ) ) );
			break;
		case 9:
			_stock->addEnemy( EnemyPtr( new EnemyHugDemon( x, y ) ) );
			break;
		case 10:
			_stock->addEnemy( EnemyPtr( new EnemyExtrudedSpirits( x, y - 50 ) ) );
			break;
		case 11:
			_stock->addEnemy( EnemyPtr( new EnemyCrocodileSnake( x, y ) ) );
			break;
		case 12:
			_stock->addEnemy( EnemyPtr( new EnemyGhoul( x, y ) ) );
			break;
		case 13:
			_stock->addEnemy( EnemyPtr( new EnemyBlueMonk( x, y ) ) );
			break;
		case 14:
			_stock->addEnemy( EnemyPtr( new EnemyNoNeckGhost( x, y ) ) );
			break;
		case 15:
			_stock->addEnemy( EnemyPtr( new EnemyStoneFly( x, y - 100 ) ) );
			break;
		case 16:
			_stock->addEnemy( EnemyPtr( new EnemyHellFire( x, y - 50 ) ) );
			break;
		case 17:
			_stock->addEnemy( EnemyPtr( new EnemyShishimai( x, y ) ) );
			break;
		case 18:
			_stock->addEnemy( EnemyPtr( new EnemyShishimaiDemon( x, y ) ) );
			break;
		case 19:
			_stock->addEnemy( EnemyPtr( new EnemySkeletonSpear( x, y ) ) );
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