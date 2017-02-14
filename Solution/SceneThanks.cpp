#include "SceneThanks.h"
#include "Drawer.h"
#include "define.h"

static const int NEXT_TIME = 200;

SceneThanks::SceneThanks( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_THANKS, "thanks/thanks_bg.png" );
}


SceneThanks::~SceneThanks( ) {
}

Scene::NEXT SceneThanks::update( ) {
	_next_count++;
	if( _next_count > NEXT_TIME ) {
		return NEXT_TITLE;
	}

	draw( );

	return NEXT_CONTINUE;
}

void SceneThanks::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans = Drawer::Transform( 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT );
	Drawer::Sprite sprite( trans, GRAPH_THANKS );
	drawer->setSprite( sprite );
}