#include "EnemyRockMass.h"
#include "Drawer.h"
#include "Camera.h"
#include "EnemyStoneMortgage.h"
#include "EnemyATField.h"
#include "EnemyStock.h"

static const int WAIT_SOUL_ANIME_TIME = 2;
static const int WAIT_SHELL_ANIME_TIME = 20;
static const int SOUL_SIZE = 128;
static const int SOUL_FOOT = -60;
static const int SHELL_TX = 0;
static const int SHELL_TY = 256 + 128;
static const int SHELL_TW = 256;
static const int SHELL_TH = 128;
static const int SHELL_FOOT = 30;
static const int HP  = 10;
static const int POW = 3;

EnemyRockMass::EnemyRockMass( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, SOUL_SIZE, SOUL_FOOT, false, HP, POW ),
_count( 0 ),
_shrine_rope( true ),
_regist( true ),
_stock( stock ) {
	_a_t_field = EnemyATFieldPtr( new EnemyATField( x, y - 200 ) );
	stock->addEnemy( _a_t_field );
}


EnemyRockMass::~EnemyRockMass( ) {
	_a_t_field->damage( -1 );
	for ( int i = 0; i < STONE_NUM; i++ ) {
		_stones[ i ]->damage( -1 );
	}
}

void EnemyRockMass::act( ) {
	if ( _regist ) {
		struct Stone {
			int offset_x;
			int offset_y;
			int type;
		} STONE[ STONE_NUM ] = {
			{    0, -150, 0, },
			{  -70,  -40, 1, },
			{   50,  -40, 2, },
			{  -30,  -40, 0, },
			{   20,  -45, 0, },
			{  -40, -100, 1, },
			{   25, -100, 2, },
			{  -10,  -80, 3, },
			{    0, -120, 0, },
			{    0,  -50, 1, },
		};

		for ( int i = 0; i < STONE_NUM; i++ ) {
			int stone_x = STONE[ i ].offset_x + getX( );
			int stone_y = STONE[ i ].offset_y + getY( );
			int stone_type = STONE[ i ].type;
			_stones[ i ] = EnemyStoneMortgagePtr( new EnemyStoneMortgage( stone_x, stone_y, stone_type ) );
			_stock->addEnemy( _stones[ i ] );
		}
		_regist = false;
	}

	if ( getHp( ) < HP ) {
		_shrine_rope = false;
	}

	if ( !_shrine_rope ) {
		_count++;
		const int MOTION[ ] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		const int PATTERN = sizeof( MOTION ) / sizeof( MOTION[ 0 ] );
		int u = MOTION[ ( _count / WAIT_SOUL_ANIME_TIME ) % PATTERN ] % 4;
		int v = MOTION[ ( _count / WAIT_SOUL_ANIME_TIME ) % PATTERN ] / 4;
		setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );

		if ( _count % 200 == 0 ) {
			_invisible = true;
			for ( int i = 0; i < STONE_NUM; i++ ) {
				_stones[ i ]->setMove( false );
			}
		}
		if ( _count % 200 == 100 ) {
			_invisible = false;
			for ( int i = 0; i < STONE_NUM; i++ ) {
				_stones[ i ]->setMove( true );
			}
		}
	}
}

void EnemyRockMass::drawOverlapped( CameraConstPtr camera ) const {
	DrawerPtr drawer = Drawer::getTask( );
	{
		int sx = getX( ) - camera->getX( ) - SHELL_TW / 2;
		int sy = getY( ) - camera->getY( ) - SHELL_TH + SHELL_FOOT;
		Drawer::Transform trans( sx, sy, SHELL_TX, SHELL_TY, SHELL_TW, SHELL_TH );
		Drawer::Sprite sprite( trans, GRAPH_ENEMY_ROCKMASS, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
	if ( _shrine_rope ) {
		int sx = getX( ) - camera->getX( ) - SHELL_TW / 2;
		int sy = getY( ) - camera->getY( ) - SHELL_TH + SHELL_FOOT;
		Drawer::Transform trans( sx, sy, SHELL_TX + SHELL_TW, SHELL_TY, SHELL_TW, SHELL_TH );
		Drawer::Sprite sprite( trans, GRAPH_ENEMY_ROCKMASS, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
}

void EnemyRockMass::damage( int pow ) {
	if ( !_invisible ) {
		Enemy::damage( pow );
	}
}

