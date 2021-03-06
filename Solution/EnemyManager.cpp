#include "EnemyManager.h"
#include "Field.h"
#include "Game.h"
#include "Camera.h"
#include "Sound.h"
#include "Drawer.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "Psychic.h"
#include "Boss.h"
#include "Map.h"
#include "EnemyStock.h"

static const int BASE_POP_Y = 200;
static const int POPUP_GROUND = 400;
static const int DECEASED_POP_Y = 450;
static const int DECEASED_PURPLE_POP_NUM = 5;
static const int DECEASED_GREEN_POP_NUM = 5;
static const int REDBIRD_POP_Y = 250;
static const int DECEASED_PURPLE_POP_Y = 100;
static const int DECEASED_GREEN_POP_Y = 100;
static const int MOTH_POP_Y = 230;
static const int BOMB_COUNT = 16;
static const int BOMB_SIZE = 256;
static const int FLOG_SMALL_POP_Y = 100;
static const int FLOG_SMALL_POP_NUM = 3;
static const int STONE_POP_Y = 200;
static const int EXTRUDEDSPIRITS_POP_Y = 200;
static const int WATER_ENEMY_POP_Y = 480;

EnemyManager::EnemyManager( MapConstPtr map, EnemyStockPtr stock ) :
_stock( stock ) {
	for ( int i = 0; i < BOMB_NUM; i++ ) {
		_bombs[ i ].count = BOMB_COUNT;
	}
	_boss = map->generateBoss( _stock );
	_enemies.push_back( _boss );
	_idx_bomb = 0;
}

EnemyManager::~EnemyManager( ) {
}

void EnemyManager::clear( ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		BossPtr boss = std::dynamic_pointer_cast< Boss >( enemy );
		if ( !boss ) {
			enemy->damage( -1 );
		}
		ite++;
	}
	_stock->clear( );
}

void EnemyManager::attackBoss( ) {
	_boss->attack( );
}

bool EnemyManager::isBossDead( ) const {
	return _boss->isFinished( );
}

void EnemyManager::update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro ) {
	EnemyPtr stock = _stock->getPopUp( );
	if ( stock ) {
		_enemies.push_back( stock );
	}

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
		enemy->setCameraX( camera->getX( ) );
		enemy->setTarget( tarosuke->getX( ), tarosuke->getY( ) );
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
	GamePtr game = Game::getTask( );

	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->draw( camera );
		if ( game->isDebug( ) ) {
			DrawerPtr drawer = Drawer::getTask( );
			Vector pos = enemy->getOverlappedPos( ) - Vector( camera->getX( ), camera->getY( ) ); 
			drawer->setCircle( Drawer::Circle( pos, enemy->getOverlappedRadius( ) ) ); 
		}
		ite++;
	}

	drawBomb( camera );

	game->addDebugMessage( "Enemy Size : %d", _enemies.size( ) );
}

void EnemyManager::addBomb( const Vector& pos ) {
	_bombs[ _idx_bomb ].pos = pos;
	_bombs[ _idx_bomb ].count = 0;
	_idx_bomb = ( _idx_bomb + 1 ) % BOMB_NUM;
	SoundPtr sound = Sound::getTask( );
	sound->playSE( "yokai_voice_08.wav" );
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