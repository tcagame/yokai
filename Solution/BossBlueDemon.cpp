#include "BossBlueDemon.h"
#include "Drawer.h"
#include "Camera.h"
#include "EnemyGhost.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60;
static const int OFFSET_Y = 512 - 140;
static const int HP  = 20;
static const int POW = 10;
static const double RADIUS = 50;
static const int CREATE_COUNT_GHOST = 60;
static const int CREATE_COUNT_LITTLE_RED_DEMON = 60;

BossBlueDemon::BossBlueDemon( EnemyStockPtr enemy_stock, int x ) :
Boss( enemy_stock, x + OFFSET_X, OFFSET_Y, HP, POW ),
_count( 0 ) {
}

BossBlueDemon::~BossBlueDemon( ) {
}

void BossBlueDemon::act( ) {
	setChipGraph( GRAPH_BOSS_2, 0, 0 );
}

void BossBlueDemon::drawOverlapped( CameraConstPtr camera ) const {

	int tx = 0 * CHIP_SIZE;
	int ty = 1 * CHIP_SIZE;

	int sx = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_BOSS_2, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void BossBlueDemon::attack( ) {
	_count++;
	if ( _count % CREATE_COUNT_GHOST == 0 ) {
		int x = getX( ) - rand( ) % SCREEN_WIDTH;
		int y = rand( ) % 150 + 100;
		Vector target( getX( ) - SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
		EnemyStockPtr stock = getEnemyStock( );
		stock->addEnemy( EnemyPtr( new EnemyGhost( stock, x, y, target ) ) );
	}

	if ( _count % CREATE_COUNT_LITTLE_RED_DEMON == 0 ) {
		int x = getX( );
		int y = getY( );
		EnemyStockPtr stock = getEnemyStock( );
	//	stock->addEnemy( EnemyPtr( new EnemyLittleBlueDemon( stock, x, y ) ) );
	}

}

double BossBlueDemon::getOverlappedRadius( ) const {
	return RADIUS;
}
