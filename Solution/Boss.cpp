#include "Boss.h"

Boss::Boss( int x, int y, int chip_size, int hp, int pow ) :
Enemy( x, y, chip_size, 0, false, hp, pow ) {
}


Boss::~Boss( ) {
}

bool Boss::isOutSideScreen( CameraConstPtr camera ) const {
	return false;
}
