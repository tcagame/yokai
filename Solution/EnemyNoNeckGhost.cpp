#include "EnemyNoNeckGhost.h"

static const int MOVE_SPEED = 10;
static const int WAIT_ANIME_TIME = 40;
static const int WAIT_ATTACK_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 3;
static const int POW = 3;
static const int EXTIT_TIME = 80;

EnemyNoNeckGhost::EnemyNoNeckGhost( int x, int y ):
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_accel( 0 ) {

}


EnemyNoNeckGhost::~EnemyNoNeckGhost( ) {
}

void EnemyNoNeckGhost::act( ) {
	setAccelX( -MOVE_SPEED );
	const int MAX_ATTACK_PATTERN = 4;
	const int ATTACK_PATTERN[ MAX_ATTACK_PATTERN ] = { 4, 5, 6, 7 };
	int pattern = ATTACK_PATTERN[ ( getX( ) / WAIT_ANIME_TIME ) % MAX_ATTACK_PATTERN ];
	setChipGraph( GRAPH_ENEMY_NOMAL, pattern, 11 );
}
