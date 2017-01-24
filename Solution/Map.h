#pragma once

#include "define.h"

const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;

struct MAPDATA {
	const char * bg_filename;
	const char * cover_filename;
	const char chip[ MAPCHIP_NUM * MAPCHIP_NUM + 1 ];
	const unsigned int enemy;
};

class Map {
public:
	Map( );
	virtual ~Map( );
	const char * getBgFilename( int idx ) const;
	const char * getCoverFilename( int idx ) const;
	const unsigned int getEnemyData( int idx ) const;
	int getLength( ) const;
	bool isChip( int bg_idx, int chip_idx ) const;
	bool isInWater( int bg_idx, int chip_idx ) const;
private:
	int _length;
	MAPDATA * _data;
};

