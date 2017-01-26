#include "SceneResult.h"
#include "Game.h"
#include "Device.h"
#include "Drawer.h"
#include "define.h"

static const int FRAME_WIDTH  = 896;
static const int FRAME_HEIGHT = 772;

SceneResult::SceneResult( ) {
	DrawerPtr drawer = Drawer::getTask( );

	GamePtr game = Game::getTask( );
	_level = game->getStage( ) - 2;
	if ( _level < 0 ) {
		_level = 0;
	}

	switch ( _level ) {
	case 4:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/heaven/heaven_frame.png" );
		break;
	case 3:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/human/human_frame.png" );
		break;
	case 2:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/damn/damn_frame.png" );
		break;
	case 1:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hungry/hungry_frame.png" );
		break;
	case 0:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hell/hell_frame.png" );
		break;
	}
}


SceneResult::~SceneResult( ) {
}

Scene::NEXT SceneResult::update( ) {
	drawFrame( );

	switch ( _level ) {
	case 4: drawHeaven( ); break;
	case 3: drawHuman( ); break;
	case 2: drawDamn( ); break;
	case 1: drawHungry( ); break;
	case 0: drawHell( ); break;
	}

	GamePtr game = Game::getTask( );
	if ( game->getFade( ) == Game::FADE_NONE ) {
		DevicePtr device = Device::getTask( );
		if ( device->getPush( ) == BUTTON_A ) {
			game->setFade( Game::FADE_OUT );
		}
	}
	if ( game->getFade( ) == Game::FADE_COVER ) {
		return NEXT_TITLE;
	}
	return NEXT_CONTINUE;
}

void SceneResult::drawFrame( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( ( SCREEN_WIDTH - FRAME_WIDTH ) / 2, ( SCREEN_HEIGHT - FRAME_HEIGHT ) / 2 );
	Drawer::Sprite sprite( trans, GRAPH_RESULT_FRAME, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void SceneResult::drawHeaven( ) {

}

void SceneResult::drawHuman( ) {

}

void SceneResult::drawDamn( ) {

}

void SceneResult::drawHungry( ) {

}

void SceneResult::drawHell(  ) {

}
