#include "SceneTitle.h"
#include "Tarosuke.h"
#include "Drawer.h"
#include "Sound.h"
#include "Device.h"
#include "Define.h"
#include "Keyboard.h"
#include "Game.h"
#include "Infomation.h"
#include <time.h>

static const int TITLE_WIDTH  = 1024;
static const int TITLE_HEIGHT = 256;
static const int TITLE_CENTER_X = 1280 / 2;
static const int TITLE_CENTER_Y = 180;
static const int CHOICE_FONT_X = 420;
static const int CHOICE_FONT_Y = 350;
static const int CHOICE_CURSORY_X = 350;
static const int CHOICE_CURSORY_Y = 400;
static const int PANEL_WIDTH  = 266;
static const int PANEL_HEIGHT = 272;
static const int PANEL_PITCH = 192;
static const int FPC = 5;
static const int SELECT_X = 600;
static const int SELECT_Y = 500;
static const int DEMO_COUNT = 600;
static const int TAROSUKE_SPEED = 10;
static const int TAROSUKE_ACCEL = 1;

SceneTitle::SceneTitle( ) {
	srand( ( unsigned int )time( NULL ) );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER_1 , "Character/Character1.png");
	drawer->loadGraph( GRAPH_TITLE_FONT  , "title/Yokai_UI_title_font.png"  );
	drawer->loadGraph( GRAPH_TITLE_FRAME , "title/Yokai_UI_title_frame.png" );
	drawer->loadGraph( GRAPH_TITLE_PANEL , "title/Yokai_UI_title_panel.png" );
	drawer->loadGraph( GRAPH_PLAYERCHOICE, "title/status_player_choice.png");
	drawer->loadGraph( GRAPH_CURSOR      , "title/cursory.png" );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_03.wav" );

	_count = 0;
	_panel_count = 0;
	_select = 0;
	
	_tarosuke_x = TITLE_CENTER_X + 400;
	_tarosuke_vx = 0;
	_tarosuke_right = false;
	_tarosuke_move = true;
}

SceneTitle::~SceneTitle( ) {
}

Scene::NEXT SceneTitle::update( ) {
	act( );
	draw( );
	
	if ( _count > DEMO_COUNT ) {
		return NEXT_DEMO;
	}

	GamePtr game = Game::getTask( );
	if ( game->getFade( ) == Game::FADE_COVER ) {
		if ( _select == 0 ) {
			return NEXT_SELECT_1PLAYER;
		} else {
			return NEXT_SELECT_2PLAYER;
		}
	}

	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "F9" ) ) {
		Infomation( false ); // データクリア
	}
	if ( keyboard->isPushKey( "ENTER" ) ) {
		return NEXT_DEBUG_STREET_TEST;
	}
	if ( keyboard->isPushKey( "NUM0" ) ) {
		return NEXT_DEBUG_STREET_0;
	}
	if ( keyboard->isPushKey( "NUM1" ) ) {
		return NEXT_DEBUG_STREET_1;
	}
	if ( keyboard->isPushKey( "NUM2" ) ) {
		return NEXT_DEBUG_STREET_2;
	}
	if ( keyboard->isPushKey( "NUM3" ) ) {
		return NEXT_DEBUG_STREET_3;
	}
	if ( keyboard->isPushKey( "NUM4" ) ) {
		return NEXT_DEBUG_STREET_4;
	}
	if ( keyboard->isPushKey( "1" ) ) {
		return NEXT_DEBUG_RESULT_1;
	}
	if ( keyboard->isPushKey( "2" ) ) {
		return NEXT_DEBUG_RESULT_2;
	}
	if ( keyboard->isPushKey( "3" ) ) {
		return NEXT_DEBUG_RESULT_3;
	}
	if ( keyboard->isPushKey( "4" ) ) {
		return NEXT_DEBUG_RESULT_4;
	}
	if ( keyboard->isPushKey( "5" ) ) {
		return NEXT_DEBUG_RESULT_5;
	}

	return NEXT_CONTINUE;
}

