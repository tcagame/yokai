#include "EnemyRedbirdAttack.h"

static const int MAX_ANIME_PATTERN = 3;
static const int WAIT_PATTERN_TIME = 8;
static const int MOVE_VERTICAL_SPEED = 6;
static const int MOVE_HORIZONTAL_SPEED = 10;
static const int WAIT_TURN_TIME = 8;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;

EnemyRedbirdAttack::EnemyRedbirdAttack( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, CHIP_SIZE, CHIP_FOOT, false ),
_act_count( 0 ) {
}


EnemyRedbirdAttack::~EnemyRedbirdAttack( ) {
}

void EnemyRedbirdAttack::act( ) {
	actMove( );
	updateChip( );
}

void EnemyRedbirdAttack::actMove( ) {
	setAccelY( MOVE_VERTICAL_SPEED );
}

void EnemyRedbirdAttack::updateChip( ) {
	_act_count++;
	_act_count %= MAX_ANIME_PATTERN * WAIT_PATTERN_TIME;
	int pattern = _act_count / WAIT_PATTERN_TIME;
	setChipGraph( GRAPH_ENEMY, pattern, 2 );
}
