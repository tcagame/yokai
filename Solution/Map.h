#pragma once

#include "define.h"
#include "smart_ptr.h"

const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;

PTR( CloudMgr );
PTR( Boss );
PTR( EnemyStock );

class Map {
public:
	enum BOSS {
		BOSS_REDDEMON,
	};

	struct Item {
		BOSS boss;

	};
	struct Panel {
		const char * bg_filename;
		const char * cover_filename;
		const char chip[ MAPCHIP_NUM * MAPCHIP_NUM + 1 ];
		const unsigned int enemy;
	};
public:
	Map( const Item * item, const Panel * panel, int panel_num );
	virtual ~Map( );
public:
	const char * getBgFilename( int idx ) const;
	const char * getCoverFilename( int idx ) const;
	const unsigned int getEnemyData( int idx ) const;
	int getLength( ) const;
	bool isChip( int bg_idx, int chip_idx ) const;
	bool isInWater( int bg_idx, int chip_idx ) const;
	CloudMgrPtr createCloudMgr( ) const;
	BossPtr createBoss( EnemyStockPtr enemy_stock ) const;
private:
	bool isSmallCloud( int bg_idx, int chip_idx ) const;
	bool isBigCloud( int bg_idx, int chip_idx ) const;
private:
	const Item  * _item;
	const Panel * _panel;
	const int     _panel_num;
};

