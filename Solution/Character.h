#pragma once
#include "smart_ptr.h"
#include "ChipDrawer.h"

PTR( ChipDrawer );
PTR( Camera );

class Character {
public:
	Character( int x, int y );
	virtual ~Character( );
	void update( );
	void draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera );
	int getX( ) const;
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
	bool isStanding( ) const;
	int getAccelX( ) const;
	int getAccelY( ) const;
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
	ChipDrawer::CHIP getChip( );
private:
	int _x;
	int _y;
	bool _standing;
	ChipDrawer::CHIP _chip;
	int _accel_x;
	int _accel_y;
	DIR _dir;
};