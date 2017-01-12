#pragma once

#include "smart_ptr.h"

PTR( Tarosuke );

class Camera {
public:
	Camera( TarosukeConstPtr tarosuke );
	virtual ~Camera( );
	int getX( ) const;
	void update( );
private:
	TarosukeConstPtr _tarosuke;
	int _x;
};

