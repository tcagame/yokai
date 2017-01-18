#pragma once

#include "Character.h"
#include "mathmatics.h"

PTR( PsychicMgr );

class Momotaro : public Character {
public:
	Momotaro( CameraConstPtr camera, PsychicMgrPtr mgr );
	virtual ~Momotaro( );
private:
	void act( );
	void manipulate( );
private:
	CameraConstPtr _camera;
	PsychicMgrPtr _psychic_mgr;
	int _shoot_x;
	int _shoot_y;
	int _cool;
	Vector _vec;
};