#include "EnemyFireball.h"
#include "Camera.h"
#include "Drawer.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 8;
static const int POW = 3;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 1;

EnemyFireball::EnemyFireball( const Vector& pos, const Vector& vec, bool dir_right ) :
Enemy( ( int )pos.x, ( int )pos.y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_pos( pos ),
_vec( vec ) {
	setNoHead( );
	if ( dir_right ) {
		_vec.x *= -1;
	}
}


EnemyFireball::~EnemyFireball( ) {
}

void EnemyFireball::act( ) {
	_count++;

	_pos += _vec;
	
	setX( ( int )_pos.x );
	setY( ( int )_pos.y );

	Vector up( 0, -1 );
	double angle = up.angle( _vec );
	if ( up.cross( _vec ).z < 0 ) {
		angle = PI2 - angle;
	}
	int n = ( int )( angle / ( PI2 / 16 ) );
	_u = n % 4;
	_v = n / 4;
	setChipGraph( GRAPH_ENEMY_FIREBALL, _u, _v );
}

void EnemyFireball::drawOverlapped( CameraConstPtr camera ) const {

	int tx = _u * CHIP_SIZE;
	int ty = _v * CHIP_SIZE;
	int sx1 = getX( ) - camera->getX( ) - CHIP_SIZE / 2;
	int sy1 = getY( ) - camera->getY( ) - CHIP_SIZE + getChipFoot( );	
	int sx2 = sx1 + CHIP_SIZE + _count % 10;
	int sy2 = sy1 + CHIP_SIZE + _count % 10;
	sx1 -= _count % 10;
	sy1 -= _count % 10;

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx1, sy1, tx, ty, CHIP_SIZE, CHIP_SIZE, sx2, sy2 );
	Drawer::Sprite sprite( trans, GRAPH_ENEMY_FIREBALL, Drawer::BLEND_ADD, 1.0 * _count / 10 );
	drawer->setSprite( sprite );
}
