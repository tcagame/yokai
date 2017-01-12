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
	virtual void updateAccel( );
	void setChip( ChipDrawer::CHIP chip );
	virtual void moveVertical( );
	virtual void manipulate( );
	virtual void updateChip( );
	virtual void debugChip( );
	void  fall( );
	void setAccelX( int accel_x );
	int getX( );
	ChipDrawer::CHIP getChip( );
private:
	int _x;
	int _y;
	ChipDrawer::CHIP _chip;
	int _accel_x;
	int _accel_y;
};