#pragma once

#include "smart_ptr.h"

PTR( Tarosuke );
PTR( Map );

class Camera {
public:
	Camera( MapConstPtr map );
	virtual ~Camera( );
public:
	int getX( ) const;
	int getY( ) const;
	void update( TarosukeConstPtr tarosuke );
	bool isLocked( ) const;
private:
	MapConstPtr _map;
	int _x;
	int _y;
	bool _lock;
};

