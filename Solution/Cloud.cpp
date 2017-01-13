#include "Cloud.h"

Cloud::Cloud( CloudManager::CLOUD_CHIP cloud_chip, int x, int y ) {
	_cloud_chip = cloud_chip;
	_x = x;
	_y = y;
}

Cloud::~Cloud( ) {
}

void Cloud::draw( CameraPtr camera ) {
}

int Cloud::getX( ) {
	return _x;
}

int Cloud::getY( ) {
	return _y;
}

CloudManager::CLOUD_CHIP Cloud::getChip( ) {
	return _cloud_chip;
}