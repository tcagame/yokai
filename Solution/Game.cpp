#include "Game.h"
#include "SceneStreet.h"

Game::Game( ) {
	_scene = ScenePtr( new SceneStreet );
}


Game::~Game( ) {

}

void Game::update( ) {
	_scene->update( );
}