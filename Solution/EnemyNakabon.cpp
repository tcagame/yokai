#include "EnemyNakabon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;

EnemyNakabon::EnemyNakabon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
}


EnemyNakabon::~EnemyNakabon( ) {
}

void EnemyNakabon::act( ) {
	const int ANIME[ ] = { 8, 9, 10, 9, 8, 11, 8, 11 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 11;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );

	_act_count++;
}