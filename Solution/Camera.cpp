#include "Camera.h"
#include "define.h"
#include "Tarosuke.h"
#include "Map.h"

static const int RANGE_NEAR = SCREEN_WIDTH / 5;
static const int RANGE_FAR  = SCREEN_WIDTH / 2;
static const int LOCK_SPEED = 10;

Camera::Camera( MapConstPtr map ) :
_map( map ),
_lock( false ) {
	_y = BG_SIZE - SCREEN_HEIGHT;
}

Camera::~Camera( ) {
}

void Camera::update( TarosukeConstPtr tarosuke ) {
	if ( _x < tarosuke->getX( ) - RANGE_FAR ) {
		_x = tarosuke->getX( ) - RANGE_FAR ;
	}
	
	if ( _lock ) {
		double near = _map->getPanelNum( ) * BG_SIZE - BG_SIZE * 3;
		if ( _x < near ) {
			_x += LOCK_SPEED;
		} else if ( _x > tarosuke->getX( ) - RANGE_NEAR ) {
			if ( tarosuke->getX( ) - RANGE_NEAR > near ) {
				_x = tarosuke->getX( ) - RANGE_NEAR;
			}
		}
	} else {
		if ( _x > tarosuke->getX( ) - RANGE_NEAR ) {
			_x = tarosuke->getX( ) - RANGE_NEAR;
		}
		if ( _x < 0 ) {
			_x = 0;
		}
	}
	if ( _x > _map->getPanelNum( ) * BG_SIZE- SCREEN_WIDTH - 1 ) {
		_x = _map->getPanelNum( ) * BG_SIZE - SCREEN_WIDTH - 1;
	}

	if ( _map->getPanelNum( ) * BG_SIZE - BG_SIZE * 3 < tarosuke->getX( ) ) {
		_lock = true;
	}
}

bool Camera::isLocked( ) const {
	return _lock;
}

int Camera::getX( ) const {
	return _x;
}

int Camera::getY( ) const {
	return _y;
}
