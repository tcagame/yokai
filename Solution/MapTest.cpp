#include "MapTest.h"
#include "define.h"

static const Map::Item item = {
	Map::BOSS_BLUEDEMON
};

static const Map::Panel panel[] = {
	{//0
		"street/map0/bg/map0_00_00.png",
		"",
		10, 10,
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
		0, 0,
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
		100, 100,
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
		0, 0,
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
		PURPLE
	},
	{//5
		"street/map0/bg/map0_06_00.png",
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
		"    #########   "
		"-   #########   "
		"    #########   "
		"    #########   "
		"    #########   "
		"~~~~#########+++"
		"################"
		"################",
		REDBIRD | EYE 
	},
	{//7
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
		"       -        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		GROW_FACE | MIASMA_GRAY
	},
	{//47
		"street/map0/bg/map0_06_00.png",
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
		"    ############"
		"    ############"
		"    ############"
		"    ############"
		"    ############"
		"++++############"
		"################"
		"################",
		NONE
	},
		{//47
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
		"     =          "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{	"street/map0/bg/event_07_00.png",
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
		"    =           "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{//47
		"street/map0/bg/event_04_00.png",
		"",
		20, 300,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//47
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
		BOW_DEMON | TREE
	},
	{//48
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
	{//49
		"street/map0/bg/event_07_00.png",
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


MapTest::MapTest( ) :
Map( &item, panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


MapTest::~MapTest( ) {
}
