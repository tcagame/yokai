#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Field );
PTR( Camera );
PTR( Tarosuke );
PTR( Momotaro );

class EnemyManager {
public:
	EnemyManager( );
	virtual ~EnemyManager( );
	void update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro );
	void draw( CameraPtr camera );
	bool isOutSideScreenEnemy( EnemyPtr enemy, CameraConstPtr camera );
private:
	std::list< EnemyPtr > _enemies;
};

