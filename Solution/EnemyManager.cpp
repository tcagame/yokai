#include "EnemyManager.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "Camera.h"

EnemyManager::EnemyManager( ) {
	_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( 1200, 204 ) ) );
	_enemies.push_back( EnemyPtr( new EnemyRedbird( 300, 300 ) ) );
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		if ( isOutSideScreenEnemy( (*ite), camera ) ) {
			ite = _enemies.erase( ite );
			continue;
		}
		(*ite)->update( field );
		ite++;
	}
}

void EnemyManager::draw( CameraPtr camera ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		(*ite)->draw( camera );
		ite++;
	}
}

bool EnemyManager::isOutSideScreenEnemy( EnemyPtr enemy, CameraConstPtr camera ) {
	bool result = false;
	int screen_left_side = camera->getX( );
	int screen_right_side = screen_left_side + SCREEN_WIDTH;
	int enemy_x = enemy->getX( );
	int enemy_size = enemy->getSize( );
	if ( enemy_x + enemy_size / 2 < screen_left_side ||
		 enemy_x - enemy_size / 2 > screen_right_side ) {
		result = true;
	}

	return result;
}