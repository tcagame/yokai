#pragma once

#include "Character.h"

class Psychic : public Character {
public:
	Psychic( int x, int y );
	virtual ~Psychic( );
public:
	void setRange( int x );
	int getRange( ) const;
private:
	int _range_x;
};
