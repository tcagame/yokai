#include "Cloud.h"
#include "define.h"
#include "Drawer.h"
#include "Camera.h"

static const int CLOUD_CHIP_PATTERN = 4;
static const int CLOUD_MOVE_SPEED = 4;
static const int MAX_TURN_COUNT = 40;
static const int INTERVAL = 10;

static const int CLOUD_BIG_WIDTH = 400;
static const int CLOUD_BIG_HEIGHT = 216;

static const int CLOUD_SMALL_WIDTH = 207;
static const int CLOUD_SMALL_HEIGHT = 216;

static const int BLANK = 60;


Cloud::Cloud( int x, int y, bool big ) {
	_width  = CLOUD_SMALL_WIDTH;
	_height = CLOUD_SMALL_HEIGHT;
	_graph  = GRAPH_CLOUD_SMALL;
	if ( big ) {
		_width  = CLOUD_BIG_WIDTH;
		_height = CLOUD_BIG_HEIGHT;
		_graph  = GRAPH_CLOUD_BIG;
	}
	_x = x;
	_y = y;
	_accel = CLOUD_MOVE_SPEED;
	_turn_count = 0;
}

Cloud::~Cloud( ) {
}

void Cloud::draw( CameraConstPtr camera ) const {
	int tx = _y / INTERVAL % CLOUD_CHIP_PATTERN * _width;
	int ty = 0;
	int sx = _x - camera->getX( ) - _width / 2;
	int sy = _y - camera->getY( ) - _height / 2;
	int sx2 = sx + _width;
	int sy2 = sy + _height;

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( sx, sy, tx, ty, _width, _height, sx2, sy2 );
	Drawer::Sprite sprite( trans, _graph, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}

void Cloud::update( ) {
	updateAccel( );
	moveVertical( );
}

void Cloud::updateAccel( ) {
	_turn_count++;
	if ( _turn_count % MAX_TURN_COUNT == 0 ) {
		_accel *= -1;
	}
}

void Cloud::moveVertical( ) {
	_y += _accel;
}

int Cloud::getX( ) const {
	return _x;
}

int Cloud::getY( ) const {
	return _y;
}

int Cloud::getHeight( ) const {
	return _height;
}

int Cloud::getBlank( ) const {
	return BLANK;
}

bool Cloud::isStanding( int x, int src_y, int dst_y ) const {
	if ( x < _x - _width / 2 || x > _x + _width / 2 ) {
		return false;
	}
	return src_y < _y - _height / 2 + BLANK  && dst_y >= _y - _height / 2 + BLANK;
}
