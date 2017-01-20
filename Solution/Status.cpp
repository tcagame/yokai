#include "Status.h"
#include "Drawer.h"
#include "define.h"

Status::Status( ) {
}

Status::~Status( ) {
}

void Status::update( ) {
}

void Status::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( 0, 0 );
	Drawer::Sprite sprite( trans, GRAPH_STATUS );
	drawer->setSprite( sprite );
}