#pragma once

#include "define.h"
#include "smart_ptr.h"
#include "mathmatics.h"

const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;

PTR( CloudMgr );
PTR( ItemMgr );
PTR( EnemyStock );
PTR( Enemy );
PTR( Boss );

class Map {
public:
	struct Panel {
		const char * bg_filename;
		const char * cover_filename;
		int marker_x;
		int marker_y;
		const char chip[ MAPCHIP_NUM * MAPCHIP_NUM + 1 ];
	};
public:
	Map( const Panel * panel, int panel_num );
	virtual ~Map( );
public:
	const char * getBgFilename( int idx ) const;
	const char * getCoverFilename( int idx ) const;
	Vector getMarkerPos( int idx ) const;
	int getPanelNum( ) const;
	bool isChip( int bg_idx, int chip_idx ) const;
	bool isBlockChip( int bg_idx, int chip_idx ) const;
	bool isItem( int bg_idx, int chip_idx ) const;
	FLOOR getFloor( int bg_idx, int chip_idx ) const;
	CloudMgrPtr createCloudMgr( ) const;
	ItemMgrPtr createItemMgr( ) const;
	virtual void addToStock( EnemyStockPtr stock, int idx ) const;
	virtual EnemyPtr generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const = 0;
	virtual BossPtr  generateBoss( EnemyStockPtr stock ) const = 0;
private:
	bool isSmallCloud( int bg_idx, int chip_idx ) const;
	bool isBigCloud( int bg_idx, int chip_idx ) const;
private:
	const Panel * _panel;
	const int     _panel_num;
};

