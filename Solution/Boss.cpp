#include "Boss.h"

Boss::Boss( int x, int y, int hp, int pow ) :
Enemy( x, y, 256, 0, false, hp, pow ) {
}


Boss::~Boss( ) {
}

bool Boss::isOutSideScreen( CameraConstPtr camera ) const {
	return false;
}
