#pragma once
#include "smart_ptr.h"
#include "ChipDrawer.h"

PTR( ChipDrawer );


class Character {
public:
	Character( int x, int y );
	virtual ~Character( );
public:
	void draw( ChipDrawerPtr chip_drawer );
protected:
	void setChip( ChipDrawer::CHIP chip );
private:
	int _x;
	int _y;
	ChipDrawer::CHIP _chip;
};