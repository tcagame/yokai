#include "BossHag.h"

static const int CHIP_SIZE = 256;
static const int OFFSET_X = 60;
static const int OFFSET_Y = 512 - 140;
static const int HP  = 20;
static const int POW = 10;

BossHag::BossHag( EnemyStockPtr stock, int x ) :
Boss( x + OFFSET_X, OFFSET_Y, CHIP_SIZE, HP, POW ) {

}


BossHag::~BossHag( ) {

}

void BossHag::act( ) {

}

void BossHag::attack( ) {

}