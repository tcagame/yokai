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
	enum DIR {
		DIR_RIGHT,
		DIR_LEFT,
	};
protected:
	void setDir( DIR dir );
	void setChip( ChipDrawer::CHIP chip );
	virtual void updateAccel( );
	virtual void moveVertical( );
	virtual void manipulate( );
	virtual void updateChip( );
	virtual void debugChip( );
	void  fall( );
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
	int getX( );
	ChipDrawer::CHIP getChip( );
private:
	int _x;
	int _y;
	ChipDrawer::CHIP _chip;
	int _accel_x;
	int _accel_y;
	DIR _dir;
};