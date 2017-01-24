#include "Game.h"
#include "SceneTitle.h"
#include "SceneGate.h"
#include "SceneStreet.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Application.h"

GamePtr Game::getTask( ) {
	ApplicationPtr fw = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( fw->getTask( Game::getTag( ) ) );
}

Game::Game( ) :
_debug( false ) {
}


Game::~Game( ) {

}

void Game::initialize( ) {
	_solo = true;
	_stage = 0;
	_scene = ScenePtr( new SceneStreet( ) );
	//_scene = ScenePtr( new SceneGate( _stage ) );
	//_scene = ScenePtr( new SceneTitle );
}

bool Game::isDebug( ) const {
	return _debug;
}

bool Game::isSolo( ) const {
	return _solo;
}

int Game::getStage( ) const {
	return _stage;
}

void Game::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "SPACE" ) ) {
		_debug = !_debug;
	}

	Scene::NEXT next = _scene->update( );

	if ( next == Scene::NEXT_CONTINUE ) {
		return;
	}

	
	_scene.reset( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->unloadAllGraph( );

	switch ( next ) {
	case Scene::NEXT_TITLE:
		_scene = ScenePtr( new SceneTitle );
		break;
	case Scene::NEXT_SELECT_1PLAYER:
	case Scene::NEXT_SELECT_2PLAYER:
		_solo = ( next == Scene::NEXT_SELECT_1PLAYER );
		_stage = 0;
	case Scene::NEXT_GATE:
		_scene = ScenePtr( new SceneGate( ) );
		break;
	case Scene::NEXT_STREET:
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	}
}