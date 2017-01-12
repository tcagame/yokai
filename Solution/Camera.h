#pragma once

#include "smart_ptr.h"

PTR( Tarosuke );
PTR( Map );

class Camera {
public:
	Camera( TarosukeConstPtr tarosuke, MapConstPtr map );
	virtual ~Camera( );
	int getX( ) const;
	void update( );
private:
	TarosukeConstPtr _tarosuke;
	MapConstPtr _map;
	int _x;
};

