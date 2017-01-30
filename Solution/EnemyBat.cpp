#include "EnemyBat.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;

EnemyBat::EnemyBat( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyBat::~EnemyBat( ) {
}

void EnemyBat::act( ) {

}
