#pragma once
#include "Character.h"

class Momotaro : public Character {
public:
	Momotaro( int x, int y );
	virtual ~Momotaro( );
	void debugChip( );
	void manipulate( );
};