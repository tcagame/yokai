#include "Enemy.h"
#include "Psychic.h"

PTR( Psychic );

Enemy::Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_size, int chip_foot, bool mass, int hp, int pow ) :
Character( x, y, chip_size, chip_foot, mass ),
_enemy_stock( enemy_stock ),
_hp( hp ),
_pow( pow ) {
}

Enemy::~Enemy( ) {
}

bool Enemy::isOverlapped( CharacterPtr target ) const {
	Vector vec = getOverlappedPos( ) - target->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

EnemyStockPtr Enemy::getEnemyStock( ) {
	return _enemy_stock;
}

void Enemy::damage( int pow ) {
	_hp -= pow;
}

bool Enemy::isFinished( ) const {
	return _hp <= 0;
}

int Enemy::getPow( ) const {
	return _pow;
}

