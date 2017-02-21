#include "SceneGate.h"
#include "Drawer.h"
#include "define.h"
#include "Sound.h"
#include "Game.h"
#include "Infomation.h"

static const int BG_HEIGHT = 512;
static const int MAP_X = ( SCREEN_WIDTH - 632 ) / 5;
static const int MAP_Y = 70;
static const int TITLE_X = ( SCREEN_WIDTH - 480 ) / 4;
static const int TITLE_Y = 10;
static const int COUNT_X = 1000;
static const int COUNT_Y = 100;
static const int CHARACTER_Y = 550;
static const int CHARACTER_SPEED = 10;
static const int CHARACTER_SIZE = 128;

SceneGate::SceneGate( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER_1, "Character/Character1.png" );
	drawer->loadGraph( GRAPH_CHARACTER_2, "Character/Character2.png" );
	drawer->loadGraph( GRAPH_GATE_BG,     "gate/gate_bg.png"  );
	drawer->loadGraph( GRAPH_GATE_COVER,  "gate/gate_cover.png"  );
	drawer->loadGraph( GRAPH_GATE_FACE,   "gate/gate_face.png"  );
	drawer->loadGraph( GRAPH_GATE_COUNT_0, "gate/count_0.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_1, "gate/count_1.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_2, "gate/count_2.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_3, "gate/count_3.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_4, "gate/count_4.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_5, "gate/count_5.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_6, "gate/count_6.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_7, "gate/count_7.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_8, "gate/count_8.png" );
	drawer->loadGraph( GRAPH_GATE_COUNT_9, "gate/count_9.png" );
	drawer->loadGraph( GRAPH_GATE_DOT    , "gate/count_dot.png" );
	drawer->loadGraph( GRAPH_GATE_CLEAR  , "gate/clear_font.png" );
	drawer->loadGraph( GRAPH_GATE_PERCENT, "gate/count_percent.png" );

	GamePtr game = Game::getTask( );
	switch ( game->getStage( ) ) {
	case 0:
		drawer->loadGraph( GRAPH_GATE_MAP  , "gate/gate_map_0.png"  );
		drawer->loadGraph( GRAPH_GATE_TITLE, "gate/gate_title_0.png"  );
		break;
	case 1:
		drawer->loadGraph( GRAPH_GATE_MAP  , "gate/gate_map_1.png"  );
		drawer->loadGraph( GRAPH_GATE_TITLE, "gate/gate_title_1.png"  );		
		break;
	case 2:
		drawer->loadGraph( GRAPH_GATE_MAP  , "gate/gate_map_2.png"  );
		drawer->loadGraph( GRAPH_GATE_TITLE, "gate/gate_title_2.png"  );
		break;
	case 3:
		drawer->loadGraph( GRAPH_GATE_MAP  , "gate/gate_map_3.png"  );
		drawer->loadGraph( GRAPH_GATE_TITLE, "gate/gate_title_3.png"  );
		break;
	case 4:
		drawer->loadGraph( GRAPH_GATE_MAP  , "gate/gate_map_4.png"  );
		drawer->loadGraph( GRAPH_GATE_TITLE, "gate/gate_title_4.png"  );
		break;
	}
	
	Infomation info;
	_prob = info.getProbability( game->getStage( ) );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_se_30.wav", false );
	_x = -1000;

	_title_offset_x = -SCREEN_WIDTH * 2;
	_map_offset_x   =  SCREEN_WIDTH * 2;
	_clear_offset_y = -SCREEN_HEIGHT * 2;
}


SceneGate::~SceneGate( ) {
}

Scene::NEXT SceneGate::update( ) {
	GamePtr game = Game::getTask( );

	if ( game->getFade( ) != Game::FADE_IN ) {
		_title_offset_x = ( int )( _title_offset_x * 95 / 100 );
		_map_offset_x   = ( int )( _map_offset_x   * 90 / 100 );
		_clear_offset_y = ( int )( _clear_offset_y * 97 / 100 );
		_x += CHARACTER_SPEED;
	}

	draw( );

	switch ( game->getFade( ) ) {
	case Game::FADE_NONE:
		if ( _x > SCREEN_WIDTH + CHARACTER_SIZE ) {
			game->setFade( Game::FADE_OUT );
		}
		break;
	case Game::FADE_COVER:
		return NEXT_STREET;
	}

	return NEXT_CONTINUE;
}

