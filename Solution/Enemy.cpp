#include "Enemy.h"
#include "Psychic.h"

PTR( Psychic );

Enemy::Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_graph, int chip_size, int chip_foot, bool mass ) :
Character( x, y, chip_graph, chip_size, chip_foot, mass ),
_enemy_stock( enemy_stock ) {
}

Enemy::~Enemy( ) {
}

bool Enemy::isOverlapped( CharacterPtr target ) {
	Vector vec = getOverlapeedPos( ) - target->getOverlapeedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

EnemyStockPtr Enemy::getEnemyStock( ) {
	return _enemy_stock;
}

void Enemy::damage( ) {
	setDead( true );
}
