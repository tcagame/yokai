#include "EnemyMiasmaGray.h"

static const int WAIT_ANIME_TIME = 3;
static const int MOVE_SPEED = 1;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 10;
static const int POW = 3;

EnemyMiasmaGray::EnemyMiasmaGray( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_anime_count( 0 ) {
}


EnemyMiasmaGray::~EnemyMiasmaGray( ) {
}

void EnemyMiasmaGray::act( ) {
	actMove( );
	updateChip( );
}

void EnemyMiasmaGray::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyMiasmaGray::updateChip( ) {
	const int MAX_ANIME_PATTERN = 4;
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _anime_count / WAIT_ANIME_TIME % MAX_ANIME_PATTERN;
	setChipGraph( GRAPH_ENEMY_NOMAL, pattern, 7 );
}
