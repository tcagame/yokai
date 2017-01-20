#include "Enemy.h"



Enemy::Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_graph,  bool mass ) :
Character( x, y, chip_graph, mass ),
_enemy_stock( enemy_stock ) {
}

Enemy::~Enemy( ) {
}

EnemyStockPtr Enemy::getEnemyStock( ) {
	return _enemy_stock;
}

bool Enemy::isOverlapped( CharacterPtr target ) {
	Vector vec = getOverlapeedPos( ) - target->getOverlapeedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}
