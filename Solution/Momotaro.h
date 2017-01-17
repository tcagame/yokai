#pragma once

#include "Character.h"

class Momotaro : public Character {
public:
	Momotaro( CameraConstPtr camera );
	virtual ~Momotaro( );
private:
	void act( );
	void manipulate( );
private:
	CameraConstPtr _camera;
};