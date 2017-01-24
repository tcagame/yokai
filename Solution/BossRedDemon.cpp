#include "BossRedDemon.h"
#include "Drawer.h"
#include "Camera.h"

static const int  CHIP_SIZE = 256;

BossRedDemon::BossRedDemon( EnemyStockPtr enemy_stock ) :
Boss( enemy_stock ) { 
}


BossRedDemon::~BossRedDemon( ) {
}

void BossRedDemon::act( ) {
	setChipGraph( GRAPH_BOSS, 0, 0 );
}

void BossRedDemon::drawOverlapped( CameraConstPtr camera ) const {

	int tx = 0 * CHIP_SIZE;
	int ty = 1 * CHIP_SIZE;

	int sx = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_BOSS, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}