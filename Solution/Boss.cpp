#include "Boss.h"


Boss::Boss( EnemyStockPtr enemy_stock ) :
Enemy( enemy_stock, 256, 400, 256, 0, true, 30, 10 ) {
}


Boss::~Boss( ) {
}
