#include "EnemyOneEyesSnake.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 1;


EnemyOneEyesSnake::EnemyOneEyesSnake( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyOneEyesSnake::~EnemyOneEyesSnake( ) {
}

void EnemyOneEyesSnake::act( ) {

}
