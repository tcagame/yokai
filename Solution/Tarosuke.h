#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );
PTR( PsychicMgr );

class Tarosuke : public Character {
public:
	Tarosuke( PsychicMgrPtr psychic );
	virtual ~Tarosuke( );
private:
	enum ACTION {
		ACTION_STAND,
		ACTION_JUMP,
		ACTION_FLOAT,
		ACTION_SAVE,
		ACTION_MAX
	};
private:
	void act( );
	void actOnStanding( );
	void actOnJumping( );
	void actOnFloating( );
	void actOnSaving( );
	void updateChip( );
private:
	ACTION _action;
	PsychicMgrPtr _psychic_mgr;
	int _jump_count;
};