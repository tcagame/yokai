#include "EnemyManager.h"
#include "Field.h"
#include "Camera.h"
#include "Drawer.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "EnemyStock.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "EnemyMoth.h"

static const int REDBIRD_POP_Y = 250;
static const int PURPLE_POP_Y = 400;
static const int MOTH_POP_Y = 230;

EnemyManager::EnemyManager( ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
	EnemyPtr stock = _enemy_stock->getPopUp( );
	if ( stock ) {
		_enemies.push_back( stock );
	}

	createByField( field->getEnemyData( ), camera );

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
	int dead_left_side = camera->getX( );
	int dead_right_side = dead_left_side + BG_SIZE * BG_NUM;
	int enemy_x = enemy->getX( );
	int enemy_y = enemy->getY( );
	int enemy_size = enemy->getSize( );
	if ( enemy_x + enemy_size / 2 < dead_left_side ||
		 enemy_x - enemy_size / 2 > dead_right_side ) {
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

void EnemyManager::createByField( unsigned int enemy_data, CameraConstPtr camera ) {
	unsigned int data = enemy_data;
	int pop_base_x = BG_SIZE * ( BG_NUM - 1 ) + camera->getX( );

	if ( data & REDBIRD ) {
		_enemies.push_back( EnemyPtr( new EnemyRedbird( _enemy_stock, pop_base_x - BG_SIZE * 2, REDBIRD_POP_Y ) ) );
	}

	if ( data & PURPLE ) {
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x	  , PURPLE_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x + 100, PURPLE_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x + 200, PURPLE_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x + 300, PURPLE_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x + 400, PURPLE_POP_Y ) ) );
	}
	if ( data & MOTH ) {
		_enemies.push_back( EnemyPtr( new EnemyMoth( _enemy_stock, pop_base_x, MOTH_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyMoth( _enemy_stock, pop_base_x + 200, MOTH_POP_Y + 30 ) ) );
	}
}