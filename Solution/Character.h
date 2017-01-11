#pragma once
#include "smart_ptr.h"
#include "ChipDrawer.h"

PTR( ChipDrawer );


class Character {
public:
	Character( int x, int y );
	virtual ~Character( );
public:
	void update( );
	void draw( ChipDrawerPtr chip_drawer );
protected:
	virtual void updateAcceleration( );
	void setChip( ChipDrawer::CHIP chip );
	virtual void moveVertical( );
	void debugChip( );
	void  fall( );
	ChipDrawer::CHIP getChip( );
private:
	int _x;
	int _y;
	ChipDrawer::CHIP _chip;
	int _acceleration_y;
};