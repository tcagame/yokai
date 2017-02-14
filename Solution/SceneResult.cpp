#include "SceneResult.h"
#include "Game.h"
#include "Device.h"
#include "Drawer.h"
#include "Sound.h"
#include "define.h"
#include "Infomation.h"

static const int FRAME_WIDTH  = 896;
static const int FRAME_HEIGHT = 772;
static const int ANIMELOCK_COUNT = 420;
static const int PHASE_COUNT = 30;
static const int NUMERIC_SIZE = 100;
static const int OFFSET_Y = 40;
static const int ONLY_FLAME_TIME = 700;
static const int WAIT_FADE_OUT_TIME = 300;

PTR( Infomation );

SceneResult::SceneResult( ) :
_count( 0 ),
_phase_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	SoundPtr sound = Sound::getTask( );
	GamePtr game = Game::getTask( );
	InfomationPtr info = InfomationPtr( new Infomation );

	_level = game->getStage( ) - 1;
	if ( _level < 0 ) {
		_level = 0;
	}

	info->increasePopulation( _level );
	_population = info->getPopulation( _level );
	
	drawer->loadGraph( GRAPH_GATE_COUNT_0, "result/number/count_0.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_1, "result/number/count_1.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_2, "result/number/count_2.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_3, "result/number/count_3.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_4, "result/number/count_4.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_5, "result/number/count_5.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_6, "result/number/count_6.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_7, "result/number/count_7.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_8, "result/number/count_8.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_9, "result/number/count_9.png" );

	switch ( _level ) {
	case 4:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/heaven/heaven_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/heaven/heaven_obj.png" );
		drawer->loadGraph( GRAPH_RESULT_MSG  , "result/heaven/heaven_message_frame.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 3:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/human/human_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/human/human_obj.png" );
		drawer->loadGraph( GRAPH_RESULT_MSG  , "result/human/human_message_frame.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 2:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/damn/damn_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/damn/damn_obj.png" );
		drawer->loadGraph( GRAPH_RESULT_MSG  , "result/damn/damn_message_frame.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 1:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hungry/hungry_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hungry/hungry_obj.png" );
		drawer->loadGraph( GRAPH_RESULT_MSG  , "result/hungry/hungry_message_frame.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	case 0:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hell/hell_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hell/hell_obj.png" );
		drawer->loadGraph( GRAPH_RESULT_MSG  , "result/hell/hell_message_frame.png" );
		sound->playBGM( "yokai_music_09.wav" );
		break;
	}

	_phase = PHASE_ONLYFRAME;
}


SceneResult::~SceneResult( ) {
}

Scene::NEXT SceneResult::update( ) {
	_count++;

	drawFrame( );

	switch ( _level ) {
	case 4: drawHeaven( ); break;
	case 3: drawHuman( ); break;
	case 2: drawDamn( ); break;
	case 1: drawHungry( ); break;
	case 0: drawHell( ); break;
	}

	drawWindow( );

	_phase_count++;
	
	GamePtr game = Game::getTask( );
	DevicePtr device = Device::getTask( );
	switch ( _phase ) {
	case PHASE_ONLYFRAME:
		if ( ( device->getPush( ) != 0 ) ||
			 ( _phase_count > ONLY_FLAME_TIME ) ) {
			_phase = PHASE_INWINDOW;
			_phase_count = 0;
		}
		break;
	case PHASE_INWINDOW:
		if ( _phase_count > PHASE_COUNT ) {
			_phase = PHASE_INCREASE;
			_phase_count = 0;
		}
		break;
	case PHASE_INCREASE:
		if ( _phase_count > PHASE_COUNT ) {
			_phase = PHASE_WAIT;
			_phase_count = 0;
		}
		break;
	case PHASE_WAIT:
		if ( game->getFade( ) == Game::FADE_NONE ) {
			if ( ( device->getPush( ) != 0 ) ||
				 ( _phase_count > WAIT_FADE_OUT_TIME ) ) {
				game->setFade( Game::FADE_OUT );
			}
		}
		break;
	}

	if ( game->getFade( ) == Game::FADE_COVER ) {
		return NEXT_THANKS;
	}
	return NEXT_CONTINUE;
}

