#include "SceneResult.h"
#include "Game.h"
#include "Device.h"
#include "Drawer.h"
#include "define.h"

static const int FRAME_WIDTH  = 896;
static const int FRAME_HEIGHT = 772;

SceneResult::SceneResult( ) :
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );

	GamePtr game = Game::getTask( );
	_level = game->getStage( ) - 2;
	if ( _level < 0 ) {
		_level = 0;
	}

	switch ( _level ) {
	case 4:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/heaven/heaven_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/heaven/heaven_obj.png" );
		break;
	case 3:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/human/human_frame.png" );
		break;
	case 2:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/damn/damn_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/damn/damn_obj.png" );
		break;
	case 1:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hungry/hungry_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hungry/hungry_obj.png" );
		break;
	case 0:
		drawer->loadGraph( GRAPH_RESULT_FRAME, "result/hell/hell_frame.png" );
		drawer->loadGraph( GRAPH_RESULT_OBJ  , "result/hell/hell_obj.png" );
		break;
	}
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

	GamePtr game = Game::getTask( );
	if ( game->getFade( ) == Game::FADE_NONE ) {
		DevicePtr device = Device::getTask( );
		if ( device->getPush( ) == BUTTON_A ) {
			game->setFade( Game::FADE_OUT );
		}
	}
	if ( game->getFade( ) == Game::FADE_COVER ) {
		return NEXT_TITLE;
	}
	return NEXT_CONTINUE;
}

void SceneResult::drawFrame( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( ( SCREEN_WIDTH - FRAME_WIDTH ) / 2, ( SCREEN_HEIGHT - FRAME_HEIGHT ) / 2 );
	Drawer::Sprite sprite( trans, GRAPH_RESULT_FRAME, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void SceneResult::drawHeaven( ) {
	DrawerPtr drawer = Drawer::getTask( );

	{// たろすけ
		Drawer::Transform trans( 575, 430, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 天女奥左
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 350, 350, ANIM[ ( _count + 12 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女奥右
		const int ANIM[ 6 ] = { 2, 2, 2, 1, 0, 1 };
		Drawer::Transform trans( 820, 360, ANIM[ ( _count + 0 ) / 8 % 6 ] * 128, 256 + 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女手前左
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 450, 350, ANIM[ ( _count + 12 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 天女手前右
		const int ANIM[ 8 ] = { 0, 0, 0, 1, 2, 3, 2, 1 };
		Drawer::Transform trans( 720, 360, ANIM[ ( _count + 0 ) / 8 % 8 ] * 128, 0, 128, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 金の鳥1
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 900 - _count * 5, 100 + ( int )( sin( _count * PI / 120 ) * 50 ), n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 金の鳥2
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 950 - _count * 5, 130 + ( int )( sin( _count * PI / 120 ) * 50 ), n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 金の鳥3
		const int ANIM[ 4 ] = { 0, 1, 2, 1 };
		int n = ANIM[ _count / 6 % 2 ];
		Drawer::Transform trans( 980 - _count * 5, 80 + ( int )( sin( _count * PI / 120 ) * 50 ), n % 2 * 64 + 384, n / 2 * 64 + 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void SceneResult::drawHuman( ) {

}

void SceneResult::drawDamn( ) {
	DrawerPtr drawer = Drawer::getTask( );

	{// 豚ろすけ
		Drawer::Transform trans( 650, 480, ( _count / 8 % 2 ) * 128, 0, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 豚ﾊﾟｲｾﾝ
		Drawer::Transform trans( 730, 485, 0, 256, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void SceneResult::drawHungry( ) {
	DrawerPtr drawer = Drawer::getTask( );

	int y = _count - 125;

	{// たろすけ
		const int ANIM[ 3 ] = { 0, 0, 1 };
		Drawer::Transform trans( 575, 325, ANIM[ _count / 5 % 3 ] * 128 + 256, 0, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 餓鬼1(左)
		Drawer::Transform trans( 375, 420, ( _count / 4 % 2 ) * 128, 128, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 餓鬼2(右)
		Drawer::Transform trans( 770, 420, ( _count / 4 % 2 ) * 128, 256, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	if ( _count > 250 ) {
		Drawer::Transform trans( 610, y, ( _count / 4 % 4 ) * 64 + 640, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void SceneResult::drawHell(  ) {
	DrawerPtr drawer = Drawer::getTask( );

	{// たろすけ
		Drawer::Transform trans( 575, 420, ( _count / 4 % 4 ) * 128, 256, 128, 128 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 鬼
		const int ANIM[ 6 ] = { 3, 2, 1, 0, 1, 2 };
		Drawer::Transform trans( 550, 260, ANIM[ _count / 4 % 4 ] * 256, 0, 256, 256 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}

	{// 窯の火1
		Drawer::Transform trans( 550, 550, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火2
		Drawer::Transform trans( 580, 550, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火3
		Drawer::Transform trans( 610, 550, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火4
		Drawer::Transform trans( 640, 550, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{// 窯の火5
		Drawer::Transform trans( 670, 550, ( _count / 4 % 4 ) * 64, 384, 64, 64 );
		Drawer::Sprite sprite( trans, GRAPH_RESULT_OBJ, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}
