#include "Status.h"
#include "Drawer.h"
#include "define.h"
#include "Power.h"
#include "Field.h"
#include "Tarosuke.h"
#include "Game.h"

static const int MAP_WIDTH = 347;
static const int POWER_X = 218;
static const int POWER_Y = 136;
static const int MARKER_SIZE = 24;
static const int TITLE_X = 325;
static const int TITLE_Y =   0;

Status::Status( PowerConstPtr power, FieldConstPtr field, TarosukeConstPtr tarosuke ) :
_power( power ),
_field( field ),
_tarosuke( tarosuke ),
_count( 0 ) {
	reset( );
}

Status::~Status( ) {
}

void Status::reset( ) {
	GamePtr game = Game::getTask( );
	_continue_count = game->getContinueCount( );
	
}

void Status::update( ) {
	_count++;
}

void Status::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	{
		Drawer::Transform trans( SCREEN_WIDTH - MAP_WIDTH, 0 );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_MAP );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Transform trans( 0, 0 );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_PLATE );
		drawer->setSprite( sprite );
	}
	{
		Drawer::Transform trans( TITLE_X, TITLE_Y );
		Drawer::Sprite sprite( trans, GRAPH_STATUS_TITLE );
		drawer->setSprite( sprite );
	}
	{
		const int GRAPH[ 7 ] = {
			GRAPH_STATUS_POWER_0,
			GRAPH_STATUS_POWER_1,
			GRAPH_STATUS_POWER_2,
			GRAPH_STATUS_POWER_3,
			GRAPH_STATUS_POWER_4,
			GRAPH_STATUS_POWER_5,
			GRAPH_STATUS_POWER_6,
		};
		int n = _power->get( );
		for ( int i = 0; i < n; i++ ) {
			Drawer::Transform trans( POWER_X + i * 16, POWER_Y );
			Drawer::Sprite sprite( trans, GRAPH[ i / 6 ] );
			drawer->setSprite( sprite );
		}
	}
	{
		const int ANIM[ 8 ] = { 4, 3, 2, 3, 4, 1, 0, 1 };
		Vector pos = _field->getStatusMarkerPos( _tarosuke->getX( ) );
		int x = ( int )pos.x - MARKER_SIZE / 2 + SCREEN_WIDTH - MAP_WIDTH;
		int y = ( int )pos.y - MARKER_SIZE;
		int u = ANIM[_count / 4 % 8 ];
		Drawer::Transform trans( x, y, u * MARKER_SIZE, 0, MARKER_SIZE, MARKER_SIZE );
		Drawer::Sprite sprite(trans, GRAPH_STATUS_MARKER );
		drawer->setSprite(sprite);
	}
	
	for ( int i = 0; i < _continue_count; i++ ) {
		int x = 850 - i * 15;
		int y = 32;
		int n = ( _count + i * 5 ) % 100;
		if ( n < 20 ) {
			y -= ( int )( sin( PI * n / 20 ) * 16 );
		}
		Drawer::Transform trans( x, y );
		Drawer::Sprite sprite(trans, GRAPH_STATUS_CONTINUE );
		drawer->setSprite(sprite);
	}
}