void SceneGate::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( MAP_X + _map_offset_x, MAP_Y ), GRAPH_GATE_MAP );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( TITLE_X + _title_offset_x, TITLE_Y ), GRAPH_GATE_TITLE );
		drawer->setSprite( sprite );
	}

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

	GamePtr game = Game::getTask( );

	{
		int n = _prob / 1000 % 10;
		if ( n > 0 ) {
			Drawer::Sprite sprite( //•S‚ÌˆÊ
				Drawer::Transform( COUNT_X - 170, COUNT_Y + 130 + _clear_offset_y ), GRAPH_NUMERIC[ n ] );
			drawer->setSprite( sprite );
		}
	}

	{
		int n = _prob / 100 % 10;
		if ( n > 0 || _prob >= 100 ) {
			Drawer::Sprite sprite( //\‚ÌˆÊ
				Drawer::Transform( COUNT_X - 120, COUNT_Y + 130 + _clear_offset_y ), GRAPH_NUMERIC[ n ] );
			drawer->setSprite( sprite );
		}
	}
	{
		int n = _prob / 10 % 10;
		Drawer::Sprite sprite( //ˆê‚ÌˆÊ
			Drawer::Transform( COUNT_X - 70, COUNT_Y + 130 + _clear_offset_y ), GRAPH_NUMERIC[ n ] );
		drawer->setSprite( sprite );
	}
	{
		int n = _prob % 10;
		Drawer::Sprite sprite( //¬”“_‘æˆê
			Drawer::Transform( COUNT_X, COUNT_Y + 130 + _clear_offset_y ), GRAPH_NUMERIC[ n ] );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( COUNT_X - 20, COUNT_Y + 170 + _clear_offset_y ), GRAPH_GATE_DOT );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( COUNT_X - 105, COUNT_Y + 50 + _clear_offset_y ), GRAPH_GATE_CLEAR );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( COUNT_X + 60, COUNT_Y + 145 + _clear_offset_y ), GRAPH_GATE_PERCENT );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( 0, SCREEN_HEIGHT - BG_HEIGHT ), GRAPH_GATE_BG );
		drawer->setSprite( sprite );
	}
	{
		const int ANIM[ 10 ] = { 0, 0, 0, 1, 0, 0, 0, 2, 3, 2 };
		int idx = ANIM[ ( _x + 1000 ) / 50 % 10 ];  
		int tx = idx % 2 * 128;
		int ty = idx / 2 * 128;
		Drawer::Sprite sprite( 
			Drawer::Transform( 1100, 350, tx, ty, 128, 128 ), GRAPH_GATE_FACE );
		drawer->setSprite( sprite );
	}
	{
		const int WALK[ 8 ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
		int tx = WALK[ ( _x / 30 ) % 8 ] * CHARACTER_SIZE;
		int ty = 0;
		int sx1 = _x;
		int sy1 = CHARACTER_Y;
		int sx2 = sx1 - CHARACTER_SIZE;
		int sy2 = sy1 + CHARACTER_SIZE;

		Drawer::Sprite sprite( 
			Drawer::Transform( sx1, sy1, tx, ty, CHARACTER_SIZE, CHARACTER_SIZE, sx2, sy2 ), GRAPH_CHARACTER_1 );
		drawer->setSprite( sprite );
	}
	if ( !game->isSolo( ) ) {
		int tx = ( ( _x / 30 ) % 3 + 3 ) * CHARACTER_SIZE;
		int ty = 5 * CHARACTER_SIZE;
		int sx1 = _x - CHARACTER_SIZE * 2;
		int sy1 = CHARACTER_Y - ( int )( CHARACTER_SIZE * 2 + sin( PI * _x / 500 ) * CHARACTER_SIZE / 2 );
		int sx2 = sx1 - CHARACTER_SIZE;
		int sy2 = sy1 + CHARACTER_SIZE;

		Drawer::Sprite sprite( 
			Drawer::Transform( sx1, sy1, tx, ty, CHARACTER_SIZE, CHARACTER_SIZE, sx2, sy2 ), GRAPH_CHARACTER_2 );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( 0, SCREEN_HEIGHT - BG_HEIGHT ), GRAPH_GATE_COVER );
		drawer->setSprite( sprite );
	}
}