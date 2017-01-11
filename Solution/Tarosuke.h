#pragma once
#include "smart_ptr.h"
#include "Character.h"

PTR( ChipDrawer );

class Tarosuke : public Character {
public:
	Tarosuke( int x, int y );
	virtual ~Tarosuke( );
private:
	void debugChip( );
	void updateAcceleration( );
private:
	static const int MAX_CHIP_NUM = 101;
	ChipDrawer::CHIP _chip_list[ MAX_CHIP_NUM ];
	int _chip_num;
};