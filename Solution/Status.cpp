#include "Status.h"
#include "Drawer.h"
#include "define.h"

static const int MAP_WIDTH = 347;
static const int POWER_X = 218;
static const int POWER_Y = 136;

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
	{
		static int n = 0;
		n++;

		Drawer::Transform trans( POWER_X, POWER_Y, 0, 0, 672 - ( n / 30 * 16 ), 32 );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_POWER );
		drawer->setSprite( sprite );
	}
}