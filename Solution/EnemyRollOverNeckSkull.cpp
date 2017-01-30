#include "EnemyRollOverNeckSkull.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;

EnemyRollOverNeckSkull::EnemyRollOverNeckSkull( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyRollOverNeckSkull::~EnemyRollOverNeckSkull( ) {
}

void EnemyRollOverNeckSkull::act( ) {

}