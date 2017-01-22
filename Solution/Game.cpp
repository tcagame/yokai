#include "Game.h"
#include "SceneTitle.h"
#include "SceneGate.h"
#include "SceneStreet.h"
#include "Drawer.h"

Game::Game( ) {
}


Game::~Game( ) {

}

void Game::initialize( ) {
	_solo = true;
	_stage = 0;
	//_scene = ScenePtr( new SceneStreet );
	//_scene = ScenePtr( new SceneGate( _stage ) );
	_scene = ScenePtr( new SceneTitle );
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
	case Scene::NEXT_SELECT_1PLAYER:
	case Scene::NEXT_SELECT_2PLAYER:
		_solo = ( next == Scene::NEXT_SELECT_1PLAYER );
		_stage = 0;
		_scene = ScenePtr( new SceneGate( _stage ) );
		break;
	case Scene::NEXT_STREET:
		_scene = ScenePtr( new SceneStreet( _solo ) );
		break;
	}
}