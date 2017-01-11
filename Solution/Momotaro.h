#pragma once
#include "Character.h"

class Momotaro : public Character {
public:
	Momotaro( int x, int y );
	virtual ~Momotaro( );
	void debugChip( );
private:
	static const int MAX_CHIP_NUM = 7;
	ChipDrawer::CHIP _chip_list[ MAX_CHIP_NUM];
	int _chip_num;
};