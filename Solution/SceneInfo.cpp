#include "SceneInfo.h"
#include "define.h"
#include "Drawer.h"
#include "Device.h"
#include "Game.h"
#include "Sound.h"

static const int COUNT_FINISH = 60 * 15;
static const int PARTICLE_SIZE = 32;
static const int DIV = 200;

SceneInfo::SceneInfo( ) :
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_INFO_BG      , "info/info_bg.png" );
	drawer->loadGraph( GRAPH_INFO_TITLE   , "info/info_title.png" );
	drawer->loadGraph( GRAPH_INFO_PARTICLE, "info/info_particle.png" );

	static int select = 0;
	select = ( select + 1 ) % ( 6 * 3 );

	switch ( select % 6 ) {
	case 0: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_ito.png" ); break;
	case 1: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_yokoyama.png" ); break;
	case 2: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_iwafune.png" ); break;
	case 3: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_saito.png" ); break;
	case 4: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_kase.png" ); break;
	case 5: drawer->loadGraph( GRAPH_INFO_NAME    , "info/info_name_yamada.png" ); break;
	}

	switch ( select ) {
	case  0: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_ito_1.png" ); break;
	case  1: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yokoyama_1.png" ); break;
	case  2: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_iwafune_1.png" ); break;
	case  3: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_saito_1.png" ); break;
	case  4: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_kase_1.png" ); break;
	case  5: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yamada_1.png" ); break;
	case  6: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_ito_2.png" ); break;
	case  7: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yokoyama_2.png" ); break;
	case  8: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_iwafune_2.png" ); break;
	case  9: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_saito_2.png" ); break;
	case 10: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_kase_2.png" ); break;
	case 11: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yamada_2.png" ); break;
	case 12: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_ito_3.png" ); break;
	case 13: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yokoyama_3.png" ); break;
	case 14: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_iwafune_3.png" ); break;
	case 15: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_saito_3.png" ); break;
	case 16: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_kase_3.png" ); break;
	case 17: drawer->loadGraph( GRAPH_INFO_MESSAGE, "info/info_message_yamada_3.png" ); break;
	}

	_data[ 0 ].graph = GRAPH_INFO_TITLE;
	_data[ 0 ].target = Vector( 0, 0 );
	_data[ 0 ].width = 512;
	_data[ 0 ].height= 128;

	_data[ 1 ].graph = GRAPH_INFO_NAME;
	_data[ 1 ].target = Vector( 650, 64 );
	_data[ 1 ].width = 512;
	_data[ 1 ].height= 128;

	_data[ 2 ].graph = GRAPH_INFO_MESSAGE;
	_data[ 2 ].target = Vector( ( 1280 - 1024 ) / 2, 720 - 512 );
	_data[ 2 ].width = 1024;
	_data[ 2 ].height= 512;

	for ( int i = 0; i < 3; i++ ) {
		_data[ i ].pos = Vector(
			( SCREEN_WIDTH  - _data[ i ].width  ) / 2,
			( SCREEN_HEIGHT - _data[ i ].height ) / 2 );
		_data[ i ].count = 0;
	}
	
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

	int num = _count / ( COUNT_FINISH / 12 );
	if ( num > 3 ) {
		num = 3;
	}
	for ( int i = 0; i < num; i++ ) {
		_data[ i ].count++;
		double alpha = 1.0;
		if ( _data[ i ].count < 30 ) {
			alpha = _data[ i ].count / 30.0;
		} else if ( _data[ i ].count < 45 ) {
			int length = _data[ i ].width * ( _data[ i ].count - 30 ) / 15;
			for ( int j = 0; j < DIV; j++ ) {
				{
					int x = ( int )_data[ i ].pos.x - PARTICLE_SIZE / 2 + length * j / DIV;
					int y = ( int )_data[ i ].pos.y - PARTICLE_SIZE / 2;
					Drawer::Sprite sprite( 
						Drawer::Transform( x, y ),
						GRAPH_INFO_PARTICLE, Drawer::BLEND_ADD, 0.1 );
					drawer->setSprite( sprite );
				}
				{
					int x = ( int )_data[ i ].pos.x - PARTICLE_SIZE / 2 - length * j / DIV + _data[ i ].width;
					int y = ( int )_data[ i ].pos.y - PARTICLE_SIZE / 2 + _data[ i ].height;
					Drawer::Sprite sprite( 
						Drawer::Transform( x, y ),
						GRAPH_INFO_PARTICLE, Drawer::BLEND_ADD, 0.1 );
					drawer->setSprite( sprite );
				}
			}
		} else if ( _data[ i ].count < 60 ) {
			int length = ( int )( _data[ i ].width * ( 1.0 - ( _data[ i ].count - 45 ) / 15.0 ) );
			for ( int j = 0; j < DIV; j++ ) {
				{
					int x = ( int )_data[ i ].pos.x - PARTICLE_SIZE / 2 - length * j / DIV + _data[ i ].width;
					int y = ( int )_data[ i ].pos.y - PARTICLE_SIZE / 2;
					Drawer::Sprite sprite( 
						Drawer::Transform( x, y ),
						GRAPH_INFO_PARTICLE, Drawer::BLEND_ADD, 0.1 );
					drawer->setSprite( sprite );
				}
				{
					int x = ( int )_data[ i ].pos.x - PARTICLE_SIZE / 2 + length * j / DIV;
					int y = ( int )_data[ i ].pos.y - PARTICLE_SIZE / 2 + _data[ i ].height;
					Drawer::Sprite sprite( 
						Drawer::Transform( x, y ),
						GRAPH_INFO_PARTICLE, Drawer::BLEND_ADD, 0.1 );
					drawer->setSprite( sprite );
				}
			}
		} else {
			Vector vec = _data[ i ].target - _data[ i ].pos;
			_data[ i ].pos += vec * 0.1;
		}

		Drawer::Sprite sprite( 
			Drawer::Transform( ( int )_data[ i ].pos.x, ( int )_data[ i ].pos.y ),
			_data[ i ].graph, Drawer::BLEND_ALPHA, alpha );
		drawer->setSprite( sprite );
	}

	return NEXT_CONTINUE;
}

