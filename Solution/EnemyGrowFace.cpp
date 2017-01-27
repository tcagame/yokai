#include "EnemyGrowFace.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 8;
static const int CHIP_SIZE = 72;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyGrowFace::EnemyGrowFace( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
}


EnemyGrowFace::~EnemyGrowFace( ) {
}

void EnemyGrowFace::act( ) {
	actMove( );
	updateChip( );
}

void EnemyGrowFace::actMove( ) {
	setAccelX( -MOVE_SPEED );

}

void EnemyGrowFace::updateChip( ) {
	const int MAX_ANIME_PATTERN = 2;
	const int ANIME_PATTERN[ MAX_ANIME_PATTERN ] = { 6, 7 };
	int pattern = ANIME_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];
	setChipGraph( GRAPH_ENEMY_SMALL, pattern, 5 );
}
