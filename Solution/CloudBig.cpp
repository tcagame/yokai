#include "CloudBig.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"

static const int CLOUD_BIG_WIDTH = 400;
static const int CLOUD_BIG_HEIGHT = 216;

CloudBig::CloudBig( int x, int y ) :
Cloud( x, y ) {
}

CloudBig::~CloudBig( ) {
}

void CloudBig::draw( CameraPtr camera ) {
	DrawerPtr drawer = Drawer::getTask( );
	//int cx = 0;
	int tx = getChip( ) * CLOUD_BIG_WIDTH;
	int ty = 0;
	int sx = getX( ) - camera->getX( );
	int sy = getY( );
	int sx2 = sx + CLOUD_BIG_WIDTH;
	int sy2 = sy + CLOUD_BIG_HEIGHT;

	Drawer::Transform trans( sx, sy, tx, ty, CLOUD_BIG_WIDTH, CLOUD_BIG_HEIGHT, sx2, sy2 );
	Drawer::Sprite sprite( trans, GRAPH_CLOUD_BIG, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}