#include "EnemyWindMonster.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 4;
static const int POW = 1;

EnemyWindMonster::EnemyWindMonster( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}


EnemyWindMonster::~EnemyWindMonster( ) {
}
