#include "SceneResult.h"
#include "Game.h"
#include "Device.h"
#include "Drawer.h"
#include "Sound.h"
#include "define.h"

static const int FRAME_WIDTH  = 896;
static const int FRAME_HEIGHT = 772;
static const int ANIMELOCK_COUNT = 420;
static const int PHASE_COUNT = 30;
static const int NUMERIC_SIZE = 100;
static const int ONLY_FLAME_TIME = 700;
static const int WAIT_FADE_OUT_TIME = 300;

PTR( Infomation );

SceneResult::SceneResult( ) :
_count( 0 ),
_offset_y( 1000 ),
_vy( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	SoundPtr sound = Sound::getTask( );
	GamePtr game = Game::getTask( );

	_continue_count = game->getContinueCount( );
	if ( _continue_count == 0 ) {
		_level = 4;
	} else if ( _continue_count <= 1 ) {
		_level = 3;
	} else if ( _continue_count <= 3 ) {
		_level = 2;
	} else if ( _continue_count <= 5 ) {
		_level = 1;
	} else {
		_level = 0;
	}
	
	drawer->loadGraph( GRAPH_RESULT_FONT_NUMBER, "result/number/result_font_number.png" );
	if ( _continue_count == 0 ) {
		drawer->loadGraph( GRAPH_RESULT_FONT_PLATE, "result/number/result_font_perfect.png" );
	} else {
		drawer->loadGraph( GRAPH_RESULT_FONT_PLATE, "result/number/result_font_plate.png" );
	}

	switch ( _level ) {
	case 4:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/heaven/heaven_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/heaven/heaven_obj.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 3:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/human/human_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/human/human_obj.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 2:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/damn/damn_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/damn/damn_obj.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 1:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hungry/hungry_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hungry/hungry_obj.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 0:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hell/hell_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hell/hell_obj.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	}
}


SceneResult::~SceneResult( ) {
}

Scene::NEXT SceneResult::update( ) {
	_count++;

	_vy += -1;
	_offset_y += _vy;

	if ( _offset_y < 40 ) {
		_offset_y = 40;
		_vy = -_vy * 6 / 10;
	}

	drawFrame( );

	switch ( _level ) {
	case 4: drawHeaven( ); break;
	case 3: drawHuman( ); break;
	case 2: drawDamn( ); break;
	case 1: drawHungry( ); break;
	case 0: drawHell( ); break;
	}

	drawNumber( );

	GamePtr game = Game::getTask( );

	if ( _count > WAIT_FADE_OUT_TIME ) {
		if ( game->getFade( ) == Game::FADE_NONE ) {
			DevicePtr device = Device::getTask( );
			if ( ( device->getPush( ) != 0 ) ) {
				game->setFade( Game::FADE_OUT );
			}
		}
	}

	if ( game->getFade( ) == Game::FADE_COVER ) {
		return NEXT_THANKS;
	}
	return NEXT_CONTINUE;
}

void SceneResult::drawNumber( ) {
	double alpha = _count / 120.0 - 1.0;
	if ( alpha < 0 ) {
		alpha = 0;
	}
	if ( alpha > 1.0 ) {
		alpha = 1.0;
	}

	DrawerPtr drawer = Drawer::getTask( );

	{
		Drawer::Transform trans( ( SCREEN_WIDTH - 1024 ) / 2, SCREEN_HEIGHT - 72 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_FONT_PLATE, Drawer::BLEND_ALPHA, alpha );
		drawer->setSprite( sprite );
	}

	{
		int n = _continue_count;
		int x = ( SCREEN_WIDTH - 1024 ) / 2 + 800;
		while ( n > 0 ) {
			Drawer::Transform trans(
				x, SCREEN_HEIGHT - 72,
				n % 10 * 72, 0, 72, 72 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_FONT_NUMBER, Drawer::BLEND_ALPHA, alpha );
			drawer->setSprite( sprite );

			n /= 10;
			x -= 50;
		}
	}
}

