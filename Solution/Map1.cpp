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
#include "EnemyDeceasedFourth.h"
#include "EnemyStoneRote.h"
#include "EnemyStoneFly.h"
#include "EnemyGhoul.h"
#include "EnemyFlogChief.h"
#include "EnemyWaterMonk.h"
#include "EnemyMiasmaGray.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyJizo.h"
#include "EnemyOnyudo.h"
#include "EnemyMoth.h"
#include "EnemyBat.h"
#include "EnemySkeletonSpear.h"
#include "EnemyOneEyesSnake.h"



static const Map::Panel panel[] = {
	{//0
		"street/map1/bg/map1_00.png",
		"",
		15, 60,
		"###             "
		"###     B       "
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
		"######          "
		"######          "
		"######          "
		"######          "
		"######D+E+F+G+++"
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
		"        S       "
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
		"      S         "
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
		"                "
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
		"        N       "
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
		"     O          "
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
		"  V             "
		"                "
		"                "
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
		"     S          "
		"                "
		"           S    "
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
		"            P   "
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
		"  P             "
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
		"               M"
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
		"   M       I    "
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
		"     R          "
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
		"             A H"
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
		"              N "
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
		"         N      "
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
		"               H"
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
		"    H    H      "
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
		"            L   "
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
		"           M    "
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
		" M              "
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
		"#########D#E#F#G"
		"################",
		DECEASED
	},
	{//32
		"street/map1/bg/map1_31.png",
		"",
		0, 0,
		"                "
		"    V           "
		"                "
		"                "
		"                "
		"                "
		"                "
		"         U      "
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
		"    U           "
		"                "
		"                "
		"                "
		"                "
		"                "
		"           Q   Q"
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
		"   Q            "
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
	case 'A': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );break;
	case 'B': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) );break;
	case 'C': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) );break;
	case 'D': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) );break;
	case 'E': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) );break;
	case 'F': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) );break;
	case 'G': enemy = EnemyPtr( new EnemyDeceasedFourth( x, y ) );break;
	case 'H': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) );break;
	case 'I': enemy = EnemyPtr( new EnemyFlogChief( stock, x, y ) );break;
	case 'J': enemy = EnemyPtr( new EnemyWaterMonk( x, y ) );break;
	case 'K': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) );break;
	case 'L': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) );break;
	case 'M': enemy = EnemyPtr( new EnemySkeletonSpear( x, y ) );break;
	case 'N': enemy = EnemyPtr( new EnemyJizo( stock, x, y ) );break;
	case 'O': enemy = EnemyPtr( new EnemyStoneFly( x, y ) );break;
	case 'P': enemy = EnemyPtr( new EnemyStoneRote( x, y ) );break;
	case 'Q': enemy = EnemyPtr( new EnemyGhoul( x, y ) );break;
	case 'R': enemy = EnemyPtr( new EnemyOnyudo( x, y ) );break;
	case 'S': enemy = EnemyPtr( new EnemyMoth( x, y ) );break;
	case 'T': enemy = EnemyPtr( new EnemyOneEyesSnake( x, y ) );break;
	case 'U': enemy = EnemyPtr( new EnemyBat( x, y ) );break;
	case 'V': enemy = EnemyPtr( new EnemyRedbird( stock, x - BG_SIZE * 2, y ) );break;
	}

	return enemy;
}

BossPtr Map1::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossBlueDemon( stock, offset_x ) );
}
