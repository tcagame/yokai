#include "Item.h"
#include "Drawer.h"
#include "Camera.h"
#include "define.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;

Item::Item( int x, int y ) :
_pos( x, y ),
_count( 0 ) {
}


Item::~Item( ) {
}

bool Item::update( const Vector& pos ) {
	_count++;

	return ( _pos - pos ).getLength2( ) < CHIP_SIZE * CHIP_SIZE;
}

void Item::draw( CameraConstPtr camera ) const {
	int idx = _count / 5 % 4;
	int tx = idx % 2 * CHIP_SIZE;
	int ty = idx / 2 * CHIP_SIZE;
	int sx = ( int )_pos.x - camera->getX( ) - CHIP_SIZE / 2;
	int sy = ( int )_pos.y - camera->getY( ) - CHIP_SIZE / 2;

	Drawer::Sprite sprite(
		Drawer::Transform( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE ), GRAPH_ITEM );
	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( sprite );
}