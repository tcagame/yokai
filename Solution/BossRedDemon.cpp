#include "BossRedDemon.h"
#include "Drawer.h"
#include "Camera.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60;
static const int OFFSET_Y = 512 - 140;
static const int HP  = 20;
static const int POW = 10;

BossRedDemon::BossRedDemon( EnemyStockPtr enemy_stock, int x ) :
Boss( enemy_stock, x + OFFSET_X, OFFSET_Y, HP, POW ) { 
}


BossRedDemon::~BossRedDemon( ) {
}

void BossRedDemon::act( ) {
	setChipGraph( GRAPH_BOSS_1, 0, 0 );
}

void BossRedDemon::drawOverlapped( CameraConstPtr camera ) const {

	int tx = 0 * CHIP_SIZE;
	int ty = 1 * CHIP_SIZE;

	int sx = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_BOSS_1, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void BossRedDemon::attack( ) {

}
