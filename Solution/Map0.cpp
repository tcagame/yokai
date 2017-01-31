#include "Map0.h"
#include "define.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyWaterGhost.h"
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"
#include "EnemyDeceasedFourth.h"
#include "EnemyMoth.h"
#include "EnemyFlog.h"
#include "BossRedDemon.h"

static const Map::Panel panel[] = {
	{//0
		"street/map0/bg/map0_00_00.png",
		"",
		40, 65,
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
		NONE
	},
	{//1
		"street/map0/bg/map0_01_00.png",
		"",
		50, 70,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"               A"
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
		"",
		70, 60,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"  A  A  A       "
		"                "
		"   ########     "
		" ##########     "
		"###########     "
		"###########     "
		"###########     "
		"###########~~B~~"
		"################"
		"################",
		NONE
	},
	{//3
		"street/map0/bg/map0_04_00.png",
		"",
		80, 80,
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
		NONE
	},
	{//4
		"street/map0/bg/map0_05_00.png",
		"",
		110, 75,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"  ###########   "
		"  ###########   "
		"  ###########   "
		"  ###########   "
		"  ###########   "
		"B~###########C D"
		"################"
		"################",
		NONE
	},
	{//5
		"street/map0/bg/map0_06_00.png",
		"",
		125, 75,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"   #############"
		"   #############"
		"   #############"
		"   #############"
		"   #############"
		" EF#############"
		"################"
		"################",
		NONE
	},
	{//6
		"street/map0/bg/map0_07_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"    G           "
		"                "
		"                "
		"                "
		"#      -        "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               ",
		NONE
	},
	{//7
		"street/map0/bg/map0_07_00.png",
		"",
		100, 120,
		"                "
		"                "
		"                "
		"            G   "
		"                "
		"                "
		"                "
		"                "
		"       -        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{//8
		"street/map0/bg/cemetery.png",
		"",
		75, 135,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"       -        "
		"             G  "
		"                "
		"                "
		"                "
		"                "
		"               #"
		"               #",
		MOTH
	},
	{//9
		"street/map0/bg/cliff_stairs.png",
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
		"            A  #"
		"             ###"
		"           #####"
		"         #######"
		"       #########"
		"################"
		"################",
		NONE
	},
	{//10
		"street/map0/bg/map0_05_01.png",
		"",
		90, 140,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"  A     A     A "
		"                "
		"################"
		"#####           "
		"#####           "
		"##### ####      "
		"#####           "
		"#####~~~~~~~~~~~"
		"################",
		NONE
	},
	{//11
		"street/map0/bg/map0_06_01.png",
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
		"####            "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		NONE
	},
	{//12
		"street/map0/bg/map0_07_01.png",
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
		"~~~~~~~~~~~~~~~~"
		"################",
		NONE
	},
	{//13
		"street/map0/bg/map0_08_01.png",
		"",
		155, 170,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"           H    "
		"       #########"
		"######          "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		NONE
	},
	{//14
		"street/map0/bg/map0_09_01.png",
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
		"###########     "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		NONE
	},
	{//15
		"street/map0/bg/map0_11_01.png",
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
		"~~~~~~~~~~~~~~~~"
		"################",
		NONE
	},
	{//16
		"street/map0/bg/map0_01_02.png",
		"street/map0/cover/right_half_gate.png",
		275, 165,
		"                "
		"                "
		"                "
		"                "
		"                "
		"  ##           #"
		"  ##       #####"
		"  ##       #####"
		"  **     #######"
		"         #######"
		"       #########"
		"       #########"
		"     ###########"
		"              ##"
		"~~~~~~~~~~~~~~##"
		"################",
		NONE
	},
	{//17
		"street/map0/bg/make_bg.png",
		"street/map0/cover/make_cover.png",
		300, 130,
		"                "
		"                "
		"                "
		"                "
		"                "
		"##              "
		"##              "
		"##              "
		"##              "
		"##              "
		"##  ####        "
		"##              "
		"##              "
		"##              "
		"################"
		"################",
		NONE
	},
	{//18
		"street/map0/bg/map2_04_01.png",
		"street/map0/cover/grass.png",
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
	{//18
		"street/map0/bg/map0_00_04.png",
		"street/map0/cover/grass.png",
		280, 120,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//19
		"street/map0/bg/map0_01_04.png",
		"street/map0/cover/grass.png",
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
		"street/map0/bg/map0_02_04.png",
		"street/map0/cover/tree_1.png",
		280, 110,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//21
		"street/map0/bg/map0_03_04.png",
		"street/map0/cover/tree_2.png",
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
	{//22
		"street/map0/bg/map0_forestRock.png",
		"street/map0/cover/grass.png",
		285, 100,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_00_05.png",
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
	{//24
		"street/map0/bg/map0_06_05.png",
		"street/map0/cover/entrygate_1.png",
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
	{//25
		"street/map0/bg/map0_07_05.png",
		"street/map0/cover/entrygate_2.png",
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
	{//26
		"street/map0/bg/map0_08_05.png",
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
	{//27
		"street/map0/bg/iwakabe.png",
		"street/map0/cover/bg_cover.png",
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
	{//28
		"street/map0/bg/event_04_00.png",
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
	{//29
		"street/map0/bg/event_05_00.png",
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
	{//30
		"street/map0/bg/event_06_00.png",
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
	{//31
		"street/map0/bg/event_07_00.png",
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
};


Map0::Map0( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map0::~Map0( ) {
}

EnemyPtr Map0::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
		break;
	case 'B': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) );
		break;
	case 'C': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) );
		break;
	case 'D': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) );
		break;
	case 'E': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) );
		break;
	case 'F': enemy = EnemyPtr( new EnemyDeceasedFourth( x, y ) );
		break;
	case 'G': enemy = EnemyPtr( new EnemyMoth( x, y ) );
		break;
	case 'H': enemy = EnemyPtr( new EnemyFlog( stock, x, y ) );
		break;
	}

	return enemy;
}

BossPtr Map0::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossRedDemon( stock, offset_x ) );
}