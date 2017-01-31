#include "EnemyShishimai.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 3;

EnemyShishimai::EnemyShishimai( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyShishimai::~EnemyShishimai( ) {
}

void EnemyShishimai::act( ) {
}