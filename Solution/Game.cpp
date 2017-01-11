#include "Game.h"
#include "SceneStreet.h"

Game::Game( ) {
}


Game::~Game( ) {

}

void Game::initialize( ) {
	_scene = ScenePtr( new SceneStreet );
}

void Game::update( ) {
	_scene->update( );
}