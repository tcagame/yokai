#include "EnemyManager.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "Camera.h"
<<<<<<< HEAD
#include "Drawer.h"
=======
#include "Tarosuke.h"
#include "Momotaro.h"
>>>>>>> 0809e6a0e6b09b00834ab474b8fdbd6a47752528

EnemyManager::EnemyManager( ) {
	_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( 1200, 204 ) ) );
	_enemies.push_back( EnemyPtr( new EnemyRedbird( 300, 300 ) ) );
	_enemies.push_back( EnemyPtr( new EnemyRedbirdAttack( 400, 130 ) ) );
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
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
#if _DEBUG
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "Enemy Size : %d", _enemies.size( ) );
#endif
}

bool EnemyManager::isOutSideScreenEnemy( EnemyPtr enemy, CameraConstPtr camera ) {
	bool result = false;
	int screen_left_side = camera->getX( );
	int screen_right_side = screen_left_side + SCREEN_WIDTH;
	int enemy_x = enemy->getX( );
	int enemy_y = enemy->getY( );
	int enemy_size = enemy->getSize( );
	if ( enemy_x + enemy_size / 2 < screen_left_side ||
		 enemy_x - enemy_size / 2 > screen_right_side ) {
		result = true;
	}
	if ( enemy_y - enemy_size < 0 ||
		 enemy_y > SCREEN_HEIGHT ) {
		result = true;
	}

	return result;
}

void EnemyManager::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}