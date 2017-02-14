#include "Map3.h"
#include "define.h"
#include "BossEnma.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyRockMass.h"
#include "EnemyBloodPondDemon.h"
#include "EnemyTreeMonster.h"
#include "EnemyStoneFly.h"
#include "EnemyStoneRote.h"
#include "EnemyShishimai.h"
#include "EnemyShishimaiDemon.h"
#include "EnemyHellFire.h"
#include "EnemyWindMonster.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyJizo.h"
#include "EnemyOnyudo.h"
#include "EnemyEyeSpector.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyRedbird.h"
#include "EnemyBat.h"
#include "EnemyRollOverNeckSkull.h"
#include "EnemyRollOverNeckWoman.h"
#include "EnemyBowDemon.h"
#include "EnemyRedFlogSmall.h"
#include "EnemyNoFace.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyCrocodileSnake.h"
#include "EnemyHugDemon.h"

static const Map::Panel panel[] = {
	{//1
		"street/map3/bg/map3_00_00.png",
		"",
		10, 115,
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
		"################"
	},
	{//2
		"street/map3/bg/map3_00_01.png",
		"street/map3/cover/bg_cover.png",
		70, 110,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	},
	{//3
		"street/map3/bg/map3_00_02.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"T               "
		"                "
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
	},
	{//4
		"street/map3/bg/map3_00_04.png",
		"",
		130, 130,
		"          *##   "
		"           *##  "
		"            *## "
		"             *##"
		"          D   *#"
		"               *"
		"               E"
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"               F"
		"################"
		"################"
	},
	{//5
		"street/map3/bg/map3_00_05.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"       R     H  "
		"                "
		"##              "
		"*###############"
		" ***************"
		"                "
		"                "
		"                "
		"                "
		"                "
		"  N     S     S "
		"################"
		"################"
	},
	{//6
		"street/map3/bg/map3_00_06.png",
		"",
		0, 0,
		"   #            "
		"   #          O "
		"   #            "
		"   #############"
		"               #"
		"               #"
		"################"
		"****************"
		"     E          "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################"
	},
	{//7
		"street/map3/bg/map3_00_07.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"      R         "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              ##"
		"  U     G     ##"
		"################"
		"################"
	},
	{//8
		"street/map3/bg/map3_00_09.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"               I"
		"                "
		"                "
		"                "
		"                "
		"                "
		"   #############"
		"   #############"
		"################"
		"################"
		"################"
		"################"
	},
	{//9
		"street/map3/bg/map3_00_10.png",
		"",
		165, 130,
		"                "
		"                "
		"                "
		"   R            "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"########        "
		"########        "
		"########        "
		"########++++++++"
		"################"
		"################"
	},
	{//10
		"street/map3/bg/map3_00_11.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"       A        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"++++++++++++++++"
		"################"
		"################"
	},
	{//11
		"street/map3/bg/blood_stairs.png",
		"",
		190, 130,
		"                "
		"                "
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
		"+++++++++#######"
		"################"
		"################"
	},
	{//12
		"street/map3/bg/blood_stair_2.png",
		"",
		0, 0,
		"                "
		"                "
		" $              "
		"                "
		"             W  "
		"                "
		"                "
		"              H "
		"        ########"
		"      ##########"
		"    ############"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//13
		"street/map3/bg/map3_00_14.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"               -"
		"      M         "
		"########        "
		"########        "
		"########^^^^^^^^"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//14
		"street/map3/bg/map3_00_15.png",
		"",
		195, 150,
		"                "
		"                "
		"                "
		"        P       "
		"                "
		"                "
		"        ^^      "
		"        ##      "
		"      ^^##^^    "
		"     ^######^^^^"
		"^^^^############"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//15
		"street/map3/bg/map3_00_16.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		" Q              "
		"                "
		"          V     "
		"                "
		"                "
		"                "
		"               #"
		"               #"
		"^^^^####^^^^^^^#"
		"################"
		"################"
		"################"
	},
	{//16
		"street/map3/bg/map3_00_17.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"             I  "
		"                "
		"                "
		"                "
		"####            "
		"####            "
		"####            "
		"####            "
		"####            "
		"####            "
		"####            "
		"####            "
	},
	{//17
		"street/map3/bg/map3_00_18.png",
		"",
		170, 150,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"  ##############"
		"  ##############"
	},
	{//18
		"street/map3/bg/map3_00_19.png",
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
		"################"
	},
	{//19
		"street/map3/bg/map3_00_20.png",
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
		"################"
	},
	{//20
		"street/map3/bg/map3_00_21.png",
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
		"    B           "
		"################"
		"################"
	},
	{//21
		"street/map3/bg/map3_00_22.png",
		"street/map3/cover/tree_1.png",
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
		"################"
	},
	{//22
		"street/map3/bg/map3_00_23.png",
		"street/map3/cover/tree_2.png",
		0, 0,
		"                "
		"        $       "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		" M       Y      "
		"################"
		"################"
	},
	{//23
		"street/map3/bg/map3_00_24.png",
		"",
		85, 190,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"Z      X        "
		"################"
		"################"
	},
	{//24
		"street/map3/bg/map3_00_25.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"E        E      "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"X  J     L     Y"
		"################"
		"################"
	},
	{//25
		"street/map3/bg/map3_00_26.png",
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
		"   S   S  S   S "
		"################"
		"################"
	},
	{//26
		"street/map3/bg/map3_00_27.png",
		"",
		150, 155,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"        E       "
		"                "
		"                "
		"                "
		"                "
		"   L            "
		"################"
		"################"
	},
	{//27
		"street/map3/bg/map3_00_28.png",
		"",
		170, 180,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	},
	{//28
		"street/map3/bg/map3_00_29.png",
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
		"               K"
		"                "
		"                "
		"                "
		"                "
		"################"
		"################"
	},
	{//29
		"street/map3/bg/map3_00_30.png",
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
		"C               "
		"###############~"
		"################"
	},
	{//30
		"street/map3/bg/map3_00_31.png",
		"",
		0, 0,
		"                "
		"         $      "
		"                "
		"                "
		"                "
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
		"################"
	},
	{//31
		"street/map3/bg/map3_00_32.png",
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
		"~~~~############"
		"################"
	},
	{//31
		"street/map3/bg/map3_00_33.png",
		"",
		333, 190,
		"                "
		"                "
		"                "
		"                "
		"                "
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
	},
	{//32
		"street/map3/bg/map3_00_34.png",
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
		"   #############"
		"   #############"
		"   #############"
		"################"
		"################"
	},
	{//33
		"street/map3/bg/map3_00_34.png",
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
		"################"
	},
};


