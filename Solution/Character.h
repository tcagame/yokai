#pragma once

#include "smart_ptr.h"
#include "define.h"
#include "ChipDrawer.h"

PTR( ChipDrawer );
PTR( Camera );
PTR( Field );

class Character {
public:
	Character( int x, int y );
	virtual ~Character( );
	int getX( ) const;
	int getY( ) const;
	ChipDrawer::CHIP getChip( ) const;
	DIR getDir( ) const;
	virtual void draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera );
	virtual void update( FieldPtr field );
protected:
	void setX( int x );
	void setY( int y );
	void setChip( ChipDrawer::CHIP chip );
	void setDir( DIR dir );
private:
	int _x;
	int _y;
	ChipDrawer::CHIP _chip;
	DIR _dir;
};

