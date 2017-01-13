#pragma once
#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );

class Tarosuke : public Character {
public:
	Tarosuke( );
	virtual ~Tarosuke(  );
public:
	void debugChip( );
	void updateAccel( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_WALK,
		ACTION_JUMP,
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
	int _jump_count;
};