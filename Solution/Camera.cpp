#include "Camera.h"
#include "define.h"
#include "Tarosuke.h"
#include "Map.h"

Camera::Camera( MapConstPtr map ) :
_map( map ) {
	_y = BG_SIZE - SCREEN_HEIGHT;
}

Camera::~Camera( ) {
}

void Camera::update( TarosukeConstPtr tarosuke ) {
	_x = tarosuke->getX( ) - SCREEN_WIDTH / 2;
	if ( _x < 0 ) {
		_x = 0;
	}
	if ( _x > _map->getLength( ) - SCREEN_WIDTH - 1 ) {
		_x = _map->getLength( ) - SCREEN_WIDTH - 1;
	}

}

int Camera::getX( ) const {
	return _x;
}

int Camera::getY( ) const {
	return _y;
}
