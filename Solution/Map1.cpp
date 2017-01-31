#include "Map1.h"
#include "define.h"
#include "EnemyDeceasedPurple.h"
#include "BossBlueDemon.h"
#include "EnemyWaterGhost.h"
#include "EnemyRedbird.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"

static const Map::Panel panel[] = {
	{//0
		"street/map1/bg/map1_00.png",
		"",
		15, 60,
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###B            "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"###             "
		"################"
		"################",
		NONE
	},
	{//1
		"street/map1/bg/map1_01.png",
		"",
		26, 75,
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
		DECEASED_PURPLE | REDBIRD
	},
	{//2
		"street/map1/bg/map1_02.png",
		"",
		45, 75,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              - "
		"   A A          "
		"######         "
		"######          "
		"######          "
		"######          "
		"######D+E+F+++++"
		"################",
		DECEASED
	},
	{//3
		"street/map1/bg/map1_03.png",
		"",
		55, 85,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"           -    "
		"                "
		"                "
		"                "
		"                "
		"++++C+++++++++++"
		"################",
		DECEASED | FLOG_SMALL
	},
	{//4
		"street/map1/bg/map1_04.png",
		"",
		65, 80,
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
		"     ###########"
		"     ###########"
		"     ###########"
		"     ###########"
		"+++++###########"
		"################",
		MOTH | SKELETON_SPEAR
	},
	{//5
		"street/map1/bg/map1_05.png",
		"street/map1/cover/bamboo1.png",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"       E        "
		"                "
		"                "
		"################"
		"################"
		"################"
		"################"
		"################"
		"################",
		EXTRUDEDSPRITS
	},
	{//6
		"street/map1/bg/map1_06.png",
		"street/map1/cover/bamboo2.png",
		0, 0,
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
		"################"
		"################"
		"################"
		"################"
		"################",
		JIZO
	},
	{//7
		"street/map1/bg/map1_07.png",
		"street/map1/cover/bamboo3.png",
		0, 0,
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
		"################"
		"################"
		"################"
		"################"
		"################",
		MIASMA_GRAY
	},
	{//8
		"street/map1/bg/map1_08.png",
		"street/map1/cover/bamboo1.png",
		85, 95,
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
		"#               "
		"###             "
		"#####           "
		"#######         "
		"################"
		"################",
		NONE
	},
	{//9
		"street/map1/bg/map1_09.png",
		"street/map1/cover/bamboo2.png",
		100, 110,
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
		CROCODILE_SNAKE
	},
	{//10
		"street/map1/bg/map1_10.png",
		"street/map1/cover/bamboo3.png",
		0, 0,
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
	{//11
		"street/map1/bg/map1_11.png",
		"street/map1/cover/bamboo1.png",
		120, 110,
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
	{//12
		"street/map1/bg/map1_12.png",
		"",
		0, 0,
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
		STONE_FLY | STONE_ROTE
	},
	{//13
		"street/map1/bg/map1_13.png",
		"",
		0, 0,
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
		STONE_ROTE
	},
	{//14
		"street/map1/bg/map1_14.png",
		"",
		0, 0,
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
		ONYUDO
	},
	{//15
		"street/map1/bg/map1_15.png",
		"street/map1/cover/big_gate.png",
		145, 90,
		"  *****         "
		"  *****         "
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
		REDBIRD
	},
	{//16
		"street/map1/bg/map1_16.png",
		"",
		0, 0,
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
	{//17
		"street/map1/bg/map1_17.png",
		"street/map1/cover/house_entry.png",
		0, 0,
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
		MOTH
	},
	{//18
		"street/map1/bg/map1_18.png",
		"street/map1/cover/house.png",
		0, 0,
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
		ONYUDO
	},
	{//19
		"street/map1/bg/map1_19.png",
		"",
		0, 0,
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
	{//20
		"street/map1/bg/map1_20.png",
		"",
		0, 0,
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
		EXTRUDEDSPRITS
	},
	{//21
		"street/map1/bg/map1_21.png",
		"",
		0, 0,
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
		JIZO
	},
	{//22
		"street/map1/bg/map1_22.png",
		"",
		0, 0,
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
	{//23
		"street/map1/bg/map1_23.png",
		"street/map1/cover/cave_1.png",
		160, 110,
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
		"         #######"
		"         #######"
		"       #########"
		"       #########"
		"################"
		"################",
		NONE
	},
	{//24
		"street/map1/bg/map1_24.png",
		"street/map1/cover/cave_2.png",
		0, 0,
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
		"################"
		"################"
		"################"
		"################"
		"################",
		MIASMA_GRAY
	},
	{//25
		"street/map1/bg/map1_24.png",
		"street/map1/cover/cave_3.png",
		0, 0,
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
		"################"
		"################"
		"################"
		"################"
		"################",
		CROCODILE_SNAKE
	},
	{//26
		"street/map1/bg/map1_25.png",
		"street/map1/cover/cave_4.png",
		175, 130,
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
		"################"
		"##########      "
		"##########      "
		"################"
		"################",
		FLOG_SMALL
	},
	{//27
		"street/map1/bg/map1_26.png",
		"street/map1/cover/bridge_1.png",
		0, 0,
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
		"################"
		"                "
		"                "
		"################"
		"################",
		DECEASED_PURPLE | REDBIRD
	},
	{//28
		"street/map1/bg/map1_27.png",
		"street/map1/cover/bridge_2.png",
		240, 140,
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
		"################"
		"                "
		"                "
		"################"
		"################",
		MOTH | STONE_FLY
	},
	{//29
		"street/map1/bg/map1_28.png",
		"street/map1/cover/bridge_3.png",
		290, 80,
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
		"################"
		"      ##########"
		"      ##########"
		"################"
		"################",
		BOW_DEMON
	},
	{//30
		"street/map1/bg/map1_29.png",
		"street/map1/cover/entry_cave.png",
		0, 0,
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
		"################"
		"################"
		"################"
		"################"
		"################",
		NONE
	},
	{//31
		"street/map1/bg/map1_30.png",
		"",
		0, 0,
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
		"#########       "
		"#########       "
		"#########       "
		"#########       "
		"################"
		"################",
		DECEASED
	},
	{//32
		"street/map1/bg/map1_31.png",
		"",
		0, 0,
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
		EXTRUDEDSPRITS
	},
	{//33
		"street/map1/bg/map1_32.png",
		"street/map1/cover/bg_cover.png",
		0, 0,
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
		SKELETON_SPEAR
	},
	{//34
		"street/map1/bg/map1_33.png",
		"",
		0, 0,
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
	{//35
		"street/map1/bg/map1_34.png",
		"",
		0, 0,
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
	{//36
		"street/map1/bg/map1_35.png",
		"",
		0, 0,
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
	{//37
		"street/map1/bg/map1_36.png",
		"",
		0, 0,
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
		"################",
		NONE
	},
};


Map1::Map1( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}

Map1::~Map1( ) {
}

EnemyPtr Map1::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
		break;
	case 'B': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) );
		break;
	case 'C': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) );
		break;
	case 'D': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) );
		break;
	case 'E': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) );
		break;
	case 'F': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) );
		break;
	}

	return enemy;
}

BossPtr Map1::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossBlueDemon( stock, offset_x ) );
}
