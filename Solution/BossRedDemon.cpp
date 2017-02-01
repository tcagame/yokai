#include "BossRedDemon.h"
#include "Drawer.h"
#include "Camera.h"
#include "EnemyGhost.h"
#include "EnemyLittleRedDemon.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60;
static const int OFFSET_Y = 512 - 140;
static const int HP  = 20;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 20;
static const int LIFTING = 50;
static const double RADIUS = 50;
static const int CREATE_COUNT_GHOST = 100;
static const int CREATE_COUNT_LITTLE_RED_DEMON = 60;

BossRedDemon::BossRedDemon( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ),
_stock( stock ),
_count( 0 ) { 
}


BossRedDemon::~BossRedDemon( ) {
}

void BossRedDemon::act( ) {
	_count++;
	
	setChipGraph( GRAPH_ENEMY_BOSS, _count / WAIT_ANIME_TIME % 2, 0 );
}

void BossRedDemon::drawOverlapped( CameraConstPtr camera ) const {

	int tx = 0 * CHIP_SIZE;
	int ty = 1 * CHIP_SIZE;

	int sx = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );	
	if ( _count % WAIT_ANIME_TIME > WAIT_ANIME_TIME / 4 ) {
		sy -= LIFTING * ( _count % WAIT_ANIME_TIME / 2 ) / 10;
	}

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE / 2, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_ENEMY_BOSS, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void BossRedDemon::attack( ) {
	if ( _count % CREATE_COUNT_GHOST == 0 ) {
		int x = getCameraX( ) + rand( ) % SCREEN_WIDTH;
		int y = rand( ) % 150 + 100;
		_stock->addEnemy( EnemyPtr( new EnemyGhost( x, y ) ) );
	}

	if ( _count % CREATE_COUNT_LITTLE_RED_DEMON == 0 ) {
		int x = getX( );
		int y = getY( );
		_stock->addEnemy( EnemyPtr( new EnemyLittleRedDemon( getCameraX( ) + SCREEN_WIDTH, y ) ) );
	}

}

double BossRedDemon::getOverlappedRadius( ) const {
	return RADIUS;
}
