#include "SceneResult.h"
#include "Game.h"
#include "Device.h"

SceneResult::SceneResult( ) {
}


SceneResult::~SceneResult( ) {
}

Scene::NEXT SceneResult::update( ) {
	GamePtr game = Game::getTask( );
	game->addDebugMessage( "Scene RESULT" );

	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) == BUTTON_A ) {
		game->setFade( Game::FADE_OUT );
	}
	if ( game->getFade( ) == Game::FADE_COVER ) {
		return NEXT_TITLE;
	}
	return NEXT_CONTINUE;
}
