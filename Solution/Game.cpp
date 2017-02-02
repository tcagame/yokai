#include "Game.h"
#include "SceneTitle.h"
#include "SceneGate.h"
#include "SceneStreet.h"
#include "SceneResult.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Application.h"
#include "define.h"
#include "Drawer.h"
#include "Sound.h"
#include <stdarg.h>

static const int PANEL_WIDTH  = 266;
static const int PANEL_HEIGHT = 272;
static const int PANEL_PITCH = 192;
static const int PANEL_COL = SCREEN_WIDTH  / PANEL_PITCH + 2;
static const int PANEL_ROW = SCREEN_HEIGHT / PANEL_PITCH + 2;
static const int FADE_COUNT = 60;

GamePtr Game::getTask( ) {
	ApplicationPtr fw = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( fw->getTask( Game::getTag( ) ) );
}

Game::Game( ) :
_debug( false ),
_solo( true ),
_stage( 0 ),
_demo_count( 0 ),
_fade( FADE_NONE ) {

}


Game::~Game( ) {

}

void Game::initialize( ) {
	changeScene( Scene::NEXT_TITLE );
}

bool Game::isDebug( ) const {
	return _debug;
}

bool Game::isSolo( ) const {
	return _solo;
}

bool Game::isDemo( ) const {
	return _demo;
}

int Game::getStage( ) const {
	return _stage;
}

void Game::update( ) {
	Scene::NEXT next = _scene->update( );
	fade( );
	option( );
	changeScene( next );
}

Game::FADE Game::getFade( ) const {
	return _fade;
}

void Game::setFade( FADE fade ) {
	_fade = fade;
}

void Game::fade( ) {
	switch ( _fade ) {
	case FADE_IN:
		_fade_count++;
		if ( _fade_count >= FADE_COUNT ) {
			_fade = FADE_NONE;
			return;
		}
		break;
	case FADE_NONE:
		_fade_count = FADE_COUNT;
		return;
	case FADE_OUT:
		_fade_count--;
		if ( _fade_count < 0 ) {
			_fade = FADE_COVER;
			_fade_count = 0;
		}
		break;
	case FADE_COVER:
		_fade_count = 0;
		break;
	}

	for ( int i = 0; i < PANEL_COL; i++ ) {
		for ( int j = 0; j < PANEL_ROW; j++ ) {
			int sx = -PANEL_WIDTH  / 2 + i * PANEL_PITCH;
			int sy = -PANEL_HEIGHT / 2 + j * PANEL_PITCH;
			int num = _fade_count / 3 - ( i + j * 2 );
			if ( num > 4 ) {
				continue;
			}
			if ( num < 0 ) {
				num = 0;
			}
			int tx = num * PANEL_WIDTH;
			DrawerPtr drawer = Drawer::getTask( );
			Drawer::Transform trans( sx, sy, tx, 0, PANEL_WIDTH, PANEL_HEIGHT );
			Drawer::Sprite sprite( trans, GRAPH_TITLE_PANEL, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void Game::option( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "SPACE" ) ) {
		_debug = !_debug;
	}

	if ( _debug ) {
		int x = 0;
		int y = 0;
		DrawerPtr drawer = Drawer::getTask( );
		std::list< std::string >::iterator it = _debug_message.begin( );
		while ( it != _debug_message.end( ) ) {
			std::string& str = *it;
			drawer->drawString( x, y, str.c_str( ) );
			y += 20;
			it++;
		}
	}
	_debug_message.clear( );
}

void Game::changeScene( Scene::NEXT next ) {
	if ( next == Scene::NEXT_CONTINUE ) {
		return;
	}

	_scene.reset( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->unloadAllGraph( );

	SoundPtr sound = Sound::getTask( );
	sound->stopAllSE( );
	sound->stopBGM( );
	_demo = false;

	switch ( next ) {
	case Scene::NEXT_TITLE:
		_scene = ScenePtr( new SceneTitle );
		break;
	case Scene::NEXT_DEMO:
		_demo_count++;
		_demo = true;
		_solo = ( _demo_count / 5 % 2 == 0 );
		_stage = _demo_count % 5;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_SELECT_1PLAYER:
	case Scene::NEXT_SELECT_2PLAYER:
		_solo = ( next == Scene::NEXT_SELECT_1PLAYER );
		_demo = false;
		_stage = 0;
		_scene = ScenePtr( new SceneGate( ) );
		break;
	case Scene::NEXT_STAGE:
		_stage++;
		if ( _stage < 5 ) {
			_scene = ScenePtr( new SceneGate( ) );
		} else if ( _stage == 5 ) {
			_scene = ScenePtr( new SceneResult );
		} else {
			_scene = ScenePtr( new SceneTitle );
		}
		break;
	case Scene::NEXT_STREET:
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_RESULT:
		_scene = ScenePtr( new SceneResult( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_0:
		_stage = 0;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_1:
		_stage = 1;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_2:
		_stage = 2;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_3:
		_stage = 3;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_4:
		_stage = 4;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_STREET_TEST:
		_stage = 5;
		_scene = ScenePtr( new SceneStreet( ) );
		break;
	case Scene::NEXT_DEBUG_RESULT_1:
		_stage = 1;
		_scene = ScenePtr( new SceneResult( ) );
		break;
	case Scene::NEXT_DEBUG_RESULT_2:
		_stage = 2;
		_scene = ScenePtr( new SceneResult( ) );
		break;
	case Scene::NEXT_DEBUG_RESULT_3:
		_stage = 3;
		_scene = ScenePtr( new SceneResult( ) );
		break;
	case Scene::NEXT_DEBUG_RESULT_4:
		_stage = 4;
		_scene = ScenePtr( new SceneResult( ) );
		break;
	case Scene::NEXT_DEBUG_RESULT_5:
		_stage = 5;
		_scene = ScenePtr( new SceneResult( ) );
		break;
	}
	
	drawer->loadGraph( GRAPH_TITLE_PANEL, "title/Yokai_UI_title_panel.png" );

	setFade( FADE_IN );
}

void Game::addDebugMessage( const char* string, ... ) {
	char buf[ 1024 ];
	va_list ap;
	unsigned int color = 0xFFFFFF;
	va_start( ap, string );
	vsprintf_s( buf, 1024, string, ap );
	std::string str = buf;
	_debug_message.push_back( str );
	va_end( ap );
}
