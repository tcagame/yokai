#include "EnemyManager.h"
#include "Field.h"
#include "Game.h"
#include "Camera.h"
#include "Sound.h"
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
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"
#include "EnemyDeceasedFourth.h"
#include "EnemyFlog.h"
#include "EnemyStoneRote.h"
#include "EnemyStoneFly.h"
#include "EnemyGhoul.h"
#include "EnemyOnyudo.h"
#include "EnemyWaterGhost.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyWaterMonk.h"
#include "EnemySkeletonSpear.h"
#include "EnemyJizo.h"
#include "Map.h"
#include "Boss.h"

static const int BASE_POP_Y = 400;
static const int POPUP_GROUND = 400;
static const int PURPLE_POP_NUM = 5;
static const int REDBIRD_POP_Y = 250;
static const int PURPLE_POP_Y = 400;
static const int MOTH_POP_Y = 230;
static const int BOMB_COUNT = 16;
static const int BOMB_SIZE = 256;
static const int FLOG_POP_Y = 100;
static const int FLOG_POP_NUM = 3;
static const int STONE_POP_Y = 200;
static const int EXTRUDEDSPIRITS_POP_Y = 200;
static const int WATER_ENEMY_POP_Y = 480;

EnemyManager::EnemyManager( MapConstPtr map ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
	for ( int i = 0; i < BOMB_NUM; i++ ) {
		_bombs[ i ].count = BOMB_COUNT;
	}
	_boss = map->createBoss( _enemy_stock );
	_enemies.push_back( _boss );
	_idx_bomb = 0;
}

EnemyManager::~EnemyManager( ) {
}


void EnemyManager::clear( ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->damage( -1 );
		ite++;
	}
	_enemy_stock =  EnemyStockPtr( new EnemyStock );
}

void EnemyManager::attackBoss( ) {
	_boss->attack( );
}

bool EnemyManager::isBossDead( ) const {
	return _boss->isFinished( );
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

		if ( enemy->isOutSideScreen( camera ) ) {
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
				enemy->steppedOn( );
			} else {
				tarosuke->damage( pow );
			}
		}

		if ( enemy->isOverlapped( momotaro ) ) {
			momotaro->damage( pow );
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

	GamePtr game = Game::getTask( );
	game->addDebugMessage( "Enemy Size : %d", _enemies.size( ) );
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
		_enemies.push_back( EnemyPtr( new EnemyTree( _enemy_stock, pop_base_x, POPUP_GROUND ) ) );
	}
	
	if ( data & DECEASED ) {
		const int INTERVAL = 64;
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedFirst( _enemy_stock, pop_base_x, POPUP_GROUND ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedSecond( _enemy_stock, pop_base_x += INTERVAL, POPUP_GROUND ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedThird( _enemy_stock, pop_base_x += INTERVAL, POPUP_GROUND ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedFourth( _enemy_stock, pop_base_x += INTERVAL, POPUP_GROUND ) ) );
	}
	
	if ( data & FLOG ) {
		for ( int i = 0; i < FLOG_POP_NUM; i++ ) {
			_enemies.push_back( EnemyPtr( new EnemyFlog( _enemy_stock, pop_base_x + i * 100, FLOG_POP_Y ) ) );
		}
	}
	if ( data % STONE_ROTE ) {
		_enemies.push_back( EnemyPtr( new EnemyStoneRote( _enemy_stock, pop_base_x, STONE_POP_Y ) ) );
	}

	if ( data % STONE_FLY ) {
		_enemies.push_back( EnemyPtr( new EnemyStoneFly( _enemy_stock, pop_base_x, STONE_POP_Y ) ) );
	}

	if ( data & GHOUL ) {
		_enemies.push_back( EnemyPtr( new EnemyGhoul( _enemy_stock, pop_base_x, POPUP_GROUND ) ) );
	}
	
	if ( data & EXTRUDEDSPRITS ) {
		_enemies.push_back( EnemyPtr( new EnemyExtrudedSpirits( _enemy_stock, pop_base_x, EXTRUDEDSPIRITS_POP_Y ) ) );
	}

	if ( data & ONYUDO ) {
		_enemies.push_back( EnemyPtr( new EnemyOnyudo( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}

	if ( data & WATER_GHOST ) {
		_enemies.push_back( EnemyPtr( new EnemyWaterGhost( _enemy_stock, pop_base_x, WATER_ENEMY_POP_Y ) ) );
	}

	if ( data & WATER_MONK ) {
		_enemies.push_back( EnemyPtr( new EnemyWaterMonk( _enemy_stock, pop_base_x, WATER_ENEMY_POP_Y ) ) );
	}
	
	if ( data & SKELETON_SPEAR ) {
		_enemies.push_back( EnemyPtr( new EnemySkeletonSpear( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}

	if ( data & JIZO ) {
		_enemies.push_back( EnemyPtr( new EnemyJizo( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}
}

EnemyPtr EnemyManager::getOverlappedEnemy( PsychicPtr pcychic ) {
	std::list< EnemyPtr >::iterator ite = _enemies.begin( );
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