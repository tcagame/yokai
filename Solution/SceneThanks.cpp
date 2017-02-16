#include "SceneThanks.h"
#include "Drawer.h"
#include "define.h"
#include "Game.h"
#include "Sound.h"

static const int NEXT_TIME = 600;
static const int FADEOUT_COUNT = 120;
static const int FADEIN_COUNT = 240;

SceneThanks::SceneThanks( ) :
_next_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_THANKS_BG   , "thanks/thanks_bg.png" );
	drawer->loadGraph( GRAPH_THANKS_PLATE, "thanks/thanks_plate.png" );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_13.wav" );
}


SceneThanks::~SceneThanks( ) {
}

Scene::NEXT SceneThanks::update( ) {
	DrawerPtr drawer = Drawer::getTask( );
	{
		Drawer::Transform trans = Drawer::Transform( 0, 0 );
		Drawer::Sprite sprite( trans, GRAPH_THANKS_BG );
		drawer->setSprite( sprite );
	}
	{
		double alpha = _next_count * 1.0 / FADEIN_COUNT;
		if ( alpha > 1.0 ) {
			alpha = 1.0;
		}
		Drawer::Transform trans = Drawer::Transform( ( SCREEN_WIDTH - 1024 ) / 2, SCREEN_HEIGHT - 256 );
		Drawer::Sprite sprite( trans, GRAPH_THANKS_PLATE, Drawer::BLEND_ALPHA, alpha );
		drawer->setSprite( sprite );
	}

	GamePtr game = Game::getTask( );

	switch (  game->getFade( )  ) {
	case Game::FADE_NONE:
		_next_count++;
		if ( _next_count > NEXT_TIME - FADEOUT_COUNT ) {
			SoundPtr sound = Sound::getTask( );
			//sound->setVolumeBGM( 1.0 - ( double )( _next_count - ( NEXT_TIME - FADEOUT_COUNT ) ) / FADEOUT_COUNT );
		}
		if( _next_count > NEXT_TIME ) {
			game->setFade( Game::FADE_OUT );
		}
		break;
	case Game::FADE_COVER:
		return NEXT_TITLE;
	}

	return NEXT_CONTINUE;
}