#include "Character.h"
#include "Drawer.h"
#include "define.h"
#include "Field.h"
#include "Camera.h"
#include "Cloud.h"

Character::Character( int x, int y, int chip_graph, int chip_size, int chip_foot, bool mass ) :
_x( x ),
_y( y ),
_mass( mass ),
_chip_graph( chip_graph ),
_chip_size( chip_size ),
_chip_foot( chip_foot ),
_chip_u( 0 ),
_chip_v( 0 ),
_accel_x( 0 ),
_accel_y( 0 ) {
}

Character::~Character( ) {
}

int Character::getX( ) const {
	return _x;
}

int Character::getY( ) const {
	return _y;
}

int Character::getAccelX( ) const {
	return _accel_x;
}

int Character::getAccelY( ) const {
	return _accel_y;
}

int Character::getSize( ) const {
	return _chip_size;
}

bool Character::isChipReverse( ) const {
	return _chip_reverse;
}

void Character::setX( int x ) {
	_x = x;
}

void Character::setY( int y ) {
	_y = y;
}

void Character::setChipReverse( bool reverse ) {
	_chip_reverse = reverse;
}

void Character::setChipUV( int u, int v ) {
	_chip_u = u;
	_chip_v = v;
}

void Character::setChipSize( int size ) {
	_chip_size = size;
}

void Character::setChipFoot( int foot ) {
	_chip_foot = foot;
}

void Character::update( FieldPtr field ) {
	setInWater( field );
	act( );
	updateDir( );
	move( field );
}

void Character::setInWater( FieldPtr field ) {
	if ( !field ) {
		return;
	}
	_in_water = field->isInWater( _x, _y );
}

bool Character::isInWater( ) const {
	return _in_water;
}

void Character::draw( CameraConstPtr camera, bool bright ) const {

	int tx = _chip_u * _chip_size;
	int ty = _chip_v * _chip_size;

	int sx1 = getX( ) - camera->getX( ) - _chip_size / 2;
	int sy1 = getY( ) - camera->getY( ) - _chip_size + _chip_foot;
	int sx2 = sx1 + _chip_size;
	int sy2 = sy1 + _chip_size;

	if ( _chip_reverse ) {
		int tmp = sx1;
		sx1 = sx2;
		sx2 = tmp;
	}

	Drawer::BLEND blend = Drawer::BLEND_NONE;
	if ( bright ) {
		blend = Drawer::BLEND_ADD;
	}

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx1, sy1, tx, ty, _chip_size, _chip_size, sx2, sy2 );
	Drawer::Sprite sprite( trans, _chip_graph, blend, 1.0 );
	drawer->setSprite( sprite );

	drawOverlapped( camera );
}

void Character::move( FieldPtr field ) {
	if ( !_mass || !field ) {
		_x += _accel_x;
		_y += _accel_y;
		return;
	}

	_accel_y += GRAVITY_POWER;
	if ( _accel_y > MAPCHIP_SIZE / 2 ) {
		_accel_y = MAPCHIP_SIZE / 2;
	}

	if ( _cloud ) { 
		if ( !_cloud->isStanding( getX( ), 0, SCREEN_HEIGHT ) ||
			 _accel_y < 0 ) {
			_cloud = CloudConstPtr( );
		}
	}

    int src_x = getX( );
    int src_y = getY( );
	int dst_x = src_x + _accel_x;
	int dst_y = src_y + _accel_y;

	Field::Collision col = field->getCollision( src_x, src_y, dst_x, dst_y );

	if ( col.overlapped_x ) {
		dst_x = col.adjust_x;
	}

	_standing = false;
	if ( col.overlapped_y ) {
		_accel_y = 0;
		dst_y = col.adjust_y;
		if ( col.cloud ) {
			_cloud = col.cloud;
		}
		_standing = true;
	}

	if ( _cloud ) {
		dst_y = _cloud->getY( ) - 1;
		_standing = true;
	}

	_x = dst_x;
	_y = dst_y;
}

void Character::updateDir( ) {
	if ( _accel_x < 0 ) {
		setChipReverse( false );
	}
	if ( _accel_x > 0 ) {
		setChipReverse( true );
	}
}

bool Character::isStanding( ) const {
	return _standing;
}

void Character::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void Character::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}

double Character::getOverlappedRadius( ) const {
	return _chip_size / 2 * 0.8;
}

Vector Character::getOverlapeedPos( ) const {
	return Vector( _x, _y + _chip_foot - _chip_size / 2 );
}
