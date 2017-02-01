#include "Map4.h"
#include "define.h"
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"
#include "EnemyDeceasedFourth.h"
#include "EnemyMiasmaGray.h"
#include "EnemyRedbird.h"
#include "EnemyStoneFly.h"
#include "EnemyStoneRote.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyFlogSmall.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyDeceasedPurple.h"
#include "EnemyMoth.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyOnyudo.h"
#include "EnemyNoFace.h"
#include "EnemyRedFlogSmall.h"
#include "EnemyMiasmaWhite.h"
#include "EnemySkeletonSpear.h"
#include "EnemyWaterGhost.h"
#include "EnemyHellFire.h"
#include "EnemyBowDemon.h"
#include "EnemyShishimai.h"
#include "BossBuddha.h"

static const Map::Panel panel[] = {
	{
		"street/map4/bg/map4_00.png",
		"",
		35, 107,
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
		"street/map4/bg/map4_01.png",
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
		"street/map4/bg/map4_02.png",
		"",
		40, 120,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		" L        L    V"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_03.png",
		"",
		0, 0,
		"               I"
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              G "
		"                "
		"   N            "
		"     M         #"
		"               #"
		"     H    T    #"
		"######~~~~~~~~~#"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_04.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		" I              "
		"                "
		"                "
		"                "
		"                "
		"                "
		"######## A B C D"
		"########++++++++"
		"################"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_05.png",
		"street/map4/cover/map4_05_cover.png",
		60, 135,
		"          i     "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"   ############ "
		"   ############ "
		"   ############ "
		"   ############ "
		"+++############+"
		"################"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_06.png",
		"",
		0, 0,
		"　     I        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		" D C B A   #####"
		"+++++++++++#####"
		"################"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_07.png",
		"street/map4/cover/map4_07_cover.png",
		80, 125,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"  N             "
		"                "
		"    N           "
		"                "
		"###             "
		"###             "
		"###             "
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_08.png",
		"",
		85, 120,
		"             i  "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              = "
		"               -"
		"                "
		"                "
		"#####           "
		"#####           ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		0, 0,
		"                "
		"       I        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"         G      "
		"           -    "
		"            -   "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
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
		"      -         "
		"              - "
		"       -        "
		"             =  "
		"              G "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		100, 90,
		"                "
		"           I    "
		"                "
		"                "
		"                "
		"                "
		"         -      "
		"                "
		"     G          "
		"            =   "
		"                "
		"             -  "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"         G      "
		"                "
		"                "
		"                "
		"       -        "
		"                "
		"                "
		"                "
		"                "
		"         -      "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		0, 0,
		"                "
		"              I "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"     -          "
		"                "
		"              G "
		"                "
		"    =           "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"        I       "
		"                "
		"                "
		"                "
		"                "
		" =            - "
		"             -  "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_09.png",
		"",
		0, 0,
		"                "
		"                "
		" I              "
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
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_10.png",
		"",
		251, 178,
		"                "
		"                "
		"I               "
		"                "
		"                "
		"                "
		"                "
		"                "
		"          G     "
		"                "
		"G               "
		"                "
		"                "
		"                "
		"          ######"
		"          ######",
		NONE
	},
	{
		"street/map4/bg/map4_11.png",
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
		"street/map4/bg/map4_12.png",
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
		"        W       "
		"                "
		"                "
		"      O        #"
		"             S #"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_13.png",
		"",
		178, 154,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"K               "
		"   O            "
		"                "
		"   #############"
		"   #############"
		"################"
		"################"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_14.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"F               "
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
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_15.png",
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
		"       E        "
		"                "
		"     E          "
		"                "
		"++++++++++++++++"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_15.png",
		"",
		0, 0,
		"                "
		"                "
		"         I      "
		"                "
		"                "
		"   I            "
		"                "
		"            f   "
		"                "
		"     G          "
		"                "
		"      E         "
		"                "
		"++++++++++++++++"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_15.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"               I"
		"                "
		"                "
		"                "
		"                "
		"            E   "
		"        -       "
		"                "
		"++++++++++++++++"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_15.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"              I "
		"                "
		"                "
		"    E           "
		"                "
		"          E     "
		"                "
		"++++++++++++++++"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_15.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"               I"
		"                "
		"                "
		"          E     "
		"                "
		"                "
		"                "
		"++++++++++++++++"
		"################"
		"################",
		NONE
	},
	{
		"street/map4/bg/map4_16.png",
		"",
		172, 143,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"++++++++++++++  "
		"##############  "
		"##############  ",
		NONE
	},
	{
		"",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"                "
		"                "
		"                "
		"            =   "
		"                "
		"                "
		"             G  "
		"                "
		"   -            "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"",
		"",
		0, 0,
		"    I           "
		"                "
		"           I    "
		"                "
		"                "
		"                "
		"                "
		"                "
		"   =            "
		"                "
		"                "
		"            =   "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"",
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
		"       =        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"",
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
		"       =        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"",
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
		"       =        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"",
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
		"       =        "
		"                "
		"                "
		"                "
		"                "
		"                "
		"                ",
		NONE
	},
	{
		"street/map4/bg/map4_90.png",
		"",
		176, 24,
		"                "
		"                "
		"                "
		"                "
		"                "
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
		"  ##############",
		NONE
	},
	{
		"street/map4/bg/map4_91.png",
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
		"",
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


Map4::Map4( ) :
Map( panel, sizeof( panel ) / sizeof( Map::Panel ) - 1 ) {
}


Map4::~Map4( ) {
}

EnemyPtr Map4::generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const {
	EnemyPtr enemy;

	int shift_back_x = x - BG_SIZE * 3; // 3つ先に置くと3つ前の時に後ろから出る

	switch ( ch ) {
	case 'A': enemy = EnemyPtr( new EnemyDeceasedFirst( x, y ) ); break;
	case 'B': enemy = EnemyPtr( new EnemyDeceasedSecond( x, y ) ); break;
	case 'C': enemy = EnemyPtr( new EnemyDeceasedThird( x, y ) ); break;
	case 'D': enemy = EnemyPtr( new EnemyDeceasedFourth( x, y ) ); break;
	case 'E': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) ); break;
	case 'F': enemy = EnemyPtr( new EnemyRedbird( stock, x, y ) ); break;
	case 'f': enemy = EnemyPtr( new EnemyRedbird( stock, shift_back_x, y ) ); break;
	case 'G': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
	//case 'g': enemy = EnemyPtr( new EnemyStoneFly( shift_x, y ) ); break;
	case 'H': enemy = EnemyPtr( new EnemyStoneRote( x, y ) ); break;
	case 'I': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
	case 'i': enemy = EnemyPtr( new EnemyExtrudedSpirits( shift_back_x, y ) ); break;
	case 'J': enemy = EnemyPtr( new EnemyFlogSmall( x, y ) ); break;
	case 'K': enemy = EnemyPtr( new EnemyOneEyesSnake( x, y ) ); break;
	case 'L': enemy = EnemyPtr( new EnemyDeceasedPurple( x, y ) ); break;
	case 'M': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) ); break;
	case 'N': enemy = EnemyPtr( new EnemyMoth( x, y ) ); break;
	case 'O': enemy = EnemyPtr( new EnemyOnyudo( x, y ) ); break;
	case 'P': enemy = EnemyPtr( new EnemyNoFace( x, y ) ); break;
	case 'Q': enemy = EnemyPtr( new EnemyRedFlogSmall( x, y ) ); break;
	case 'R': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
	case 'S': enemy = EnemyPtr( new EnemySkeletonSpear( x, y ) ); break;
	case 'T': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) ); break;
	case 'U': enemy = EnemyPtr( new EnemyHellFire( x, y ) ); break;
	case 'V': enemy = EnemyPtr( new EnemyBowDemon( stock, x, y ) ); break;
	case 'W': enemy = EnemyPtr( new EnemyShishimai( x, y ) ); break;
	}

	return enemy;
}

BossPtr Map4::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossBuddha( stock, offset_x ) );
}
