#include "EnemyManager.h"
#include "Field.h"
#include "Camera.h"
#include "Drawer.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "Psychic.h"
#include "EnemyStock.h"
#include "EnemyPurpleYokai.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "EnemyMoth.h"
#include "EnemyTree.h"
#include "Sound.h"

static const int PURPLE_POP_NUM = 5;
static const int REDBIRD_POP_Y = 250;
static const int PURPLE_POP_Y = 400;
static const int MOTH_POP_Y = 230;
static const int TREE_POP_Y = 400;
static const int BOMB_COUNT = 16;
static const int BOMB_SIZE = 256;

EnemyManager::EnemyManager( ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
	for ( int i = 0; i < BOMB_NUM; i++ ) {
		_bombs[ i ].count = BOMB_COUNT;
	}
}

EnemyManager::~EnemyManager( ) {
}


void EnemyManager::clear( ) {
	_enemies.clear( );
	_enemy_stock =  EnemyStockPtr( new EnemyStock );
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
	EnemyPtr stock = _enemy_stock->getPopUp( );
	if ( stock ) {
		_enemies.push_back( stock );
	}

	createByField( field->getEnemyData( ), camera );
	updateBomb( );

	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		if ( isOutSideScreenEnemy( enemy, camera ) ) {
			ite = _enemies.erase( ite );
			continue;
		}
		if ( enemy->isFinished( ) ) {
			addBomb( enemy->getOverlappedPos( ) );
			ite = _enemies.erase( ite );
			continue;

		}
		enemy->update( field );
		int pow = enemy->getPow( );

		if ( enemy->isOverlapped( tarosuke ) ) {
			if ( tarosuke->isOnHead( enemy ) ) {
				tarosuke->bound( );
			} else {
				tarosuke->damage( pow ); // ¦Enemy‚©‚çUŒ‚—Í‚ğæ“¾‚µ‚Ä“n‚·
			}
		}

		if ( enemy->isOverlapped( momotaro ) ) {
			momotaro->damage( pow ); // ¦Enemy‚©‚çUŒ‚—Í‚ğæ“¾‚µ‚Ä“n‚·
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

	drawBomb( camera );
#if _DEBUG
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "Enemy Size : %d", _enemies.size( ) );
#endif
}

void EnemyManager::addBomb( const Vector& pos ) {
	_bombs[ _idx_bomb ].pos = pos;
	_bombs[ _idx_bomb ].count = 0;
	_idx_bomb = ( _idx_bomb + 1 ) % BOMB_NUM;
	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_se_26.wav" );
}

void EnemyManager::updateBomb( ) {
	for ( int i = 0; i < BOMB_NUM; i++ ) {
		 _bombs[ i ].count++;
	}
}

void EnemyManager::drawBomb( CameraConstPtr camera ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < BOMB_NUM; i++ ) {
		int idx = ( _idx_bomb + i ) % BOMB_NUM;
		if ( _bombs[ idx ].count >= BOMB_COUNT ) {
			continue;
		}
		int pattern = _bombs[ idx ].count / ( BOMB_COUNT / 4 );
		int tx = pattern % 2 * BOMB_SIZE;
		int ty = pattern / 2 * BOMB_SIZE;

		int sx = ( int )_bombs[ idx ].pos.x - camera->getX( ) - BOMB_SIZE / 2;
		int sy = ( int )_bombs[ idx ].pos.y - camera->getY( ) - BOMB_SIZE / 2;

		Drawer::Transform trans( sx, sy, tx, ty, BOMB_SIZE, BOMB_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_BOMB, Drawer::BLEND_NONE, 1.0 );
		drawer->setSprite( sprite );
	}
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
		for ( int i = 0; i < PURPLE_POP_NUM; i++ ) {
			_enemies.push_back( EnemyPtr( new EnemyPurpleYokai( _enemy_stock, pop_base_x + ( i * 100 ), PURPLE_POP_Y ) ) );
		}
	}
	if ( data & MOTH ) {
		_enemies.push_back( EnemyPtr( new EnemyMoth( _enemy_stock, pop_base_x, MOTH_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyMoth( _enemy_stock, pop_base_x + 200, MOTH_POP_Y + 30 ) ) );
	}

	if ( data & TREE ) {
		_enemies.push_back( EnemyPtr( new EnemyTree( _enemy_stock, pop_base_x, TREE_POP_Y ) ) );
	}
}

EnemyPtr EnemyManager::getOverlappedEnemy( PsychicPtr pcychic ) {
	std::list< EnemyPtr>::iterator ite = _enemies.begin( );
	EnemyPtr target;

	while ( ite != _enemies.end( ) ) {
		if ( (*ite)->isOverlapped( pcychic ) ) {
			target = (*ite);
			break;
		}
		ite++;
	}
	return target;
}