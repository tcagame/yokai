#include "Field.h"
#include "Drawer.h"
#include "define.h"

static const int BG_X = 0;
static const int BG_Y = -48;
static const int BG_SIZE = 758;

Field::Field( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_BG_NEAR, "street/map0/map0_1_3.png" );
	drawer->loadGraph( GRAPH_BG_FAR, "street/map0/map0_2_3.png" );
}


Field::~Field( ) {
}

void Field::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	
	Drawer::Sprite sprite_bg_near( 
		Drawer::Transform( BG_X, BG_Y ),
		GRAPH_BG_NEAR );
	drawer->setSprite( sprite_bg_near );

	Drawer::Sprite sprite_bg_far( 
		Drawer::Transform( BG_X + BG_SIZE, BG_Y ),
		GRAPH_BG_FAR );
	drawer->setSprite( sprite_bg_far );
}

