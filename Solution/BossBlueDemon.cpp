#include "BossBlueDemon.h"
#include "Drawer.h"
#include "Camera.h"
#include "EnemyGhost.h"
#include "EnemyLittleBlueDemon.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60;
static const int OFFSET_Y = 512 - 140;
static const int HP  = 30;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 20;
static const int LIFTING = 50;
static const double RADIUS = 50;
static const int CREATE_COUNT_GHOST = 60;
static const int CREATE_COUNT_LITTLE_BLUE_DEMON = 60;

BossBlueDemon::BossBlueDemon( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ),
_count( 0 ) {
}

BossBlueDemon::~BossBlueDemon( ) {
}

void BossBlueDemon::act( ) {
	_count++;
	
	setChipGraph( GRAPH_ENEMY_BOSS, _count / WAIT_ANIME_TIME % 2, 0 );
}

void BossBlueDemon::drawOverlapped( CameraConstPtr camera ) const {

	int tx = 0 * CHIP_SIZE;
	int ty = 1 * CHIP_SIZE;

	int sx = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );
	if ( _count / WAIT_ANIME_TIME % 2 ) {
		sy -= LIFTING;
	}

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE / 2, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_ENEMY_BOSS, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void BossBlueDemon::attack( ) {
	if ( _count % CREATE_COUNT_GHOST == 0 ) {
		int x = getCameraX( ) + rand( ) % SCREEN_WIDTH;
		int y = rand( ) % 150 + 100;
		_stock->addEnemy( EnemyPtr( new EnemyGhost( x, y ) ) );
	}

	if ( _count % CREATE_COUNT_LITTLE_BLUE_DEMON == 0 ) {
		int x = getX( );
		int y = getY( );
		_stock->addEnemy( EnemyPtr( new EnemyLittleBlueDemon( getCameraX( ) + SCREEN_WIDTH, y ) ) );
	}

}

double BossBlueDemon::getOverlappedRadius( ) const {
	return RADIUS;
}
