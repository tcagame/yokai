#include "EnemyRedbirdAttack.h"

static const int CHIP_SIZE = 108;
static const int FOOT = 20;
static const int MAX_ANIME_PATTERN = 3;
static const int WAIT_PATTERN_TIME = 5;
static const int MOVE_VERTICAL_SPEED = 6;

EnemyRedbirdAttack::EnemyRedbirdAttack( int x, int y ) :
Enemy( x, y, GRAPH_ENEMY_REDBIRD_ATTACK, CHIP_SIZE, FOOT, false ) {
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
	int pattern = ( getX( ) / WAIT_PATTERN_TIME ) % MAX_ANIME_PATTERN;
	setChipUV( pattern, 0 );
}