void SceneResult::drawWindow( ) {
	if ( _phase == PHASE_ONLYFRAME ) {
		return;
	}

	double alpha = 1.0;
	if ( _phase == PHASE_INWINDOW ) {
		alpha = ( double )_phase_count / ( PHASE_COUNT / 2 );
	}

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( 70, 570 );
	Drawer::Sprite sprite( trans, GRAPH_RESULT_MSG, Drawer::BLEND_ALPHA, alpha );
	drawer->setSprite( sprite );

	switch ( _phase ) {
	case PHASE_INWINDOW:
		drawNumber( 0, _population - 1, alpha );
		break;
	case PHASE_INCREASE:
		{
			int offset = _phase_count * NUMERIC_SIZE / PHASE_COUNT;
			drawNumber( offset               , _population - 1, 1.0 );
			drawNumber( offset - NUMERIC_SIZE, _population    , 1.0 );
		}
		break;
	case PHASE_WAIT:
		drawNumber( 0, _population, 1.0 );
		break;
	}
}

void SceneResult::drawNumber( int offset, int num, double alpha ) {
	const int GRAPH_NUMERIC[ 10 ] = {
		GRAPH_GATE_COUNT_0,
		GRAPH_GATE_COUNT_1,
		GRAPH_GATE_COUNT_2,
		GRAPH_GATE_COUNT_3,
		GRAPH_GATE_COUNT_4,
		GRAPH_GATE_COUNT_5,
		GRAPH_GATE_COUNT_6,
		GRAPH_GATE_COUNT_7,
		GRAPH_GATE_COUNT_8,
		GRAPH_GATE_COUNT_9,
	};
	const int X[ ] = {
		70 + 800,
		70 + 200,
		70 + 528,
		70 + 800,
		70 + 800,
	};

	int y = 70 + 570 + offset;
	int x = X[ _level ];
	{
		int n = num;
		while ( n >= 10 ) {
			x += NUMERIC_SIZE / 4;
			n /= 10;
		}
	}

	{
		int n = num;
		DrawerPtr drawer = Drawer::getTask( );
		do {
			Drawer::Transform trans( x - NUMERIC_SIZE / 2, y - NUMERIC_SIZE / 2, 0, 0, NUMERIC_SIZE, NUMERIC_SIZE, x + NUMERIC_SIZE / 2, y + NUMERIC_SIZE / 2 );
			Drawer::Sprite sprite( trans, GRAPH_NUMERIC[ n % 10 ], Drawer::BLEND_ALPHA, alpha );
			drawer->setSprite( sprite );

			n /= 10;
			x -= NUMERIC_SIZE / 2;
		} while ( n > 0 );
	}
}