void SceneResult::drawFrame( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( ( SCREEN_WIDTH - FRAME_WIDTH ) / 2, ( SCREEN_HEIGHT - FRAME_HEIGHT ) / 2 - _offset_y );
	Drawer::Sprite sprite( trans, GRAPH_RESULT_FRAME, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void SceneResult::drawHeaven( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count > ANIMELOCK_COUNT - 170 && _count < ANIMELOCK_COUNT - 120 ) {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 430 - _offset_y, ( _count / 4 % 2 ) * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 430 - _offset_y, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}

	{// “V—‰œ¶
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 350, 350 - _offset_y, ANIM[ ( _count + 12 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// “V—‰œ‰E
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 820, 360 - _offset_y, ANIM[ ( _count + 0 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// “V—Žè‘O¶
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 450, 350 - _offset_y, ANIM[ ( _count + 12 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// “V—Žè‘O‰E
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 720, 360 - _offset_y, ANIM[ ( _count + 0 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// ‹à‚Ì’¹1
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1280 - _count % 300 * 5, 150 + ( int )( sin( _count * PI / 120 ) * 50 ) - _offset_y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// ‹à‚Ì’¹2
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1330 - _count % 300 * 5, 180 + ( int )( sin( _count * PI / 120 ) * 50 ) - _offset_y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// ‹à‚Ì’¹3
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1350 - _count % 300 * 5, 130 + ( int )( sin( _count * PI / 120 ) * 50 ) - _offset_y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void SceneResult::drawHuman( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count < ANIMELOCK_COUNT - 29 ) {
		if ( _count > ANIMELOCK_COUNT - 84 ) {
			{// ‚½‚ë‚·‚¯
				const int ANIM[ 7 ] = { 0, 1, 2, 3, 3, 3, 3 };
				Drawer::Transform trans( 360, 400 - _offset_y, ANIM[ _count / 8 % 7 ] * 128, 0, 128, 128 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		} else {
			{// ‚½‚ë‚·‚¯
				Drawer::Transform trans( 360, 400 - _offset_y, 0, 0, 128, 128 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		}

		{// •ƒH
			Drawer::Transform trans( 590, 410 - _offset_y, ( _count / 8 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// •êH
			const int ANIM[ 6 ] = { 0, 0, 0, 0, 0, 1 };
			Drawer::Transform trans( 710, 480 - _offset_y, ANIM[ _count / 4 % 6 ] * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚`
			Drawer::Transform trans( 710, 355 - _offset_y, ( ( _count + 12 ) / 8 % 2 ) * 128, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚a
			const int ANIM[ 4 ] = { 0, 0, 0, 1 };
			Drawer::Transform trans( 830, 350 - _offset_y, ANIM[ ( _count + 12 ) / 4 % 4 ] * 128, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count >= ANIMELOCK_COUNT - 29 && _count < ANIMELOCK_COUNT - 7 ) {
		{// ‚½‚ë‚·‚¯
			const int ANIM[ 6 ] = { 0, 1, 0, 1, 2, 1 };
			Drawer::Transform trans( 360, 400 - _offset_y, ANIM[ _count / 8 % 6 ] * 128 + 640, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// •ƒH
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 590, 410 - _offset_y, ANIM[ _count / 8 % 4 ] * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// •êH
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 710, 480 - _offset_y, ANIM[ _count / 8 % 4 ] * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚`
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 710, 355 - _offset_y, ANIM[ _count / 8 % 4 ] * 128 + 256, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚a
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 830, 350 - _offset_y, ANIM[ _count / 8 % 4 ] * 128 + 256, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

	} else {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 360, 400 - _offset_y, 768, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// •ƒH
			Drawer::Transform trans( 590, 410 - _offset_y, ( _count / 8 % 2 ) * 128 + 768, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// •êH
			Drawer::Transform trans( 710, 480 - _offset_y, ( _count / 8 % 2 ) * 128 + 768, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚`
			Drawer::Transform trans( 710, 355 - _offset_y, ( _count / 8 % 2 ) * 128 + 640, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// eÊ‚a
			Drawer::Transform trans( 830, 350 - _offset_y, ( _count / 8 % 2 ) * 128 + 768, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void SceneResult::drawDamn( ) {
	DrawerPtr drawer = Drawer::getTask( );

	{// ƒJƒ‰ƒX
		Drawer::Transform trans( 850 - _count, 200 - _offset_y, ( _count / 4 % 2 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	if ( _count < ANIMELOCK_COUNT - 84 ) {
		{// “Ø‚ë‚·‚¯
			Drawer::Transform trans( 650, 480 - _offset_y, ( _count / 8 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‚¨‚¶‚¢‚³‚ñ
			Drawer::Transform trans( 380, 450 - _offset_y, ( _count / 8 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// “ØÊß²¾Ý
			Drawer::Transform trans( 730, 485 - _offset_y, 0, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count >= ANIMELOCK_COUNT - 84 && _count <= ANIMELOCK_COUNT - 29 ) {
		if ( _count >= ANIMELOCK_COUNT - 68 && _count <= ANIMELOCK_COUNT - 37 ) {
			{// ƒn[ƒg
				Drawer::Transform trans( 715, 440 - _offset_y, ( _count / 8 % 4 ) * 128 + 128, 384, 64, 64 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		}
		{// “Ø‚ë‚·‚¯
			Drawer::Transform trans( 650, 480 - _offset_y, ( _count / 8 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‚¨‚¶‚¢‚³‚ñ
			Drawer::Transform trans( 380, 450 - _offset_y, ( _count / 4 % 2 ) * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		
		{// “ØÊß²¾Ý
			const int ANIM[ 7 ] = { 0, 1, 2, 2, 2, 2, 1 };
			Drawer::Transform trans( 730, 485 - _offset_y, ANIM[ _count / 8 % 7 ] * 128 + 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// “Ø‚ë‚·‚¯
			Drawer::Transform trans( 650, 480 - _offset_y, ( _count / 4 % 2 ) * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‚¨‚¶‚¢‚³‚ñ
			Drawer::Transform trans( 380, 450 - _offset_y, ( _count / 4 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// “ØÊß²¾Ý
			Drawer::Transform trans( 730, 485 - _offset_y, 0, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void SceneResult::drawHungry( ) {
	DrawerPtr drawer = Drawer::getTask( );

	int food_y = _count - 250;
	int y = food_y * 10 + 500;

	if ( y > 450 ) {
		y = 450;
	}

	if ( _count < ANIMELOCK_COUNT - 148 )  {
		{// ‚½‚ë‚·‚¯
			const int ANIM[ 3 ] = { 0, 0, 1 };
			Drawer::Transform trans( 575, 325 - _offset_y, ANIM[ _count / 8 % 3 ] * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‰ì‹S¶
			Drawer::Transform trans( 375, 420 - _offset_y, ( _count / 4 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// ‰ì‹S‰E
			Drawer::Transform trans( 770, 420 - _offset_y, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count < ANIMELOCK_COUNT - 90 ) {
		{// ‚½‚ë‚·‚¯
			const int ANIM[ 4 ] = { 0, 0, 0, 1 };
			Drawer::Transform trans( 575, 325 - _offset_y, ANIM[ _count / 8 % 4 ] * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‰ì‹S¶
			Drawer::Transform trans( 375, 420 - _offset_y, _count / 4 % 2 * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// ‰ì‹S‰E
			const int ANIM[ 4 ] = { 0, 1, 2, 1 };
			Drawer::Transform trans( 770, 420 - _offset_y, ANIM[ _count / 4 % 4 ] * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count < ANIMELOCK_COUNT ) {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 325 + ( ( _count / 3 ) - 103 ) - _offset_y, ( _count / 16 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// ‰ì‹S¶
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 375 + ( _count - 310 ), 420 - _offset_y, ANIM[ _count / 6 % 6 ] * 128 + 512, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// ‰ì‹S‰E
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 770 - ( _count - 310 ), 420 - _offset_y, ANIM[ _count / 6 % 6 ] * 128, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// Žè‘«
			Drawer::Transform trans( ( _count / 15 % 4 ) * 60 + 530, ( _count / 24 % 4 ) * 60 + 390 - _offset_y, ( _count / 32 % 4 ) * 64 + 512, 448, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// Šç
			Drawer::Transform trans( ( _count / 13 % 3 ) * 80 + 520, ( _count / 7 % 3 ) * 80 + 380 - _offset_y, ( _count / 32 % 3 ) * 64 + 768, 448, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// ƒPƒ“ƒJ‰Œ
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 510, 370 - _offset_y, ANIM[ _count / 4 % 6 ] * 256, 512, 256, 256 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}

	if ( _count > ANIMELOCK_COUNT - 220 && _count < ANIMELOCK_COUNT ) {
		{// H‚×•¨
			Drawer::Transform trans( 610, y - _offset_y, ( _count / 4 % 4 ) * 64 + 640, 384, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void SceneResult::drawHell( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count < ANIMELOCK_COUNT - 20 ) {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 420 - _offset_y, ( _count / 4 % 4 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count <= ANIMELOCK_COUNT - 13 ) {
		{// ‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 420 - _offset_y, ( _count / 4 % 2 ) * 128 + 512, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// “M‚ê‚é‚½‚ë‚·‚¯
			Drawer::Transform trans( 575, 420 - _offset_y, ( _count / 4 % 2 ) * 128 + 768, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
	
	{// ‹S
		const int ANIM[ 6 ] = { 3, 2, 1, 0, 1, 2 };
		Drawer::Transform trans( 550, 260 - _offset_y, ANIM[ _count / 4 % 4 ] * 256, 0, 256, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// —q‚Ì‰Î1
		Drawer::Transform trans( 550, 550 - _offset_y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// —q‚Ì‰Î2
		Drawer::Transform trans( 580, 550 - _offset_y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// —q‚Ì‰Î3
		Drawer::Transform trans( 610, 550 - _offset_y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// —q‚Ì‰Î4
		Drawer::Transform trans( 640, 550 - _offset_y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// —q‚Ì‰Î5
		Drawer::Transform trans( 670, 550 - _offset_y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}
