#pragma once
#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );

class Tarosuke : public Character {
public:
	Tarosuke( int x, int y );
	virtual ~Tarosuke( );
};