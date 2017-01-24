#pragma once

#include "smart_ptr.h"
#include "Character.h"
#include "mathmatics.h"

PTR( ChipDrawer );
PTR( PsychicMgr );
PTR( Momotaro );
PTR( Power );
PTR( Character );

class Tarosuke : public Character {
public:
	Tarosuke( PsychicMgrPtr psychic, PowerPtr power, MomotaroPtr momotaro );
	virtual ~Tarosuke( );
public:
	bool isOnHead( CharacterPtr target ) const;
	void warp( int v );
	void damage( int pow );
	void bound( );
	void adjust( CameraConstPtr camera );
private:
	enum ACTION {
		ACTION_STAND,
		ACTION_FALTER,
		ACTION_SHOOT,
		ACTION_BRAKE,
		ACTION_JUMP,
		ACTION_FLOAT,
		ACTION_BURST,
		ACTION_CALL,
		ACTION_APPEAR,
		ACTION_PRAY,
		ACTION_DEAD,
		ACTION_MAX
	};
private:
	void act( );
	void actOnStanding( );
	void actOnJumping( );
	void actOnFloating( );
	void actOnBraking( );
	void actOnBursting( );
	void actOnFaltering( );
	void actOnShooting( );
	void actOnCalling( );
	void actOnAppearring( );
	void actOnPraying( );
	void actOnDying( );
	void drawOverlapped( CameraConstPtr camera ) const;
private:
	MomotaroPtr _momotaro;
	PowerPtr _power;
	ACTION _action;
	PsychicMgrPtr _psychic_mgr;
	int _jump_count;
	int _saving_power;
	int _act_count;
	Vector _momo_pos;
	Vector _momo_vec;
};