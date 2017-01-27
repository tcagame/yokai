#include "EnemyBowDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;
static const int MOVE_SPEED = 5;
static const int WAIT_ANIME_TIME = 30;

EnemyBowDemon::EnemyBowDemon( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyBowDemon::~EnemyBowDemon( ) {
}

void EnemyBowDemon::act( ) {
	actMove( );
	updateChip( );
}

void EnemyBowDemon::actMove( ) {
	setAccelX( -MOVE_SPEED );
}

void EnemyBowDemon::updateChip( ) {
	const int MAX_ANIME_PATTERN = 15;
	const int ANIME[ MAX_ANIME_PATTERN ] = { 7, 8, 9, 8, 7, 8, 9, 8, 7, 8, 9, 10, 11, 12, 13 };
	int u = ANIME[ getX( ) / WAIT_ANIME_TIME % MAX_ANIME_PATTERN ];
	int v = 5;
	setChipGraph( GRAPH_ENEMY_NOMAL, u, v );
}