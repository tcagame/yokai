#pragma once
#include <list>
#include "smart_ptr.h"

PTR( Enemy );

class EnemyStock {
public:
	EnemyStock( );
	virtual ~EnemyStock( );
public:
	void addEnemy( EnemyPtr enemy );
	EnemyPtr getPopUp( );
private:
	std::list< EnemyPtr > _enemies;
};

