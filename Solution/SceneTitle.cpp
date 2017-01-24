#include "SceneTitle.h"
#include "Tarosuke.h"
#include "Drawer.h"
#include "Sound.h"
#include "Device.h"
#include "Define.h"
#include "Keyboard.h"

static const int TITLE_WIDTH  = 1024;
static const int TITLE_HEIGHT = 256;
static const int TITLE_CENTER_X = 1280 / 2;
static const int TITLE_CENTER_Y = 180;
static const int PANEL_WIDTH  = 266;
static const int PANEL_HEIGHT = 272;
static const int PANEL_PITCH = 192;
static const int FPC = 5;
static const int SELECT_X = 600;
static const int SELECT_Y = 500;

SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_TITLE_FONT,  "title/Yokai_UI_title_font.png"  );
	drawer->loadGraph( GRAPH_TITLE_FRAME, "title/Yokai_UI_title_frame.png" );
	drawer->loadGraph( GRAPH_TITLE_PANEL, "title/Yokai_UI_title_panel.png" );

	_count = 0;
	_finish = false;
	_select = 0;
}

SceneTitle::~SceneTitle( ) {
}

Scene::NEXT SceneTitle::update( ) {
	act( );
	draw( );

	if ( _finish ) {
		if ( _select == 0 ) {
			return NEXT_SELECT_1PLAYER;
		} else {
			return NEXT_SELECT_2PLAYER;
		}
	}

	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "ENTER" ) ) {
		return NEXT_TEST;
	}

	return NEXT_CONTINUE;
}

void SceneTitle::act( ) {
	_count++;

	DevicePtr device = Device::getTask( );
	if ( device->getButton( ) != 0 ) {
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_01.wav" );
		_finish = true;
	}

	if ( device->getDirY( ) < 0 ) {
		_select = 0;
	}
	if ( device->getDirY( ) > 0 ) {
		_select = 1;
	}
}

void SceneTitle::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );

	Drawer::Sprite sprite_font( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_TITLE_FONT );
	drawer->setSprite( sprite_font );

	Drawer::Sprite sprite_frame( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_TITLE_FRAME );
	drawer->setSprite( sprite_frame);

	for ( int i = 0; i < 5; i++ ) {
		int x = TITLE_CENTER_X - PANEL_PITCH * 2 + i * PANEL_PITCH - PANEL_WIDTH / 2;
		int y = TITLE_CENTER_Y - PANEL_HEIGHT / 2;
		int tx = abs( ( _count / FPC + i ) % 10 - 3 );
		if ( tx > 3 ) {
			tx = 3;
		}
		tx *= PANEL_WIDTH;
		Drawer::Sprite sprite_panel( 
			Drawer::Transform( x, y, tx, 0, PANEL_WIDTH, PANEL_HEIGHT ),
			GRAPH_TITLE_PANEL );
		drawer->setSprite( sprite_panel);
	}

	drawer->drawString( SELECT_X, SELECT_Y +   0, "1P PLAYER GAME" );
	drawer->drawString( SELECT_X, SELECT_Y +  40, "2P PLAYER GAME" );
	drawer->drawString( SELECT_X - 30, SELECT_Y + _select * 40, "Å®" );
}
