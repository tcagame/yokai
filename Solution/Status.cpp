#include "Status.h"
#include "Drawer.h"
#include "define.h"

static const int MAP_WIDTH = 347;

Status::Status( ) {
}

Status::~Status( ) {
}

void Status::update( ) {
}

void Status::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	{
		Drawer::Transform trans( SCREEN_WIDTH - MAP_WIDTH, 0 );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_MAP );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Transform trans( 0, 0 );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_PLATE );
		drawer->setSprite( sprite );
	}
}