#include "Camera.h"
#include "define.h"
#include "Tarosuke.h"
#include "Map.h"

Camera::Camera( TarosukeConstPtr tarosuke, MapConstPtr map ) :
_tarosuke( tarosuke ),
_map( map ) {
}

Camera::~Camera( ) {
}

void Camera::update( ) {
	_x = _tarosuke->getX( ) - SCREEN_WIDTH / 2;
	if ( _x < 0 ) {
		_x = 0;
	}
	if ( _x > _map->getLength( ) - SCREEN_WIDTH - 1 ) {
		_x = _map->getLength( ) - SCREEN_WIDTH - 1;
	}

	_y = 48;
}

int Camera::getX( ) const {
	return _x;
}

int Camera::getY( ) const {
	return _y;
}
