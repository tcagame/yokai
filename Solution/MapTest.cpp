#include "MapTest.h"
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
		"###         -   "
		"###             "
		"### -           "
		"###             "
		"###     -      -"
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
		"                "
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
		" ####******     "
		"#####           "
		"#####           "
		"#####           "
		"#####      ~~~~~"
		"################"
		"################",
		NONE
	},
	{//3
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{//4
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
		NONE
	},
	{//5
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
		"    #########   "
		"-   #########   "
		"    #########   "
		"    #########   "
		"    #########   "
		"~~~~#########+++"
		"################"
		"################",
		FLOG
	},
	{//47
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
		"                "
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
		"                "
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
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{//48
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
		NONE
	},
	{//49
		"street/map0/bg/event_07_00.png",
		"",
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
