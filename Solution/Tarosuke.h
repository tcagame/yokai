#pragma once
#include "smart_ptr.h"

PTR( ChipDrawer );

class Tarosuke {
public:
	Tarosuke( );
	virtual ~Tarosuke( );
	void draw( ChipDrawerPtr chip_drawer );
};

