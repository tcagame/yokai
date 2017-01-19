#pragma once

#include "Character.h"
#include "mathmatics.h"

PTR( PsychicMgr );

class Momotaro : public Character {
public:
	Momotaro( CameraConstPtr camera, PsychicMgrPtr mgr );
	virtual ~Momotaro( );
public:
	void hide( );
	void appear( int x, int y, bool reverse );
private:
	enum ACTION {
		ACTION_HIDE,
		ACTION_MOVE,
	};
private:
	void act( );
	void actOnMove( );
	void actOnHide( );
private:
	CameraConstPtr _camera;
	PsychicMgrPtr _psychic_mgr;
	ACTION _action;
	int _shoot_x;
	int _shoot_y;
	int _cool;
	Vector _vec;
	int _device_num;
	int _act_count;
};