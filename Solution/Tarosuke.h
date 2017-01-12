#pragma once
#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );

class Tarosuke : public Character {
public:
	Tarosuke( int x, int y );
	virtual ~Tarosuke( );
public:
	void debugChip( );
	void updateAccel( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_WALK,
		ACTION_JUMP,
		ACTION_MAX
	};
private:
	void updateChip( );
	void manipulate( );
	void actOnJumping( );
private:
	ACTION _action;
	int _jump_count;
};