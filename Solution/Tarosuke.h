#pragma once
#include "smart_ptr.h"
#include "Character.h"
#include "PsychicMgr.h"

PTR( ChipDrawer );
PTR( PsychicMgr );

class Tarosuke : public Character {
public:
	Tarosuke( PsychicMgrPtr psychic );
	virtual ~Tarosuke( );
public:
	void debugChip( );
	void updateAccel( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_WALK,
		ACTION_JUMP,
		ACTION_PSYCHIC,
		ACTION_FLOAT,
		ACTION_MAX
	};
private:
	void updateChip( );
	void manipulate( );
	void adjustX( );
	void adjustY( );
private:
	ACTION _action;
	PsychicMgrPtr _psychic_mgr;
	int _jump_count;
};