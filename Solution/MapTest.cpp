#include "MapTest.h"
#include "define.h"
#include "EnemyDeceasedPurple.h"
#include "BossRedDemon.h"
#include "EnemyMoth.h"
#include "EnemyRockMass.h"

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
		SHISHIMAI
	},
	{//3 G[X
		"street/map0/bg/map0_04_00.png",
		"",
		100, 100,
		"                "
		"                "
		"                "
		"                "
		"        G       "
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
		"                "
		"                "
		"                "
		"  ###########   "
		"  ###########   "
		"~~             "
		"################"
		"################",
		BLUE_MONK | ROCK_MASS
	},
	{//5@©¹Á¿
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
		YADOKARI
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
	{//7@Í¶
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
		NONE
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
	{//9@ÏÔ­»KlÉ¡
		"street/map1/bg/map1_31.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"        D       "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"################"
		"################",
		TREE_MONSTER
	},
	{//10
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
	{//11@RE}
		"street/map0/bg/event_04_00.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"       E        "
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
	{//12
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
	{//13@õYmadaõ
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
	{//14
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
	{//15
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
	{//16
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
		NO_NECK_GHOST
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
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


MapTest::~MapTest( ) {
}

EnemyPtr MapTest::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	case 'B': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	case 'C': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	case 'D': enemy = EnemyPtr( new EnemyMoth( x, y ) );
		break;
	case 'E': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	case 'F': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	case 'G': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) );
	}

	return enemy;
}

BossPtr MapTest::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossRedDemon( stock, offset_x ) );
}
