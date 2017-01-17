#pragma once

#include "smart_ptr.h"
#include "define.h"

PTR( Camera );
PTR( Field );
PTR( Cloud );

class Character {
public:
	Character( int x, int y, int chip_graph, int chip_size, int chip_foot, bool mass = true );
	virtual ~Character( );
public:
	virtual void update( FieldPtr field );
	int getX( ) const;
	int getY( ) const;
	int getAccelX( ) const;
	int getAccelY( ) const;
	bool isStanding( ) const;
	void draw( CameraConstPtr camera );
protected:
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
	void setChipReverse( bool reverse );
	void setChipUV( int u, int v );
	void setChipSize( int size );
private:
	virtual void act( ) = 0;
	void move( FieldPtr field );
	void updateDir( );
private:
	const bool _mass;
	int _x;
	int _y;
	int _accel_x;
	int _accel_y;
	CloudConstPtr _cloud;
	bool _standing;
	int  _chip_graph;
	int  _chip_u;
	int  _chip_v;
	int  _chip_size;
	int  _chip_foot;
	bool _chip_reverse;
};
