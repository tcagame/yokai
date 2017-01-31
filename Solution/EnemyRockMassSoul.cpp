#include "EnemyRockMassSoul.h"

static const int WAIT_ANIME_TIME = 2;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = -60;
static const int HP  = 10;
static const int POW = 3;
static const int MAX_ANIME_PATTERN = 8;

EnemyRockMassSoul::EnemyRockMassSoul( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_count( 0 ) {
}


EnemyRockMassSoul::~EnemyRockMassSoul( ) {
}

void EnemyRockMassSoul::act( ) {
	updateChip( );
}

void EnemyRockMassSoul::updateChip( ) {
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	const int v = 10;
	const int MOTION[ MAX_ANIME_PATTERN ] = { 4, 5, 6, 7, 8, 9, 10, 11 };
	int u = MOTION[ ( _count / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );
}