#pragma once

#include "define.h"
#include "smart_ptr.h"

const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;

struct MAPDATA {
	const char * filename;
	const char chip[ MAPCHIP_NUM * MAPCHIP_NUM + 1 ];
	const unsigned int enemy;
};

PTR( CloudMgr );

class Map {
public:
	Map( );
	virtual ~Map( );
public:
	const char * getFilename( int idx ) const;
	const unsigned int getEnemyData( int idx ) const;
	int getLength( ) const;
	bool isChip( int bg_idx, int chip_idx ) const;
	bool isInWater( int bg_idx, int chip_idx ) const;
	CloudMgrPtr createCloudMgr( ) const;
private:
	bool isSmallCloud( int bg_idx, int chip_idx ) const;
	bool isBigCloud( int bg_idx, int chip_idx ) const;
private:
	int _num;
	MAPDATA * _data;
};

