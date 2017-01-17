#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Field );
PTR( Cloud );

class MassCharacter : public Character {
public:
	MassCharacter( int x, int y );
	virtual ~MassCharacter( );
	void update( FieldPtr field );
protected:
	virtual void updateAccel( );
	virtual void move( FieldPtr field );
	virtual void manipulate( );
	virtual void updateChip( );
	void  fall( );
	bool isStanding( ) const;
	virtual void adjustX( );
	virtual void adjustY( );
	void setAccelX( int accel_x );
	void setAccelY( int accel_y );
private:
	void updateDir( );
private:
	int _accel_x;
	int _accel_y;
	CloudConstPtr _cloud;
	bool _standing;
};