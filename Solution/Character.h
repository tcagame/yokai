#pragma once
#include "smart_ptr.h"
#include "ChipDrawer.h"

PTR( ChipDrawer );
PTR( Camera );
PTR( Field );
PTR( Cloud );

class Character {
public:
	Character( int x, int y );
	virtual ~Character( );
	void update( FieldPtr field );
	virtual void draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera );
	int getX( ) const;
protected:
	void setChip( ChipDrawer::CHIP chip );
	virtual void updateAccel( );
	virtual void move( FieldPtr field );
	virtual void manipulate( );
	virtual void updateChip( );
	void  fall( );
	bool isStanding( ) const;
	int getY( ) const;
	void setX( int x );
	void setY( int y );
	int getAccelX( ) const;
	int getAccelY( ) const;
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
	virtual void adjustX( );
	virtual void adjustY( );
	ChipDrawer::CHIP getChip( );
	DIR getDir( );
private:
	void updateDir( );
private:
	int _x;
	int _y;
	bool _standing;
	ChipDrawer::CHIP _chip;
	int _accel_x;
	int _accel_y;
	DIR _dir;
	CloudConstPtr _cloud;
};