void SceneResult::drawFrame( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( ( SCREEN_WIDTH - FRAME_WIDTH ) / 2, ( SCREEN_HEIGHT - FRAME_HEIGHT ) / 2 - OFFSET_Y );
	Drawer::Sprite sprite( trans, GRAPH_RESULT_FRAME, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void SceneResult::drawHeaven( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count > ANIMELOCK_COUNT - 170 && _count < ANIMELOCK_COUNT - 120 ) {
		{// たろすけ
			Drawer::Transform trans( 575, 430 - OFFSET_Y, ( _count / 4 % 2 ) * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// たろすけ
			Drawer::Transform trans( 575, 430 - OFFSET_Y, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}

	{// 天女奥左
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 350, 350 - OFFSET_Y, ANIM[ ( _count + 12 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女奥右
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 820, 360 - OFFSET_Y, ANIM[ ( _count + 0 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女手前左
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 450, 350 - OFFSET_Y, ANIM[ ( _count + 12 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女手前右
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 720, 360 - OFFSET_Y, ANIM[ ( _count + 0 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 金の鳥1
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1280 - _count % 300 * 5, 150 + ( int )( sin( _count * PI / 120 ) * 50 ) - OFFSET_Y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 金の鳥2
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1330 - _count % 300 * 5, 180 + ( int )( sin( _count * PI / 120 ) * 50 ) - OFFSET_Y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 金の鳥3
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 1350 - _count % 300 * 5, 130 + ( int )( sin( _count * PI / 120 ) * 50 ) - OFFSET_Y, n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void SceneResult::drawHuman( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count < ANIMELOCK_COUNT - 29 ) {
		if ( _count > ANIMELOCK_COUNT - 84 ) {
			{// たろすけ
				const int ANIM[ 7 ] = { 0, 1, 2, 3, 3, 3, 3 };
				Drawer::Transform trans( 360, 400 - OFFSET_Y, ANIM[ _count / 8 % 7 ] * 128, 0, 128, 128 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		} else {
			{// たろすけ
				Drawer::Transform trans( 360, 400 - OFFSET_Y, 0, 0, 128, 128 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		}

		{// 父？
			Drawer::Transform trans( 590, 410 - OFFSET_Y, ( _count / 8 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 母？
			const int ANIM[ 6 ] = { 0, 0, 0, 0, 0, 1 };
			Drawer::Transform trans( 710, 480 - OFFSET_Y, ANIM[ _count / 4 % 6 ] * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ａ
			Drawer::Transform trans( 710, 355 - OFFSET_Y, ( ( _count + 12 ) / 8 % 2 ) * 128, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ｂ
			const int ANIM[ 4 ] = { 0, 0, 0, 1 };
			Drawer::Transform trans( 830, 350 - OFFSET_Y, ANIM[ ( _count + 12 ) / 4 % 4 ] * 128, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count >= ANIMELOCK_COUNT - 29 && _count < ANIMELOCK_COUNT - 7 ) {
		{// たろすけ
			const int ANIM[ 6 ] = { 0, 1, 0, 1, 2, 1 };
			Drawer::Transform trans( 360, 400 - OFFSET_Y, ANIM[ _count / 8 % 6 ] * 128 + 640, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 父？
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 590, 410 - OFFSET_Y, ANIM[ _count / 8 % 4 ] * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 母？
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 710, 480 - OFFSET_Y, ANIM[ _count / 8 % 4 ] * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ａ
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 710, 355 - OFFSET_Y, ANIM[ _count / 8 % 4 ] * 128 + 256, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ｂ
			const int ANIM[ 4 ] = { 0, 1, 2, 3 };
			Drawer::Transform trans( 830, 350 - OFFSET_Y, ANIM[ _count / 8 % 4 ] * 128 + 256, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

	} else {
		{// たろすけ
			Drawer::Transform trans( 360, 400 - OFFSET_Y, 768, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 父？
			Drawer::Transform trans( 590, 410 - OFFSET_Y, ( _count / 8 % 2 ) * 128 + 768, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 母？
			Drawer::Transform trans( 710, 480 - OFFSET_Y, ( _count / 8 % 2 ) * 128 + 768, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ａ
			Drawer::Transform trans( 710, 355 - OFFSET_Y, ( _count / 8 % 2 ) * 128 + 640, 512, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 親戚Ｂ
			Drawer::Transform trans( 830, 350 - OFFSET_Y, ( _count / 8 % 2 ) * 128 + 768, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void SceneResult::drawDamn( ) {
	DrawerPtr drawer = Drawer::getTask( );

	{// カラス
		Drawer::Transform trans( 850 - _count, 200 - OFFSET_Y, ( _count / 4 % 2 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	if ( _count < ANIMELOCK_COUNT - 84 ) {
		{// 豚ろすけ
			Drawer::Transform trans( 650, 480 - OFFSET_Y, ( _count / 8 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// おじいさん
			Drawer::Transform trans( 380, 450 - OFFSET_Y, ( _count / 8 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 豚ﾊﾟｲｾﾝ
			Drawer::Transform trans( 730, 485 - OFFSET_Y, 0, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count >= ANIMELOCK_COUNT - 84 && _count <= ANIMELOCK_COUNT - 29 ) {
		if ( _count >= ANIMELOCK_COUNT - 68 && _count <= ANIMELOCK_COUNT - 37 ) {
			{// ハート
				Drawer::Transform trans( 715, 440 - OFFSET_Y, ( _count / 8 % 4 ) * 128 + 128, 384, 64, 64 );
				Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
				drawer->setSprite( sprite );
			}
		}
		{// 豚ろすけ
			Drawer::Transform trans( 650, 480 - OFFSET_Y, ( _count / 8 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// おじいさん
			Drawer::Transform trans( 380, 450 - OFFSET_Y, ( _count / 4 % 2 ) * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		
		{// 豚ﾊﾟｲｾﾝ
			const int ANIM[ 7 ] = { 0, 1, 2, 2, 2, 2, 1 };
			Drawer::Transform trans( 730, 485 - OFFSET_Y, ANIM[ _count / 8 % 7 ] * 128 + 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// 豚ろすけ
			Drawer::Transform trans( 650, 480 - OFFSET_Y, ( _count / 4 % 2 ) * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// おじいさん
			Drawer::Transform trans( 380, 450 - OFFSET_Y, ( _count / 4 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 豚ﾊﾟｲｾﾝ
			Drawer::Transform trans( 730, 485 - OFFSET_Y, 0, 256, 128, 128 );
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
		{// たろすけ
			const int ANIM[ 3 ] = { 0, 0, 1 };
			Drawer::Transform trans( 575, 325 - OFFSET_Y, ANIM[ _count / 8 % 3 ] * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 餓鬼左
			Drawer::Transform trans( 375, 420 - OFFSET_Y, ( _count / 4 % 2 ) * 128, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// 餓鬼右
			Drawer::Transform trans( 770, 420 - OFFSET_Y, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count < ANIMELOCK_COUNT - 90 ) {
		{// たろすけ
			const int ANIM[ 4 ] = { 0, 0, 0, 1 };
			Drawer::Transform trans( 575, 325 - OFFSET_Y, ANIM[ _count / 8 % 4 ] * 128 + 256, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 餓鬼左
			Drawer::Transform trans( 375, 420 - OFFSET_Y, _count / 4 % 2 * 128 + 256, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// 餓鬼右
			const int ANIM[ 4 ] = { 0, 1, 2, 1 };
			Drawer::Transform trans( 770, 420 - OFFSET_Y, ANIM[ _count / 4 % 4 ] * 128 + 256, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count < ANIMELOCK_COUNT ) {
		{// たろすけ
			Drawer::Transform trans( 575, 325 + ( ( _count / 3 ) - 103 ) - OFFSET_Y, ( _count / 16 % 2 ) * 128, 0, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}

		{// 餓鬼左
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 375 + ( _count - 310 ), 420 - OFFSET_Y, ANIM[ _count / 6 % 6 ] * 128 + 512, 128, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// 餓鬼右
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 770 - ( _count - 310 ), 420 - OFFSET_Y, ANIM[ _count / 6 % 6 ] * 128, 384, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// 手足
			Drawer::Transform trans( ( _count / 15 % 4 ) * 60 + 530, ( _count / 24 % 4 ) * 60 + 390 - OFFSET_Y, ( _count / 32 % 4 ) * 64 + 512, 448, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// 顔
			Drawer::Transform trans( ( _count / 13 % 3 ) * 80 + 520, ( _count / 7 % 3 ) * 80 + 380 - OFFSET_Y, ( _count / 32 % 3 ) * 64 + 768, 448, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
		{// ケンカ煙
			const int ANIM[ 6 ] = { 0, 1, 2, 3, 2, 1 };
			Drawer::Transform trans( 510, 370 - OFFSET_Y, ANIM[ _count / 4 % 6 ] * 256, 512, 256, 256 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}

	if ( _count > ANIMELOCK_COUNT - 220 && _count < ANIMELOCK_COUNT ) {
		{// 食べ物
			Drawer::Transform trans( 610, y - OFFSET_Y, ( _count / 4 % 4 ) * 64 + 640, 384, 64, 64 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
}

void SceneResult::drawHell( ) {
	DrawerPtr drawer = Drawer::getTask( );

	if ( _count < ANIMELOCK_COUNT - 20 ) {
		{// たろすけ
			Drawer::Transform trans( 575, 420 - OFFSET_Y, ( _count / 4 % 4 ) * 128, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else if ( _count <= ANIMELOCK_COUNT - 13 ) {
		{// たろすけ
			Drawer::Transform trans( 575, 420 - OFFSET_Y, ( _count / 4 % 2 ) * 128 + 512, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	} else {
		{// 溺れるたろすけ
			Drawer::Transform trans( 575, 420 - OFFSET_Y, ( _count / 4 % 2 ) * 128 + 768, 256, 128, 128 );
			Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
			drawer->setSprite( sprite );
		}
	}
	
	{// 鬼
		const int ANIM[ 6 ] = { 3, 2, 1, 0, 1, 2 };
		Drawer::Transform trans( 550, 260 - OFFSET_Y, ANIM[ _count / 4 % 4 ] * 256, 0, 256, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 窯の火1
		Drawer::Transform trans( 550, 550 - OFFSET_Y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火2
		Drawer::Transform trans( 580, 550 - OFFSET_Y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火3
		Drawer::Transform trans( 610, 550 - OFFSET_Y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火4
		Drawer::Transform trans( 640, 550 - OFFSET_Y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火5
		Drawer::Transform trans( 670, 550 - OFFSET_Y, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}
