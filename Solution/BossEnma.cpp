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
#include "EnemyShishimai.h"
#include "EnemyShishimaiDemon.h"
#include "EnemySkeletonSpear.h"
#include "EnemyYadokariYokai.h"
#include "EnemyJizo.h"
#include "EnemyWindMonster.h"
#include "EnemyOnyudo.h"

static const int WAIT_ANIME_TIME = 10;
static const int CHIP_SIZE = 128;
static const int OFFSET_X = 192 + CHIP_SIZE;
static const int OFFSET_Y = 512 - 265;
static const int HP  = 30;
static const int POW = 6;
static const int CREATE_COUNT_ENEMY = 120;
static const double RADIUS = 90;
static const double RANGE = 650;

BossEnma::BossEnma( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ),
_anime_count( 0 ),
_attack_count( 60 ) {
}


BossEnma::~BossEnma( ) {
}

void BossEnma::act( ) {
	updateChip( );
}

void BossEnma::attack( ) {
	if ( getTargetX( ) < getX( ) - RANGE && _attack_count < 1 ) {
		return;
	}
	_attack_count++;
	const int ATTACK_PATTERN = 10; // switch case‚Ì”
	_attack_count %= CREATE_COUNT_ENEMY * ATTACK_PATTERN;

	if ( _attack_count % CREATE_COUNT_ENEMY == 0 ) {
		int x = getX( );
		int y = getY( ) + 100;
		
		switch ( _attack_count / CREATE_COUNT_ENEMY ) {
		case 0: // ‰»‚¯’n‘ 
			_stock->addEnemy( EnemyPtr( new EnemyJizo( _stock, x - 250, y ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyJizo( _stock, x - 1000, y ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyRedbird( _stock, x - SCREEN_WIDTH, y - 150 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyRedbird( _stock, x - SCREEN_WIDTH + 100, y - 150 ) ) );
			break;
		case 1: // •—‚Ì—d‰ö & ‘å“ü“¹
			_stock->addEnemy( EnemyPtr( new EnemyNoNeckGhost( x, y - 100 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyNoNeckGhost( x - 150, y - 150 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemySkeletonSpear( x + 140, y ) ) );
			_stock->addEnemy( EnemyPtr( new EnemySkeletonSpear( x + 190, y ) ) );
			break;
		case 2: // Ô‚¢“G
			_stock->addEnemy( EnemyPtr( new EnemyRedbird( _stock, x + SCREEN_WIDTH, y - 150, false ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyRedbird( _stock, x - SCREEN_WIDTH - 50, y - 150 ) ) );
			break;
		case 3: // ‚»‚Ì‘¼
			_stock->addEnemy( EnemyPtr( new EnemyWindMonster( _stock, x + 400, y - 150 ) ) );
			break;
		case 4: // ƒS[ƒXƒg
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaGray( x, y - 250 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaGray( x - 100, y - 150 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaGray( x - 100, y - 250 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaGray( x - 200, y - 150 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyExtrudedSpirits( x, y - 150 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyExtrudedSpirits( x - SCREEN_WIDTH, y - 150, true ) ) );
			break;
		case 5:		
			_stock->addEnemy( EnemyPtr( new EnemyNoNeckGhost( x, y - 100 ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyNoNeckGhost( x - 150, y - 150 ) ) );
			break;
		case 6: // ƒS[ƒXƒg
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaWhite( x, y - 250, true ) ) );
			_stock->addEnemy( EnemyPtr( new EnemyMiasmaWhite( x + 100, y - 150, true ) ) );
			break;
		case 7:
			_stock->addEnemy( EnemyPtr( new EnemySkeletonSpear( x + 140, y ) ) );
			_stock->addEnemy( EnemyPtr( new EnemySkeletonSpear( x + 190, y ) ) );
			break;
		}
	}
}

void BossEnma::updateChip( ) {
	const int WIDTH_NUM = 2;
	const int MOTION[ ] = { 0, 2, 1, 2 };
	int pattern = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	int u = MOTION[ ( _anime_count / WAIT_ANIME_TIME ) % pattern ] % WIDTH_NUM;
	int v = MOTION[ ( _anime_count / WAIT_ANIME_TIME ) % pattern ] / WIDTH_NUM;
	_anime_count++;

	setChipGraph( GRAPH_ENEMY_BOSS, u, v );
}

double BossEnma::getOverlappedRadius( ) const {
	return RADIUS;
}