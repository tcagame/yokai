#include "EnemyYadokariYokai.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;

EnemyYadokariYokai::EnemyYadokariYokai( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_action( ACTION_APPEAR ),
_act_count( 0 ) {
}


EnemyYadokariYokai::~EnemyYadokariYokai( ) {
}

void EnemyYadokariYokai::act( ) {
	updateChip( );
	_act_count++;
}

void EnemyYadokariYokai::updateChip( ) {
	if ( _action == ACTION_APPEAR ) {
		const int ANIME[ ] = { 9, 10, 11 };
		int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
		int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
		int v = 14;
		setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
		if ( u == 11 ) {
			_action = ACTION_NOMAL;
			return;
		}
	}
	if ( _action == ACTION_NOMAL ) {
		const int ANIME[ ] = { 11, 12, 13, 12, 13, 12 };
		int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
		int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
		int v = 14;
		setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
	}
}