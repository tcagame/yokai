#include "Camera.h"
#include "define.h"
#include "Tarosuke.h"

Camera::Camera( TarosukeConstPtr tarosuke ) :
_tarosuke( tarosuke ) {
}


Camera::~Camera( ) {
}

void Camera::update( ) {
	_x = _tarosuke->getX( ) - SCREEN_WIDTH / 2;
	if ( _x < 0 ) {
		_x = 0;
	}
}

int Camera::getX( ) const {
	return _x;
}