void SceneTitle::act( ) {
	_count++;
	_panel_count++;

	if ( _count % 60 == 0 ) {
		_tarosuke_move = ( rand( ) % 3 != 0 );
		if ( _tarosuke_move ) {
			_tarosuke_right = ( rand( ) % 2 == 0 );
		}
	}
	
	if ( _tarosuke_move ) {
		if ( _tarosuke_right ) {
			_tarosuke_vx += TAROSUKE_ACCEL;
			if ( _tarosuke_vx > TAROSUKE_SPEED ) {
				_tarosuke_vx = TAROSUKE_SPEED;
			}
		} else {
			_tarosuke_vx += -TAROSUKE_ACCEL;
			if ( _tarosuke_vx < -TAROSUKE_SPEED ) {
				_tarosuke_vx = -TAROSUKE_SPEED;
			}
		}
	} else {
		if ( _tarosuke_vx > 0 ) {
			_tarosuke_vx -= TAROSUKE_ACCEL;
		}
		if ( _tarosuke_vx < 0 ) {
			_tarosuke_vx += TAROSUKE_ACCEL;
		}
	}

	_tarosuke_x += _tarosuke_vx;
	if ( _tarosuke_x < TITLE_CENTER_X - 400 ) {
		_tarosuke_x = TITLE_CENTER_X - 400;
		_tarosuke_vx = 0;
		_tarosuke_move = true;
		_tarosuke_right = true;
	}
	if ( _tarosuke_x > TITLE_CENTER_X + 400 ) {
		_tarosuke_x = TITLE_CENTER_X + 400;
		_tarosuke_vx = 0;
		_tarosuke_move = true;
		_tarosuke_right = false;
	}
	
	GamePtr game = Game::getTask( );
	if ( game->getFade( ) != Game::FADE_NONE ) {
		return;
	}

	DevicePtr device = Device::getTask( );

	if ( device->getButton( ) != 0 ) {
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_01.wav" );
		game->setFade( Game::FADE_OUT );
	}

	if ( device->getDirY( ) < 0 && _select != 0 ) {
		_select = 0;
		_count = 0;
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_06.wav" );
	}
	if ( device->getDirY( ) > 0 && _select != 1  ) {
		_select = 1;
		_count = 0;
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_06.wav" );
	}

}

void SceneTitle::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	
	Drawer::Sprite sprite_font( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_TITLE_FONT );
	drawer->setSprite( sprite_font );
	
	{
		int sy = TITLE_CENTER_Y - 32;
		int sx1 = _tarosuke_x - 64;
		int sx2 = sx1 + 128;
		if ( _tarosuke_right ) {
			int tmp = sx1;
			sx1 = sx2;
			sx2 = tmp;
		}
		const int ANIM[ 8 ] = { 0, 1, 2, 1, 0, 3, 4, 3 };
		int pattern = ANIM[ _tarosuke_x / 20 % 8 ];
		if ( _tarosuke_vx == 0 ) {
			pattern = 0;
		} else if ( _count % 10 == 9 ) {
			SoundPtr sound = Sound::getTask( );
			sound->playSE( "yokai_voice_15.wav" );
		}
		int tx = pattern * 128;
		Drawer::Sprite sprite( 
			Drawer::Transform( sx1, sy, tx, 0, 128, 128, sx2, sy + 128 ),
			GRAPH_CHARACTER_1 );
		drawer->setSprite( sprite );
	}

	Drawer::Sprite sprite_frame( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_TITLE_FRAME );
	drawer->setSprite( sprite_frame );

	Drawer::Sprite sprite_playerchoice(
		Drawer::Transform( CHOICE_FONT_X, CHOICE_FONT_Y ),
		GRAPH_PLAYERCHOICE );
	drawer->setSprite( sprite_playerchoice );
	
	GamePtr game = Game::getTask( );
	if ( game->getFade( ) != Game::FADE_IN ) {
		Drawer::Sprite sprite_cusory(
			Drawer::Transform( CHOICE_CURSORY_X, CHOICE_CURSORY_Y + _select * 140 ),
			GRAPH_CURSOR );
		drawer->setSprite( sprite_cusory );
	}

	for ( int i = 0; i < 5; i++ ) {
		int x = TITLE_CENTER_X - PANEL_PITCH * 2 + i * PANEL_PITCH - PANEL_WIDTH / 2;
		int y = TITLE_CENTER_Y - PANEL_HEIGHT / 2;
		int tx = abs( ( _panel_count / FPC + i ) % 10 - 3 );
		if ( tx > 3 ) {
			tx = 3;
		}
		tx *= PANEL_WIDTH;
		Drawer::Sprite sprite_panel( 
			Drawer::Transform( x, y, tx, 0, PANEL_WIDTH, PANEL_HEIGHT ),
			GRAPH_TITLE_PANEL );
		drawer->setSprite( sprite_panel);
	}
}
