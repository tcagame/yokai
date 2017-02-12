#include "SceneInfo.h"
#include "define.h"
#include "Drawer.h"
#include "Device.h"
#include "Game.h"
#include "Sound.h"

static const int COUNT_FINISH = 60 * 15;

SceneInfo::SceneInfo( ) :
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_INFO_BG, "info/info_bg.png" );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_01.wav", false );
}


SceneInfo::~SceneInfo( ) {
}

Scene::NEXT SceneInfo::update( ) {
	_count++;

	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) != 0 ) {
		GamePtr game = Game::getTask( );
		game->setFade( Game::FADE_COVER );
		return NEXT_TITLE;
	}
	if ( _count > COUNT_FINISH  ) {
		return NEXT_TITLE;
	}

	DrawerPtr drawer = Drawer::getTask( );
	
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( -_count, 0 ), GRAPH_INFO_BG );
		drawer->setSprite( sprite );
	}

	return NEXT_CONTINUE;
}

