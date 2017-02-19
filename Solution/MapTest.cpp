#include "MapTest.h"
#include "define.h"
#include "EnemyStock.h"
#include "BossRedDemon.h"
#include "EnemyBat.h"
#include "EnemyBloodPondDemon.h"
#include "EnemyBlueMonk.h"
#include "EnemyBowDemon.h"
#include "EnemyCrocodileSnake.h"
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedFourth.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyEyeSpector.h"
#include "EnemyFlog.h"
#include "EnemyFlogChief.h"
#include "EnemyHandMonster.h"
#include "EnemyHellFire.h"
#include "EnemyHugDemon.h"
#include "EnemyJizo.h"
#include "EnemyMiasmaGray.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyNakabon.h"
#include "EnemyNoFace.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyRayMonster.h"
#include "EnemyRockMass.h"
#include "EnemyRollOverNeckWoman.h"
#include "EnemyShishimai.h"
#include "EnemyShishimaiDemon.h"
#include "EnemyStoneMortgage.h"
#include "EnemySkeletonSpear.h"
#include "EnemyRollOverNeckSkull.h"
#include "EnemyWaterGhost.h"
#include "EnemyGhoul.h"
#include "EnemyMoth.h"
#include "EnemyOnyudo.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyRedbird.h"
#include "EnemyStoneRote.h"
#include "EnemyStoneFly.h"
#include "EnemyTree.h"
#include "EnemyGhost.h"
#include "EnemyWaterMonk.h"
#include "EnemyWindMonster.h"
#include "EnemyYadokariYokai.h"
#include "EnemyAnimal.h"

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
		"################"
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
		" $    s t#######"
		"################"
		"################"
	},
	{//2
		"street/map0/bg/map0_02_00.png",
		"",
		70, 60,
		"                "
		"                "
		"                "
		"                "
		"        A  B    "
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
		"################"
	},
	{//3
		"street/map0/bg/map0_04_00.png",
		"",
		80, 80,
		"                "
		"                "
		" =              "
		"                "
		"                "
		"                "
		"                "
		"                "
		"             -  "
		"                "
		"                "
		"                "
		"       C        "
		"~~~~~~~~~~~~~~~~"
		"################"
		"################"
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
		"~~###########D E"
		"################"
		"################"
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
		" FG#############"
		"################"
		"################"
	},
	{//6
		"street/map0/bg/map0_07_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"   H           I"
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
		"#               "
	},
	{//7
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
		"      J         "
		"~~~~~~~~~~~~~~~~"
		"################"
	},
	{//8
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
		"      ##########"
		"#####           "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
	},
	{//9
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
		"     K          "
		"###########     "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
	},
	{//10
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
		"          L     "
		"################"
		"################"
	},
	{//11
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
		"################"
	},
	{//12
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
		"################"
	},
	{//13
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
		"      M         "
		"                "
		"                "
		"                "
		"                "
		"                "
		"         N      "
		"################"
		"################"
	},
	{//14
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
		" O              "
		"                "
		"                "
		"             P  "
		"################"
		"################"
	},
	{//15
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
		"     Q          "
		"################"
		"################"
	},
	{//16
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
		"             W  "
		"################"
		"################"
	},
	{//17
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
		"################"
	},
	{//18
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
		"################"
	},
	{//19
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
		"         V      "
		"                "
		"                "
		"  R     S       "
		"################"
		"################"
	},
	{//20
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
		"     T       r  "
		"################"
		"################"
	},
	{//21
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
		"         U      "
		"                "
		"              p "
		"################"
		"################"
	},
	{//22
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
		"        q       "
		"                "
		"   X          Y "
		"################"
		"################"
	},
	{//23
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
		"      Z        a"
		"################"
		"################"
	},
	{//24
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
		"    b       o   "
		"################"
		"################"
	},
	{//25
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
		"################"
	},
	{//26
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
		"    d           "
		"                "
		"      c         "
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//27
		"street/map1/bg/map1_24.png",
		"street/map1/cover/cave_3.png",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"          g     "
		"      e      f  "
		"                "
		"                "
		"                "
		"################"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//28
		"street/map3/bg/map3_00_07.png",
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
		"           m    "
		"                "
		"                "
		"                "
		"              ##"
		"        h     ##"
		"################"
		"################"
	},
	{//29
		"street/map3/bg/map3_00_09.png",
		"",
		0, 0,
		"                "
		"    k           "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              i "
		"                "
		"   #############"
		"   #############"
		"################"
		"################"
		"################"
		"################"
	},
	{//30
		"street/map3/bg/map3_00_10.png",
		"",
		165, 130,
		"                "
		"                "
		"                "
		"                "
		"   j            "
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
	{//31
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
		"       l        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"++++++++++++++++"
		"################"
		"################"
	},
	{//32
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
	{//33
		"street/map3/bg/blood_stair_2.png",
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
		"        ########"
		"      ##########"
		"    ############"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//34
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
		"                "
		"########        "
		"########        "
		"########^^^^^^^^"
		"################"
		"################"
		"################"
		"################"
		"################"
	},
	{//35
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
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################"
	},
	{//36
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
		"        n       "
		"###############~"
		"################"
	},
	{//37
		"street/map3/bg/map3_00_31.png",
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
		"################"
	},
	{//38
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
	{//39
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
		"                "
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
		"                "
	},
	{//40
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
		"################"
	},
	{//41
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
		"################"
	},
	{//42
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
		"################"
	},
	{//43
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
		"################"
	},
};


MapTest::MapTest( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


MapTest::~MapTest( ) {
}

EnemyPtr MapTest::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
		case 'A': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) ); break;
		case 'B': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) ); break;
		case 'C': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) ); break;
		case 'D': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) ); break;
		case 'E': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) ); break;
		case 'F': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) ); break;
		case 'G': enemy = EnemyPtr( new EnemyDeceasedFourth( x, y ) ); break;
		case 'H': enemy = EnemyPtr( new EnemyMoth( x, y ) ); break;
		case 'I': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
		case 'J': enemy = EnemyPtr( new EnemyWaterMonk( x, y ) ); break;
		case 'K': enemy = EnemyPtr( new EnemyFlog( stock, x, y ) ); break;
		case 'L': enemy = EnemyPtr( new EnemyTree( stock, x, y ) ); break;
		case 'M': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) ); break;
		case 'N': enemy = EnemyPtr( new EnemySkeletonSpear( x, y ) ); break;
		case 'O': enemy = EnemyPtr( new EnemyNoNeckGhost( x, y ) ); break;
		case 'P': enemy = EnemyPtr( new EnemyGhost( x, y ) ); break;
		case 'Q': enemy = EnemyPtr( new EnemyBowDemon( stock, x, y ) ); break;
		case 'R': enemy = EnemyPtr( new EnemyHandMonster( stock, x, y ) ); break;
		case 'S': enemy = EnemyPtr( new EnemyJizo( stock, x, y ) ); break;
		case 'T': enemy = EnemyPtr( new EnemyCrocodileSnake( stock, x, y ) ); break;
		case 'U': enemy = EnemyPtr( new EnemyRollOverNeckWoman( x, y ) ); break;
		case 'V': enemy = EnemyPtr( new EnemyStoneRote( x, y, false ) ); break;
		case 'W': enemy = EnemyPtr( new EnemyFlogChief( stock, x, y ) ); break;
		case 'X': enemy = EnemyPtr( new EnemyBlueMonk( x, y ) ); break;
		case 'Y': enemy = EnemyPtr( new EnemyOnyudo( x, y ) ); break;
		case 'Z': enemy = EnemyPtr( new EnemyNakabon( x, y ) ); break;
		case 'a': enemy = EnemyPtr( new EnemyShishimai( x, y ) ); break;
		case 'b': enemy = EnemyPtr( new EnemyShishimaiDemon( x, y ) ); break;
		case 'c': enemy = EnemyPtr( new EnemyGhoul( x, y ) ); break;
		case 'd': enemy = EnemyPtr( new EnemyEyeSpector( x, y ) ); break;
		case 'e': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
		case 'f': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) ); break;
		case 'g': enemy = EnemyPtr( new EnemyBat( x, y ) ); break;
		case 'h': enemy = EnemyPtr( new EnemyNoFace( x, y ) ); break;
		case 'i': enemy = EnemyPtr( new EnemyRollOverNeckSkull( x, y ) ); break;
		case 'j': enemy = EnemyPtr( new EnemyWindMonster( stock, x, y ) ); break;
		case 'k': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
		case 'l': enemy = EnemyPtr( new EnemyBloodPondDemon( stock, x, y ) ); break;

		case 'n': enemy = EnemyPtr( new EnemyRockMass( stock, x, y ) ); break;
		case 'o': enemy = EnemyPtr( new EnemyOneEyesSnake( x, y ) ); break;
		case 'p': enemy = EnemyPtr( new EnemyHugDemon( x, y ) ); break;
		case 'q': enemy = EnemyPtr( new EnemyRayMonster( x, y ) ); break;
		case 'r': enemy = EnemyPtr( new EnemyYadokariYokai( x, y ) ); break;
		case 's': enemy = EnemyPtr( new EnemyAnimal( x, y, GRAPH_ENEMY_ANIMAL_DOG ) ); break;
		case 't': enemy = EnemyPtr( new EnemyAnimal( x, y, GRAPH_ENEMY_ANIMAL_CAT ) ); break;
	}
	
	return enemy;
}

BossPtr MapTest::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossRedDemon( stock, offset_x ) );
}