#include "Map0.h"
#include "define.h"

static const Map::Item item = {
	Map::BOSS_REDDEMON
};

static const Map::Panel panel[] = {
	{//0
		"street/map0/bg/map0_00_00.png",
		"",
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
		"",
		"                "
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
		"",
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
		DECEASED
	},
	{//3
		"street/map0/bg/map0_04_00.png",
		"",
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
	{//4
		"street/map0/bg/map0_05_00.png",
		"",
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
		"~~#             "
		"################"
		"################",
		NONE
	},
	{//5
		"street/map0/bg/map0_06_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		FLOG
	},
	{//6
		"street/map0/bg/map0_07_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
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
		"################"
		"################",
		TREE
	},
	{//7
		"street/map0/bg/map0_07_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
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
		"################"
		"################",
		TREE
	},
	{//8
		"street/map0/bg/map0_07_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
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
		"################"
		"################",
		TREE
	},
	{//9
		"street/map0/bg/map0_04_01.png",
		"street/map0/cover/rock_2.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//10
		"street/map0/bg/map0_05_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		FLOG
	},
	{//11
		"street/map0/bg/map0_06_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		STONE
	},
	{//12
		"street/map0/bg/map0_07_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//13
		"street/map0/bg/map0_08_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//14
		"street/map0/bg/map0_09_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_11_01.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_01_02.png",
		"street/map0/cover/right_half_gate.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_00_04.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_01_04.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_02_04.png",
		"street/map0/cover/tree_1.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_03_04.png",
		"street/map0/cover/tree_2.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_forestRock.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_00_05.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_06_05.png",
		"street/map0/cover/entrygate_1.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_07_05.png",
		"street/map0/cover/entrygate_2.png",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/map0_08_05.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/event_04_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/event_05_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/event_06_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"street/map0/bg/event_07_00.png",
		"",
		"                "
		"                "
		"                "
		"                "
		"                "
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


Map0::Map0( ) :
Map( &item, panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map0::~Map0( ) {
}
