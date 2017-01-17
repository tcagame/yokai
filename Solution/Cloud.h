#pragma once
#include "CloudManager.h"

class Cloud {
public:
	Cloud( int x, int y, bool big );
	virtual ~Cloud( );
public:
	void draw( CameraConstPtr camera ) const;
	void update( );
	bool isStanding( int x, int src_y, int dst_y ) const;
	int getX( ) const;
	int getY( ) const;
private:
	void updateAccel( );
	void moveVertical( );
	void updateChip( );
private:
	int _x;
	int _y;
	int _accel;
	int _turn_count;
	int _width;
	int _height;
	int _graph;
};

