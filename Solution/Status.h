#pragma once

#include "smart_ptr.h"

PTR( Power );
PTR( Tarosuke );
PTR( Field );

class Status {
public:
	Status( PowerConstPtr power, FieldConstPtr field, TarosukeConstPtr tarosuke  );
	virtual ~Status( );
public:
	void update( );
	void draw( );
	void reset( );
private:
	PowerConstPtr _power;
	int _count;
	FieldConstPtr _field;
	TarosukeConstPtr _tarosuke;
	int _continue_count;
};
