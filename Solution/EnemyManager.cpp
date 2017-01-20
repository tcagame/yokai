#include "EnemyManager.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "Camera.h"
#include "Drawer.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "EnemyStock.h"

EnemyManager::EnemyManager( ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
	_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, 1200, 204 ) ) );
	//_enemies.push_back( EnemyPtr( new EnemyRedbird( _enemy_stock, 250, 300 ) ) );
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
	EnemyPtr stock = _enemy_stock->getPopUp( );
	if ( stock ) {
		_enemies.push_back( stock );
	}
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		if ( isOutSideScreenEnemy( enemy, camera ) ) {
			ite = _enemies.erase( ite );
			continue;
		}
		enemy->update( field );

		if ( enemy->isOverlapped( tarosuke ) ) {
			tarosuke->damage( );
		}

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