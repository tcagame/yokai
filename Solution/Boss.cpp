#include "Boss.h"

Boss::Boss( int x, int y, int chip_size, int hp, int pow ) :
Enemy( x, y, chip_size, 0, false, hp, pow ) {
	focus( );
}


Boss::~Boss( ) {
}

Vector Boss::getOverlappedPos( ) const {
	return Vector( getX( ) + getSize( ) / 2, getY( ) + getChipFoot( ) - getSize( ) / 2 );
}

bool Boss::isOutSideScreen( CameraConstPtr camera ) const {
	return false;
}
