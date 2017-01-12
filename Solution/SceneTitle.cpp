#include "SceneTitle.h"
#include "Tarosuke.h"
#include "Drawer.h"
#include "Device.h"

static const int TITLE_WIDTH  = 1024;
static const int TITLE_HEIGHT = 256;
static const int TITLE_CENTER_X = 1280 / 2;
static const int TITLE_CENTER_Y = 180;
static const int PANEL_WIDTH  = 266;
static const int PANEL_HEIGHT = 272;
static const int PANEL_PITCH = 192;
static const int FPC = 5;

SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_FONT,  "title/Yokai_UI_title_font.png"  );
	drawer->loadGraph( GRAPH_FRAME, "title/Yokai_UI_title_frame.png" );
	drawer->loadGraph( GRAPH_PANEL, "title/Yokai_UI_title_panel.png" );

	_count = 0;
	_finish = false;
}

SceneTitle::~SceneTitle( ) {
}

Scene::NEXT SceneTitle::update( ) {
	act( );
	draw( );

	if ( _finish ) {
		return NEXT_STREET;
	}

	return NEXT_CONTINUE;
}


void SceneTitle::act( ) {
	_count++;

	DevicePtr device = Device::getTask( );
	if ( device->getButton( ) != 0 ) {
		_finish = true;
	}
}

void SceneTitle::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );

	Drawer::Sprite sprite_font( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_FONT );
	drawer->setSprite( sprite_font );

	Drawer::Sprite sprite_frame( 
		Drawer::Transform( TITLE_CENTER_X - TITLE_WIDTH / 2, TITLE_CENTER_Y - TITLE_HEIGHT / 2),
		GRAPH_FRAME );
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
			GRAPH_PANEL );
		drawer->setSprite( sprite_panel);
	}
}
