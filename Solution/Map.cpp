#include "Map.h"
#include "define.h"
#include "CloudMgr.h"
#include "Cloud.h"

static const unsigned int NONE = 0x00000000;

MAPDATA MAP0[] = {
	{//0
		"street/map0/bg/map0_00_00.png",
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"################"
		"################",
		PURPLE
	},
	{//1
		"street/map0/bg/map0_01_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"               #"
		"             ###"
		"           #####"
		"         #######"
		"################"
		"################",
		NONE
	},
	{//2
		"street/map0/bg/map0_02_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"   ########     "
		" ##########     "
		"###########     "
		"###########     "
		"###########     "
		"###########~~~~~"
		"################"
		"################",
		NONE
	},
	{//3
		"street/map0/bg/map0_03_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		PURPLE
	},
	{//4
		"street/map0/bg/map0_04_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"      =         "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		MOTH
	},
	{//5
		"street/map0/bg/map0_05_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"-               "
		"                "
		"                "
		"                "
		"~~~#            "
		"################"
		"################",
		NONE
	},
	{//6
		"street/map0/bg/map0_06_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		NONE
	},
	{//7
		"street/map0/bg/map0_07_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		TREE
	},
	{//8
		"street/map0/bg/map0_07_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//9
		"street/map0/bg/map0_07_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		NONE
	},
	{//10
		"street/map0/bg/map0_07_00.png", // Ç¬Ç»Ç¨ÇçlÇ¶ÇÈ
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE
	},
	{//11
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE
	},
	{//12
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		NONE
	},
	{//13
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//14
		"street/map0/bg/map0_04_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//15
		"street/map0/bg/map0_05_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//16
		"street/map0/bg/map0_06_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//17
		"street/map0/bg/map0_07_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//18
		"street/map0/bg/map0_08_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//19
		"street/map0/bg/map0_09_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//20
		"street/map0/bg/map0_10_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//21
		"street/map0/bg/map0_11_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//22
		"street/map0/bg/map0_00_02.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//23
		"street/map0/bg/map0_00_02.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//24
		"street/map0/bg/map0_00_02.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//25
		"street/map0/bg/map0_00_02.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//26
		"street/map0/bg/map0_00_01.png", // Ç¬Ç»Ç¨ÇçlÇ¶ÇÈ
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//27
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//28
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//29
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//30
		"street/map0/bg/map0_00_01.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//31
		"street/map0/bg/map0_04_03.png", // map3_04_04ÇÇ¢ÇÍÇÈ
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//32
		"street/map0/bg/map0_06_03.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//33
		"street/map0/bg/map0_07_03.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//34
		"street/map0/bg/map0_00_04.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//35
		"street/map0/bg/map0_02_04.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//36
		"street/map0/bg/map0_01_04.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//37
		"street/map0/bg/map0_03_04.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//38
		"street/map0/bg/map0_04_04.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//39
		"street/map0/bg/map0_00_01.png", // map3_07_04ÇÇ¢ÇÍÇÈ
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//40
		"street/map0/bg/map0_00_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//41
		"street/map0/bg/map0_00_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//42
		"street/map0/bg/map0_00_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//43
		"street/map0/bg/map0_06_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//44
		"street/map0/bg/map0_07_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//45
		"street/map0/bg/map0_08_05.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//46
		"street/map0/bg/event_04_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//47
		"street/map0/bg/event_05_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//48
		"street/map0/bg/event_06_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
	{//49
		"street/map0/bg/event_07_00.png",
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		PURPLE | REDBIRD
	},
};

Map::Map( ) {
	_num = ( sizeof( MAP0 ) / sizeof( MAPDATA ) - 1 );
	_data = MAP0;
}

Map::~Map( ) {
}

int Map::getLength( ) const {
	return _num * BG_SIZE;
}

const char * Map::getFilename( int idx ) const {
	return _data[ idx ].filename;
}

const unsigned int Map::getEnemyData( int idx ) const {
	return _data[ idx ].enemy;
}

bool Map::isChip( int bg_idx, int chip_idx ) const {
	return _data[ bg_idx ].chip[ chip_idx ] == '#';
}


bool Map::isInWater( int bg_idx, int chip_idx ) const {
	return _data[ bg_idx ].chip[ chip_idx ] == '~';
}

bool Map::isBigCloud( int bg_idx, int chip_idx ) const {
	return _data[ bg_idx ].chip[ chip_idx ] == '=';
}

bool Map::isSmallCloud( int bg_idx, int chip_idx ) const {
	return _data[ bg_idx ].chip[ chip_idx ] == '-';
}

CloudMgrPtr Map::createCloudMgr( ) const {
	CloudMgrPtr mgr( new CloudMgr );

	for ( int i = 0; i < _num; i++ ) {
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			if ( isBigCloud( i, j ) ||
				 isSmallCloud( i, j ) ) {
				bool big = false;
				if ( isBigCloud( i, j ) ) {
					big = true;
				}
				int x = j % MAPCHIP_NUM * MAPCHIP_SIZE + i * BG_SIZE;
				int y = j / MAPCHIP_NUM * MAPCHIP_SIZE;
				CloudPtr cloud( new Cloud( x, y, big ) );
				mgr->add( cloud );
			}
		}
	}

	return mgr;
}

