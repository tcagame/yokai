#include "Character.h"
#include "define.h"
#include "Field.h"
#include "Camera.h"

Character::Character( int x, int y ) {
	_x = x;
	_y = y;
	_accel_x = 0;
	_accel_y = 0;
	_store_overlapped = false;
}


Character::~Character( ) {
}

void Character::update( FieldPtr field ) {
	updateAccel( );
	updateDir( );
	moveVertical( field );
	moveHorizontal( field );
	updateChip( );
	//debugChip( );
}

void Character::updateAccel( ) {
}

void Character::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( _dir == DIR_RIGHT );

	chip_drawer->draw( _chip, _x - camera->getX( ) - CHIP_SIZE / 2, _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK, reverse );
}

void Character::moveHorizontal( FieldPtr field ) {
	_x += _accel_x;
	adjustX( );
	
	bool overlapped = field->isChip( _x, _y );

	// もしチップに重なっていたらチップの上に移動
	if ( overlapped && !_store_overlapped ) {
		// 衝突している
		int dif = _x % MAPCHIP_SIZE;
		_x = _x / MAPCHIP_SIZE * MAPCHIP_SIZE;
		if ( dif < MAPCHIP_SIZE / 2 ) {
			_x -= 1;
		} else {
			_x += MAPCHIP_SIZE;
		}
		_accel_x = 0;
		overlapped = false;
	}

	_store_overlapped = overlapped;

}

void Character::moveVertical( FieldPtr field ) {
	// 移動した
    _y += _accel_y;
	adjustY( );

	bool overlapped = field->isChip( _x, _y );

	_standing = false;
	if ( _accel_y > 0 ) {
		// もしチップに重なっていたらチップの上に移動
		if ( overlapped && !_store_overlapped ) {
			// 衝突している
			_y = _y / MAPCHIP_SIZE * MAPCHIP_SIZE;
			_y -= 1;
			_accel_y = 0;
			overlapped = false;
			_standing = true;
		}
	}

	_store_overlapped = overlapped;
}

void Character::debugChip( ) {
}

void Character::manipulate( ) {
}

void Character::updateChip( ) {
}

void Character::updateDir( ) {
	if ( _accel_x > 0 ) {
		_dir = DIR_RIGHT;
	}
	if ( _accel_x < 0 ) {
		_dir = DIR_LEFT;
	}
}

int Character::getX( ) const {
	return _x;
}

int Character::getY( ) const {
	return _y;
}

void Character::setX( int x ) {
	_x = x;
}

void Character::setY( int y ) {
	_y = y;
}

void Character::adjustX( ) {
}

void Character::adjustY( ) {
}

void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP Character::getChip( ) {
	return _chip;
}

Character::DIR Character::getDir( ) {
	return _dir;
}

void Character::fall( ) {
 	_accel_y += GRAVITY_POWER;
}

bool Character::isStanding( ) const {
	return _standing;
}
int Character::getAccelX( ) const {
	return _accel_x;
}

int Character::getAccelY( ) const {
	return _accel_y;
}

void Character::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void Character::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}
