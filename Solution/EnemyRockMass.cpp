#include "EnemyRockMass.h"
#include "Drawer.h"
#include "Camera.h"

static const int WAIT_SOUL_ANIME_TIME = 2;
static const int WAIT_SHELL_ANIME_TIME = 20;
static const int SOUL_SIZE = 128;
static const int SOUL_FOOT = -100;
static const int SHELL_TX = 0;
static const int SHELL_TY = 256 + 128;
static const int SHELL_TW = 256;
static const int SHELL_TH = 128;
static const int SHELL_FOOT = 30;
static const int HP  = 10;
static const int POW = 3;

EnemyRockMass::EnemyRockMass( int x, int y ) :
Enemy( x, y, SOUL_SIZE, SOUL_FOOT, true, HP, POW ),
_count( 0 ){

}


EnemyRockMass::~EnemyRockMass( ) {
}

void EnemyRockMass::act( ) {
	const int MOTION[ ] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	const int PATTERN = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
	_count++;
	int u = MOTION[ ( _count / WAIT_SOUL_ANIME_TIME ) % PATTERN ] % 4;
	int v = MOTION[ ( _count / WAIT_SOUL_ANIME_TIME ) % PATTERN ] / 4;
	setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );
}

void EnemyRockMass::drawOverlapped( CameraConstPtr camera ) const {
	{
		int sx = getX( ) - camera->getX( ) - SHELL_TW / 2;
		int sy = getY( ) - camera->getY( ) - SHELL_TH + SHELL_FOOT;
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx, sy, SHELL_TX, SHELL_TY, SHELL_TW, SHELL_TH );
		Drawer::Sprite sprite( trans, GRAPH_ENEMY_ROCKMASS, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	{
		int sx = getX( ) - camera->getX( ) - SHELL_TW / 2;
		int sy = getY( ) - camera->getY( ) - SHELL_TH + SHELL_FOOT;
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx, sy, SHELL_TX + SHELL_TW, SHELL_TY, SHELL_TW, SHELL_TH );
		Drawer::Sprite sprite( trans, GRAPH_ENEMY_ROCKMASS, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}