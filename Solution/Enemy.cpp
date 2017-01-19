#include "Enemy.h"



Enemy::Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_graph, int chip_size, int foot, bool mass ) :
Character( x, y, chip_graph, chip_size, foot, mass ),
_enemy_stock( enemy_stock ) {
}

Enemy::~Enemy( ) {
}

EnemyStockPtr Enemy::getEnemyStock( ) {
	return _enemy_stock;
}