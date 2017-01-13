#include "CloudSmall.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"

static const int CLOUD_SMALL_WIDTH = 207;
static const int CLOUD_SMALL_HEIGHT = 216;

CloudSmall::CloudSmall( int x, int y ) :
Cloud( x, y ) {
}

CloudSmall::~CloudSmall( ) {
}

void CloudSmall::draw( CameraPtr camera ) {
	DrawerPtr drawer = Drawer::getTask( );
	//int cx = 0;
	int tx = getChip( ) * CLOUD_SMALL_WIDTH;
	int ty = 0;
	int sx = getX( ) - camera->getX( );
	int sy = getY( );
	int sx2 = sx + CLOUD_SMALL_WIDTH;
	int sy2 = sy + CLOUD_SMALL_HEIGHT;

	Drawer::Transform trans( sx, sy, tx, ty, CLOUD_SMALL_WIDTH, CLOUD_SMALL_HEIGHT, sx2, sy2 );
	Drawer::Sprite sprite( trans, GRAPH_CLOUD_SMALL, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}