Map3::Map3( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map3::~Map3( ) {
}

EnemyPtr Map3::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyBloodPondDemon( stock, x, y ) ); break;
	case 'B': enemy = EnemyPtr( new EnemyTreeMonster( stock, x, y ) ); break;
	case 'C': enemy = EnemyPtr( new EnemyRockMass( stock, x, y ) ); break;
	case 'D': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
	case 'E': enemy = EnemyPtr( new EnemyStoneRote( x, y, false ) ); break;
	case 'F': enemy = EnemyPtr( new EnemyShishimai( x, y ) ); break;
	case 'G': enemy = EnemyPtr( new EnemyShishimaiDemon( x, y ) ); break;
	case 'H': enemy = EnemyPtr( new EnemyHellFire( x, y ) ); break;
	case 'I': enemy = EnemyPtr( new EnemyWindMonster( stock, x + 300, y ) ); break;
	case 'J': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) ); break;
	case 'K': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
	case 'L': enemy = EnemyPtr( new EnemyJizo( stock, x, y ) ); break;
	case 'M': enemy = EnemyPtr( new EnemyOnyudo( x, y ) ); break;
	case 'N': enemy = EnemyPtr( new EnemyEyeSpector( x, y ) ); break;
	case 'O': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
	case 'P': enemy = EnemyPtr( new EnemyBat( x, y ) ); break;
	case 'Q': enemy = EnemyPtr( new EnemyRollOverNeckSkull( x, y ) ); break;
	case 'R': enemy = EnemyPtr( new EnemyRedbird( stock, x - BG_SIZE * 3, y ) ); break;
	case 'S': enemy = EnemyPtr( new EnemyBowDemon( stock, x, y ) ); break;
	case 'T': enemy = EnemyPtr( new EnemyRedFlogSmall( x, y ) ); break;
	case 'U': enemy = EnemyPtr( new EnemyNoFace( x, y ) ); break;
	case 'V': enemy = EnemyPtr( new EnemyNoNeckGhost( x, y ) ); break;
	case 'W': enemy = EnemyPtr( new EnemyRollOverNeckWoman( x, y ) ); break;
	case 'X': enemy = EnemyPtr( new EnemyHugDemon( x, y ) ); break;
	case 'Y': enemy = EnemyPtr( new EnemyCrocodileSnake( stock, x, y ) ); break;
	case 'Z': enemy = EnemyPtr( new EnemyOneEyesSnake( x, y ) ); break;
	}

	return enemy;
}

BossPtr Map3::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossEnma( stock, offset_x ) );
}
