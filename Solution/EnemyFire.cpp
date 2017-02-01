#include "EnemyFire.h"
#include "Drawer.h"
#include "Camera.h"

static const int HP = 99;
static const int POW = 3;
static const int MOVE_SPEED = 5;
static const double SPEED = 5.0;
static const double ACCEL = 0.1;
static const int CHIP_SIZE = 128;

EnemyFire::EnemyFire( const Vector& pos, const Vector& vec, const Vector& target ) : 
Enemy( 0, 0, 0, 0, false, HP, POW ),
_target( target ),
_pos( pos ),
_vec( vec.normalize( ) * SPEED ) {
	setNoHead( );
	
	_target.x += rand( ) % 400 - 200;
	_target.y += rand( ) % 400 - 200;
	int count = rand( ) % 200;
	for ( int i = 0; i < count; i++ ) {
		Vector v = _target - _pos;
		v = v.normalize( ) * ACCEL;
		_vec = ( _vec + v ).normalize( ) * SPEED;
		_pos += _vec;
	}
}


EnemyFire::~EnemyFire( ) {
}

void EnemyFire::act( ) {

	for ( int j = 0; j < DIV_NUM; j++ ) {
		Vector v = _target - _pos;
		v = v.normalize( ) * ACCEL;
		_vec = ( _vec + v ).normalize( ) * SPEED;
		_pos += _vec;

		for ( int i = 0; i < TAIL_NUM - 1; i++ ) {
			_tails[ i ] = _tails[ i + 1 ];
		}
		_tails[ TAIL_NUM - 1 ] = _pos;
	}

	setX( ( int )_pos.x );
	setY( ( int )_pos.y );
}

bool EnemyFire::isOutSideScreen( CameraConstPtr camera ) const {
	return false;
}

void EnemyFire::draw( CameraConstPtr camera, bool bright ) const {
	int tx = 0 * CHIP_SIZE;
	int ty = 3 * CHIP_SIZE;

	for ( int i = 0; i < TAIL_NUM; i++ ) {
		if ( _tails[ i ].isOrijin( ) ) {
			continue;
		}
		int draw_size = CHIP_SIZE * ( i + 1 ) / TAIL_NUM;
		int sx = ( int )_tails[ i ].x - camera->getX( ) - draw_size / 2;
		int sy = ( int )_tails[ i ].y - camera->getY( ) - draw_size / 2;
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx + draw_size, sy + draw_size );
		Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, 0.5 );
		drawer->setSprite( sprite );
	}
}