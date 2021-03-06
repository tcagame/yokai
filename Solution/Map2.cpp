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
#include "EnemyRedbird.h"
#include "EnemyHugDemon.h"
#include "BossHag.h"
#include "EnemyNoNeckGhost.h"
#include "EnemyHandMonster.h"
#include "EnemyRayMonster.h"
#include "EnemyAnimal.h"


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
		"################"
	},
	{
		"street/map2/map2_start_01.png",
		"",
		0, 0,
		"                "
		"                "
		"                "
		"             ## "
		"             ###"
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
		"################"
	},
	{
		"street/map2/map2_start_02.png",
		"",
		0, 0,
		"             ###"
		"             ###"
		"             ###"
		"             ###"
		"#          B ###"
		"         $   ###"
		"    ############"
		"  ##############"
		"################"
		"################"
		"################"
		"################"
		"################"
		"                "
		"################"
		"################"
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
		"N               "
		"################"
		"################"
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
		"J  J  J  J      "
		"                "
		"################"
		"################"
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
		"          B     "
		"################"
		"################"
	},
	{
		"street/map2/map2_sea_00.png",
		"",
		181, 106,
		"                "
		"                "
		"                "
		"                "
		"              C "
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
		"################"
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		169, 109,
		"                "
		"                "
		"                "
		"               H"
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
		"################"
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		150, 111,
		"                "
		"                "
		"                "
		"              L "
		"                "
		"                "
		"      E         "
		"                "
		"                "
		"        -       "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"           C    "
		"        -       "
		"                "
		"                "
		"                "
		"  G             "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"   G            "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"   G            "
		"~~~~~~~~~~~~~~~~"
		"################"
	},
	{//���Q�n�_
		"street/map2/map2_sea_02.png",
		"",
		130, 116,
		"                "
		"                "
		"   Q            "
		"          Q     "
		"    Q  Q        "
		"Q         Q  Q  "
		"    Q  Q        "
		"          Q     "
		"   Q            "
		"                "
		"                "
		"                "
		"           #####"
		"           #####"
		"~~~~~~~~~~~#####"
		"################"
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
		"#               "
		"#     t         "
		"################"
		"################"
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
		"         P  P  P"
		"################"
		"################"
	},
	{
		"street/map2/map2_brownstreet_02.png",
		"",
		50, 141,
		"                "
		"                "
		"                "
		"                "
		"     E          "
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
		"       N        "
		"################"
		"################"
	},
	{
		"street/map2/map2_brownstreet_04.png",
		"",
		79, 145,
		"                "
		"                "
		"                "
		"                "
		"       H        "
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
		"      I         "
		"################"
		"################"
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
		"       I    B###"
		"################"
		"################"
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
		"##       F      "
		"##~~~~~~~~~~~~~~"
		"################"
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
		"          G     "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"               C"
		"                "
		"      -         "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"       G        "
		"~~~~~~~~~~~~~~~~"
		"################"
	},
	{
		"street/map2/map2_sea_01.png",
		"",
		163, 148,
		"                "
		"                "
		"                "
		"        H       "
		"                "
		"                "
		"                "
		"                "
		"                "
		"      -         "
		"                "
		"                "
		"                "
		"             F  "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"           G    "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"          F     "
		"     -          "
		"                "
		"                "
		"                "
		"                "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"    -           "
		"                "
		"                "
		"                "
		"         G      "
		"~~~~~~~~~~~~~~~~"
		"################"
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
		"################"
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
		"################"
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
		"            s   "
		"################"
		"################"
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
		"################"
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
		"################"
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
		"################"
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
	case 'B': enemy = EnemyPtr( new EnemyStoneRote( x, y, false ) ); break;
	case 'C': enemy = EnemyPtr( new EnemyStoneFly( x, y ) ); break;
	case 'D': enemy = EnemyPtr( new EnemyMiasmaGray( x, y ) ); break;
	case 'E': enemy = EnemyPtr( new EnemyMiasmaWhite( x, y ) ); break;
	case 'F': enemy = EnemyPtr( new EnemyWaterMonk( x, y ) ); break;
	case 'G': enemy = EnemyPtr( new EnemyWaterGhost( x, y ) ); break;
	case 'H': enemy = EnemyPtr( new EnemyExtrudedSpirits( x, y ) ); break;
	case 'I': enemy = EnemyPtr( new EnemySkeletonSpear( x, y ) ); break;
	case 'J': enemy = EnemyPtr( new EnemyRedFlogSmall( x, y ) ); break;
	case 'L': enemy = EnemyPtr( new EnemyRedbird( stock, x - BG_SIZE * 3, y ) ); break;
	case 'M': enemy = EnemyPtr( new EnemyDeceasedGreen( x, y ) ); break;
	case 'N': enemy = EnemyPtr( new EnemyHugDemon( x, y ) ); break;
	case 'O': enemy = EnemyPtr( new EnemyNoNeckGhost( x, y ) ); break;
	case 'P': enemy = EnemyPtr( new EnemyHandMonster( stock, x, y ) ); break;
	case 'Q': enemy = EnemyPtr( new EnemyRayMonster( x, y ) ); break;
	case 's': enemy = EnemyPtr( new EnemyAnimal( x, y, GRAPH_ENEMY_ANIMAL_DOG ) ); break;
	case 't': enemy = EnemyPtr( new EnemyAnimal( x, y, GRAPH_ENEMY_ANIMAL_CAT ) ); break;
	}

	return enemy;
}

BossPtr Map2::generateBoss( EnemyStockPtr stock ) const {
	int offset_x = getPanelNum( ) * BG_SIZE - BG_SIZE;
	return BossPtr( new BossHag( stock, offset_x ) );
}
