#include "Map2.h"
#include "define.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyStoneRote.h"
#include "EnemyStoneFly.h"
#include "EnemyMiasmaGray.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyWaterMonk.h"
#include "EnemyWaterGhost.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyDeceasedGreen.h"
#include "EnemySkeletonSpear.h"
#include "EnemyRedFlogSmall.h"
#include "EnemyHellFire.h"
#include "EnemyRedbird.h"
#include "BossHag.h"

static const Map::Panel panel[] = {
	{
		"street/map2/map2_start_00.png",
		"",
		204, 97,
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
	{
		"street/map2/map2_start_01.png",
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
		"              ##"
		"            ####"
		"          ######"
		"         #######"
		"                "
		"################"
		"################",
		DECEASED_GREEN | MOTH
	},
	{
		"street/map2/map2_start_02.png",
		"",
		0, 0,
		"             ###"
		"             ###"
		"             ###"
		"             ###"
		"        B    ###"
		"             ###"
		"    ############"
		"  ##############"
		"################"
		"################"
		"################"
		"################"
		"################"
		"                "
		"################"
		"################",
		STONE_FLY
	},
	{
		"street/map2/map2_rock_00.png",
		"",
		194, 100,
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"#               "
		"                "
		"################"
		"################",
		NONE
	},
	{
		"street/map2/map2_rock_01.png",
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
		HELL_FIRE | STONE_ROTE
	},
	{
		"street/map2/map2_rock_02.png",
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
	{
		"street/map2/map2_sea_00.png",
		"",
		181, 106,
		"                "
		"                "
		"                "
		"                "
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
		"#########~~~~~~~"
		"################",
		DECEASED_PURPLE | MOTH | STONE_FLY
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		169, 109,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"      -         "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		WATER_GHOST
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		150, 111,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		STONE_FLY | MIASMA_GRAY | HELL_FIRE
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		135, 113,
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
		"~~~~~~~~~~~~~~~~"
		"################",
		WATER_GHOST | STONE_FLY | EXTRUDEDSPRITS
	},
	{
		"street/map2/map2_sea_02.png",
		"",
		130, 116,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"           #####"
		"~~~~~~~~~~~#####"
		"################",
		WATER_MONK
	},
	{
		"street/map2/map2_brownstreet_00.png",
		"",
		84, 113,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		STONE_ROTE | MOTH
	},
	{
		"street/map2/map2_brownstreet_01.png",
		"",
		66, 121,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"   -            "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		STONE_ROTE | STONE_FLY
	},
	{
		"street/map2/map2_brownstreet_02.png",
		"",
		50, 141,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		STONE_ROTE | STONE_FLY | EXTRUDEDSPRITS
	},
	{
		"street/map2/map2_brownstreet_03.png",
		"",
		63, 145,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		FLOG_GREEN | FLOG_SMALL | HELL_FIRE
	},
	{
		"street/map2/map2_brownstreet_04.png",
		"",
		79, 145,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{
		"street/map2/map2_brownstreet_05.png",
		"",
		85, 146,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{
		"street/map2/map2_sea_00_01.png",
		"",
		105, 147,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"             ###"
		"################"
		"################",
		SKELETON_SPEAR | FLOG_SMALL
	},
	{
		"street/map2/map2_sea_00_02.png",
		"",
		119, 152,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"##              "
		"##~~~~~~~~~~~~~~"
		"################",
		EXTRUDEDSPRITS 
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		141, 152,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"    -           "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		STONE_FLY | MIASMA_GRAY
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		163, 148,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		WATER_MONK | HELL_FIRE
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		199, 138,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"        -       "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################",
		WATER_GHOST | MOTH
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		239, 135,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		WATER_MONK | STONE_FLY
	},
	{
		"street/map2/map2_sea_02.png",
		"",
		273, 134,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		" -              "
		"                "
		"                "
		"                "
		"           #####"
		"~~~~~~~~~~~#####"
		"################",
		MIASMA_WHITE
	},
	{
		"street/map2/map2_riverbed.png",
		"",
		291, 131,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{
		"street/map2/map2_gravel0.png",
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
	{
		"street/map2/map2_gravel1.png",
		"",
		308, 164,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	{
		"street/map2/map2_gravel2.png",
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
	{
		"street/map2/map2_gravel0.png",
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


Map2::Map2( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map2::~Map2( ) {
}

EnemyPtr Map2::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) ); break;
	case 'B': enemy = EnemyPtr( new EnemyStoneRote( x, y ) ); break;
	case 'C': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
	case 'D': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) ); break;
	case 'E': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
	case 'F': enemy = EnemyPtr( new EnemyWaterMonk( x, y ) ); break;
	case 'G': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) ); break;
	case 'H': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
	case 'I': enemy = EnemyPtr( new EnemySkeletonSpear( x, y ) ); break;
	case 'J': enemy = EnemyPtr( new EnemyRedFlogSmall( x, y ) ); break;
	case 'K': enemy = EnemyPtr( new EnemyHellFire( x, y ) ); break;
	case 'L': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) ); break;
	}

	return enemy;
}

BossPtr Map2::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossHag( stock, offset_x ) );
}
