#include "EnemyManager.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "Camera.h"
#include "Drawer.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "EnemyStock.h"
#include "Field.h"

EnemyManager::EnemyManager( ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
	EnemyPtr stock = _enemy_stock->getPopUp( );
	enemyCreate( field->getEnemyData( ), ( TarosukeConstPtr )tarosuke, camera );
	if ( stock ) {
		_enemies.push_back( stock );
	}
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

void EnemyManager::enemyCreate( unsigned int enemy_data, TarosukeConstPtr tarosuke, CameraConstPtr camera ) {
	unsigned int data = enemy_data;
	int tarosuke_x = tarosuke->getX( );
	if ( data & REDBIRD ) {
		_enemies.push_back( EnemyPtr( new EnemyRedbird( _enemy_stock, camera->getX( ) + SCREEN_WIDTH * 7 / 8, 250 ) ) );
	}

	if ( data & PURPLE ) {
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, tarosuke_x - 100, 400 ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, tarosuke_x + 100, 400 ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, tarosuke_x + 200, 400 ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, tarosuke_x + 300, 400 ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, tarosuke_x + 400, 400 ) ) );
	}
}