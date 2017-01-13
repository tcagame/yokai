#include "Game.h"
#include "SceneTitle.h"
#include "SceneStreet.h"
#include "Drawer.h"

Game::Game( ) {
}


Game::~Game( ) {

}

void Game::initialize( ) {
	_scene = ScenePtr( new SceneStreet );
	//_scene = ScenePtr( new SceneTitle );
}

void Game::update( ) {
	Scene::NEXT next = _scene->update( );

	if ( next == Scene::NEXT_CONTINUE ) {
		return;
	}
	
	_scene.reset( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->unloadAllGraph( );

	switch ( next ) {
	case Scene::NEXT_STREET:
		_scene = ScenePtr( new SceneStreet );
		break;
	}

}