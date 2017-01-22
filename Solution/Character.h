#pragma once

#include "smart_ptr.h"
#include "define.h"
#include "mathmatics.h"

PTR( Camera );
PTR( Field );
PTR( Cloud );
PTR( EnemyManager );

class Character {
public:
	Character( int x, int y, int chip_size, int chip_foot, bool mass );
	virtual ~Character( );
public:
	virtual void update( FieldPtr field );
	int getX( ) const;
	int getY( ) const;
	int getAccelX( ) const;
	int getAccelY( ) const;
	int getSize( ) const;
	bool isChipReverse( ) const;
	bool isStanding( ) const;
	bool isInWater( ) const;
	virtual double getOverlappedRadius( ) const;
	virtual Vector getOverlapeedPos( ) const;
	void draw( CameraConstPtr camera, bool bright = false ) const;
protected:
	void setX( int x );
	void setY( int y );
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
	void setChipReverse( bool reverse );
	void setChipGraph( GRAPH graph, int u, int v );
	void setChipSize( int size );
	void setChipFoot( int foot );
	void setDead( bool dead );
private:
	virtual void act( ) = 0;
	void move( FieldPtr field );
	void updateDir( );
	void setInWater( FieldPtr field );
	virtual void drawOverlapped( CameraConstPtr camera ) const { }
private:
	const bool _mass;
	int _x;
	int _y;
	int _accel_x;
	int _accel_y;
	CloudConstPtr _cloud;
	bool _standing;
	bool _in_water;
	int  _chip_graph;
	int  _chip_u;
	int  _chip_v;
	int  _chip_size;
	int  _chip_foot;
	bool _chip_reverse;
	bool _dead;
};
