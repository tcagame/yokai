#pragma once

#include "define.h"

struct MAPDATA {
	const char * filename;
	const char chip[ MAPCHIP_NUM * MAPCHIP_NUM + 1 ];
	const unsigned int enemy;
};

class Map {
public:
	Map( );
	virtual ~Map( );
	const char * getFilename( int idx ) const;
	const unsigned int getEnemyData( int idx ) const;
	int getLength( ) const;
	bool isChip( int bg_idx, int chip_idx ) const;
	bool isInWater( int bg_idx, int chip_idx ) const;
private:
	int _length;
	MAPDATA * _data;
};

