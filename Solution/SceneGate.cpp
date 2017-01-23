#include "SceneGate.h"
#include "Drawer.h"
#include "define.h"
#include "Sound.h"

static const int BG_HEIGHT = 512;
static const int MAP_X = ( SCREEN_WIDTH - 512 ) / 2;
static const int MAP_Y = -100;
static const int TAROSUKE_Y = 550;
static const int TAROSUKE_SPEED = 10;
static const int TAROSUKE_SIZE = 128;

SceneGate::SceneGate( int stage ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER_1, "Character/Character1.png" );
	drawer->loadGraph( GRAPH_GATE_BG,     "gate/gate_bg.png"  );
	drawer->loadGraph( GRAPH_GATE_COVER,  "gate/gate_cover.png"  );
	drawer->loadGraph( GRAPH_GATE_MAP,    "gate/gate_map_0.png"  );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_se_32.wav" );
	_x = 0;
}


SceneGate::~SceneGate( ) {
}

Scene::NEXT SceneGate::update( ) {
	act( );
	draw( );

	if ( _x > SCREEN_WIDTH + TAROSUKE_SIZE ) {
		return NEXT_STREET;
	}
	return NEXT_CONTINUE;
}

void SceneGate::act( ) {
	_x += TAROSUKE_SPEED;
}

void SceneGate::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( MAP_X, MAP_Y ), GRAPH_GATE_MAP );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( 0, SCREEN_HEIGHT - BG_HEIGHT ), GRAPH_GATE_BG );
		drawer->setSprite( sprite );
	}
	{
		const int WALK[ 8 ] = { 1, 2, 1, 0, 3, 4, 3, 0 };
		int tx = WALK[ ( _x / 30 ) % 8 ] * TAROSUKE_SIZE;
		int ty = 0;
		int sx1 = _x;
		int sy1 = TAROSUKE_Y;
		int sx2 = sx1 - TAROSUKE_SIZE;
		int sy2 = sy1 + TAROSUKE_SIZE;

		Drawer::Sprite sprite( 
			Drawer::Transform( sx1, sy1, tx, ty, TAROSUKE_SIZE, TAROSUKE_SIZE, sx2, sy2 ), GRAPH_CHARACTER_1 );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Sprite sprite( 
			Drawer::Transform( 0, SCREEN_HEIGHT - BG_HEIGHT ), GRAPH_GATE_COVER );
		drawer->setSprite( sprite );
	}
}