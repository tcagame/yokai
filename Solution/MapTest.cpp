#include "MapTest.h"
#include "define.h"
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
#include "EnemyLittleBlueDemon.h"
#include "EnemyMiasmaGray.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyNakabon.h"
#include "EnemyNoFace.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyRayMonster.h"
#include "EnemyRedFlogSmall.h"
#include "EnemyRockMass.h"
#include "EnemyRollOverNeckWoman.h"
#include "EnemyShishimai.h"
#include "EnemyShishimaiDemon.h"
#include "EnemyStoneMortgage.h"
#include "EnemyRollOverNeckSkull.h"
#include "EnemyTreeMonster.h"
#include "EnemyWaterGhost.h"
#include "EnemyGhoul.h"
#include "EnemyManager.h"
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
#include "BossRedDemon.h"
#include "EnemyStock.h"

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
		"################"
	},
	{//1
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"              B "
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
		"################"
	},
	{//2
		"street/map0/bg/map0_02_00.png",
		"",
		0, 0,
		"                "
		"  C      1    D "
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
		"################"
	},
	{//3 エース
		"street/map0/bg/map0_04_00.png",
		"",
		100, 100,
		"                "
		"                "
		"                "
		"   E    2    o  "
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
		"################"
	},
	{//4
		"street/map0/bg/map0_05_00.png",
		"",
		0, 0,
		"                "
		"                "
		"     3     A    "
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
		"~~             "
		"################"
		"################"
	},
	{//5　かせっち☆
		"street/map0/bg/map0_06_00.png",
		"",
		0, 0,
		"                "
		"                "
		"             4  "
		"                "
		"                "
		"                "
		"                "
		"     FGIJ       "
		"   #############"
		"   #############"
		"   #############"
		"   #############"
		"   #############"
		"   #############"
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
		"        /   H   "
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
		"################"
	},
	{//7　河童
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
		"                "
	},
	{//8
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"         |      "
		"     K       L  "
		"                "
		"                "
		"                "
		"               #"
		"             ###"
		"           #####"
		"         #######"
		"################"
		"################"
	},
	{//9　変態くそメガネ伊藤
		"street/map1/bg/map1_31.png",
		"",
		0, 0,
		"                "
		"                "
		"        .       "
		" ,  M        N  "
		"                "
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
	{//10
		"street/map0/bg/event_04_00.png",
		"",
		0, 0,
		"                "
		"                "
		"       }        "
		"   O        P  @"
		"                "
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
	{//11　ヨコヤ・マ
		"street/map0/bg/event_04_00.png",
		"",
		0, 0,
		"                "
		"        {       "
		"  Q         R   "
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
		"           #####"
		"################"
		"################"
	},
	{//12
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"        [       "
		" ]  S        T  "
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
		"################"
	},
	{//13　†Ymada†
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"         !      "
		"  $  U      V   "
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
		"################"
	},
	{//14
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"       (       )"
		"  W         X   "
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
		"################"
	},
	{//15
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"   Y   %   Z   &"
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
		"################"
	},
	{//16
		"street/map0/bg/map0_01_00.png",
		"",
		0, 0,
		"                "
		"                "
		"    5       6   "
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
		"################"
	},
	{//47
		"street/map0/bg/map0_06_00.png",
		"",
		0, 0,
		"                "
		"   7        8   "
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
		"################"
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
		"################"
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
		"################"
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
		"################"
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
		case 'A': enemy = EnemyPtr( new EnemyBowDemon( stock, x, y ) ); break;
		case 'B': enemy = EnemyPtr( new EnemyCrocodileSnake( x, y ) ); break;
		case 'C': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
		case 'E': enemy = EnemyPtr( new EnemyEyeSpector( x, y ) ); break;
		case 'F': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) ); break;
		case 'G': enemy = EnemyPtr( new EnemyDeceasedFourth( x, y ) ); break;
		case 'H': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) ); break;
		case 'I': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) ); break;
		case 'J': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) ); break;
		case 'K': enemy = EnemyPtr( new EnemyFlog( stock, x, y ) ); break;
		case 'L': enemy = EnemyPtr( new EnemyFlogChief( stock, x, y ) ); break;
		case 'P': enemy = EnemyPtr( new EnemyHandMonster( stock, x, y ) ); break;
		case 'Q': enemy = EnemyPtr( new EnemyHellFire( x, y ) ); break;
		case 'S': enemy = EnemyPtr( new EnemyHugDemon( x, y ) ); break;
		case 'T': enemy = EnemyPtr( new EnemyJizo( stock, x, y ) ); break;
		case 'U': enemy = EnemyPtr( new EnemyLittleBlueDemon( x, y ) ); break;
		case 'V': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) ); break;
		case 'W': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
		case 'X': enemy = EnemyPtr( new EnemyNakabon( x, y ) ); break;
		case 'Y': enemy = EnemyPtr( new EnemyNoFace( x, y ) ); break;
		case 'Z': enemy = EnemyPtr( new EnemyNoNeckGhost( x, y ) ); break;
		case '{': enemy = EnemyPtr( new EnemyOneEyesSnake( x, y ) ); break;
		case '}': enemy = EnemyPtr( new EnemyRayMonster( x, y ) ); break;
		case '[': enemy = EnemyPtr( new EnemyRedFlogSmall( x, y ) ); break;
		case ']': enemy = EnemyPtr( new EnemyRockMass( stock, x, y ) ); break;
		case '@': enemy = EnemyPtr( new EnemyRollOverNeckWoman( x, y ) ); break;
		case '/': enemy = EnemyPtr( new EnemyShishimai( x, y ) ); break;
		case '.': enemy = EnemyPtr( new EnemyShishimaiDemon( x, y ) ); break;
		case ',': enemy = EnemyPtr( new EnemyStoneMortgage( x, y, 0 ) ); break;
		case '|': enemy = EnemyPtr( new EnemyRollOverNeckSkull( x, y ) ); break;
		case '!': enemy = EnemyPtr( new EnemyTreeMonster( stock, x, y ) ); break;
		case '$': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) ); break;
		case '%': enemy = EnemyPtr( new EnemyGhoul( x, y ) ); break;
		case '&': enemy = EnemyPtr( new EnemyMoth( x, y ) ); break;
		case '(': enemy = EnemyPtr( new EnemyOnyudo( x, y ) ); break;
		case ')': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) ); break;
		case '1': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) ); break;
		case '2': enemy = EnemyPtr( new EnemyStoneRote( x, y, false ) ); break;
		case '3': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
		case '4': enemy = EnemyPtr( new EnemyTree( stock, x, y ) ); break;
		case '5': enemy = EnemyPtr( new EnemyGhost( x, y ) ); break;
		case '6': enemy = EnemyPtr( new EnemyWaterMonk( x, y ) ); break;
		case '7': enemy = EnemyPtr( new EnemyWindMonster( stock, x, y ) ); break;
		case '8': enemy = EnemyPtr( new EnemyYadokariYokai( x, y ) ); break;
	}
	
	return enemy;
}

BossPtr MapTest::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossRedDemon( stock, offset_x ) );
}
