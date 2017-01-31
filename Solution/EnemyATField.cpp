#include "EnemyATField.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 99;
static const int POW = 3;

EnemyATField::EnemyATField( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ) {
}

EnemyATField::~EnemyATField( ) {
}

void EnemyATField::act( ) {
}

void EnemyATField::damage( int pow ) {
}