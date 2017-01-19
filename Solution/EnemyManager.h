#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Field );
PTR( Camera );

class EnemyManager {
public:
	EnemyManager( );
	virtual ~EnemyManager( );
	void update( FieldPtr field, CameraConstPtr camera );
	void draw( CameraPtr camera );
	bool isOutSideScreenEnemy( EnemyPtr enemy, CameraConstPtr camera );
private:
	std::list< EnemyPtr > _enemies;
};

