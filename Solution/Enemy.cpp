#include "Enemy.h"

static const int ENEMY_SIZE = 204;
static const int ENEMY_FOOT = 0;

Enemy::Enemy( int x, int y, int chip_graph, bool mass ) :
Character( x, y, chip_graph, ENEMY_SIZE, ENEMY_FOOT, mass ) {
}

Enemy::~Enemy( ) {
}
