#pragma once

#include "Character.h"
#include "mathmatics.h"

PTR( PsychicMgr );
PTR( Power );
PTR( Inputter );

class Momotaro : public Character {
public:
	Momotaro( InputterPtr inputter, PsychicMgrPtr mgr, PowerPtr _power );
	virtual ~Momotaro( );
public:
	void hide( );
	void appear( int x, int y, bool reverse );
	void damage( int pow );
	void adjust( CameraConstPtr camera, FieldConstPtr field );
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
	InputterPtr _inputter;
	CameraConstPtr _camera;
	PsychicMgrPtr _psychic_mgr;
	PowerPtr _power;
	ACTION _action;
	Vector _vec;
	int _device_num;
	int _act_count;
	int _falter_count;
	int _cooltime;
};