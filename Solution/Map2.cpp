#include "Map2.h"
#include "define.h"

static const Map::Item item = {
	Map::BOSS_REDDEMON
};

static const Map::Panel panel[] = {
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
	{
		"street/map0/bg/map0_03_00.png",
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
		" =           -  "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################",
		NONE
	},
};


Map2::Map2( ) :
Map( &item, panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map2::~Map2( ) {
}
