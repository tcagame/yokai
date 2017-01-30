#include "Map0.h"
#include "define.h"

static const Map::Item item = {
	Map::BOSS_REDDEMON
};

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
		"                "
		"                "
		"               #"
		"             ###"
		"           #####"
		"         #######"
		"################"
		"################",
		PURPLE
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
		WATER_GHOST
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
		"~~###########   "
		"################"
		"################",
		DECEASED
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
		"   #############"
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
		"                "
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
		MOTH
	},
	{//7
		"street/map0/bg/map0_07_00.png",
		"",
		100, 120,
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
		"                "
		"                ",
		FLOG_SMALL
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
		"                "
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
		"               #"
		"             ###"
		"           #####"
		"         #######"
		"       #########"
		"################"
		"################",
		PURPLE
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
		"                "
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
		FLOG_SMALL
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
		"                "
		"       #########"
		"######          "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		FLOG | FLOG_SMALL
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
		WATER_GHOST | EXTRUDEDSPRITS
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
		WATER_MONK | REDBIRD | MIASMA_GRAY
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
		STONE_ROTE
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
		FLOG_SMALL
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
		FLOG_SMALL
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
		TREE | GROW_FACE
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
		STONE_FLY
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
		PURPLE
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
		REDBIRD
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
		EXTRUDEDSPRITS | GHOUL
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
		GHOUL
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
		BOW_DEMON
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
Map( &item, panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map0::~Map0( ) {
}
