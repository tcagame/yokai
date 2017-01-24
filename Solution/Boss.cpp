#include "Boss.h"

Boss::Boss( EnemyStockPtr enemy_stock, int x, int y, int hp, int pow ) :
Enemy( enemy_stock, x, y, 256, 0, false, hp, pow ) {
}


Boss::~Boss( ) {
}
