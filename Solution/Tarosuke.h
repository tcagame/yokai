#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );
PTR( PsychicMgr );
PTR( Momotaro );

class Tarosuke : public Character {
public:
	Tarosuke( PsychicMgrPtr psychic );
	virtual ~Tarosuke( );
public:
	void setSoloPlay( MomotaroPtr momotaro );
private:
	enum ACTION {
		ACTION_STAND,
		ACTION_SHOOT,
		ACTION_BRAKE,
		ACTION_JUMP,
		ACTION_FLOAT,
		ACTION_SAVE,
		ACTION_BURST,
		ACTION_CALL,
		ACTION_APPEAR,
		ACTION_PRAY,
		ACTION_MAX
	};
private:
	void act( );
	void actOnStanding( );
	void actOnJumping( );
	void actOnFloating( );
	void actOnBraking( );
	void actOnBursting( );
	void actOnShooting( );
	void actOnCalling( );
	void actOnAppearring( );
	void actOnPraying( );
	void updateChip( );
	void drawOverlapped( CameraConstPtr camera ) const;
private:
	MomotaroPtr _momotaro;
	ACTION _action;
	PsychicMgrPtr _psychic_mgr;
	int _jump_count;
	int _saving_power;
	int _act_count;
};