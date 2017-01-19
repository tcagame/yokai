#include "EnemyStock.h"


EnemyStock::EnemyStock( ) {
}


EnemyStock::~EnemyStock( ) {
}

void EnemyStock::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}


EnemyPtr EnemyStock::getPopUp( ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	if ( ite == _enemies.end( ) ) {
		return EnemyPtr( );
	}
	EnemyPtr stock = (*ite);
	_enemies.pop_front( );
	return stock;
}
