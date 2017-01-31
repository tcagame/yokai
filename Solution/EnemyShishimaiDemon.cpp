#include "EnemyShishimaiDemon.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 2;

EnemyShishimaiDemon::EnemyShishimaiDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}


EnemyShishimaiDemon::~EnemyShishimaiDemon( ) {
}

void EnemyShishimaiDemon::act( ) {

}