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
#include "EnemyDeceasedPurple.h"
#include "EnemyMiasmaWhite.h"
#include "EnemyRedbird.h"
#include "EnemyRedbirdAttack.h"
#include "EnemyMoth.h"
#include "EnemyTree.h"
#include "EnemyDeceasedFirst.h"
#include "EnemyDeceasedSecond.h"
#include "EnemyDeceasedThird.h"
#include "EnemyDeceasedFourth.h"
#include "EnemyFlogSmall.h"
#include "EnemyStoneRote.h"
#include "EnemyStoneFly.h"
#include "EnemyGhoul.h"
#include "EnemyOnyudo.h"
#include "EnemyWaterGhost.h"
#include "EnemyExtrudedSpirits.h"
#include "EnemyWaterMonk.h"
#include "EnemySkeletonSpear.h"
#include "EnemyMiasmaGray.h"
#include "EnemyFlog.h"
#include "EnemyJizo.h"
#include "EnemyEyeSpector.h"
#include "EnemyGrowFace.h"
#include "EnemyCrocodileSnake.h"
#include "EnemyBowDemon.h"
#include "EnemyHugDemon.h"
#include "EnemyBloodPondDemon.h"
#include "EnemyBlueMonk.h"
#include "EnemyOneEyesSnake.h"
#include "EnemyDeceasedGreen.h"
#include "EnemyTreeMonster.h"
#include "EnemyHellFire.h"
#include "EnemyRockMassSoul.h"
#include "EnemyRockMassShell.h"
#include "EnemyRollOverNeckSkull.h"
#include "EnemyRollOverNeckWoman.h"
#include "EnemyRayMonster.h"
#include "EnemyWindMonster.h"
#include "EnemyBat.h"
#include "EnemyHandMonster.h"
//#include "EnemyNoFace.h"
#include "EnemyNoNeckGhost.h"

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

EnemyManager::EnemyManager( MapConstPtr map ) {
	_enemy_stock = EnemyStockPtr( new EnemyStock );
	for ( int i = 0; i < BOMB_NUM; i++ ) {
		_bombs[ i ].count = BOMB_COUNT;
	}
	_boss = map->createBoss( _enemy_stock );
	_enemies.push_back( _boss );
	_idx_bomb = 0;

	for ( int i = 0; i < BG_NUM; i++ ) {
		createByField( map->getEnemyData( i ), CameraPtr( ) );
	}
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

	field->apeearEnemy( _enemy_stock );
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

void EnemyManager::createByField( unsigned long long enemy_data, CameraConstPtr camera ) {
	unsigned long long data = enemy_data;
	int camera_pos = 0;
	if ( camera ) {
		camera_pos = camera->getX( );
	}
	int pop_base_x = BG_SIZE * ( BG_NUM - 1 ) + camera_pos;

	if ( data & REDBIRD ) {
		_enemies.push_back( EnemyPtr( new EnemyRedbird( _enemy_stock, pop_base_x - BG_SIZE * 2, REDBIRD_POP_Y ) ) );
	}

	if ( data & DECEASED_PURPLE ) {
		for ( int i = 0; i < DECEASED_PURPLE_POP_NUM; i++ ) {
			_enemies.push_back( EnemyPtr( new EnemyDeceasedPurple( pop_base_x + ( i * 100 ), DECEASED_PURPLE_POP_Y ) ) );
		}
	}
	if ( data & MOTH ) {
		_enemies.push_back( EnemyPtr( new EnemyMoth( pop_base_x, MOTH_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyMoth( pop_base_x + 200, MOTH_POP_Y + 30 ) ) );
	}

	if ( data & TREE ) {
		_enemies.push_back( EnemyPtr( new EnemyTree( _enemy_stock, pop_base_x, POPUP_GROUND ) ) );
	}
	if ( data & TREE_MONSTER ) {
		_enemies.push_back( EnemyPtr( new EnemyTreeMonster( _enemy_stock, pop_base_x, POPUP_GROUND ) ) );
	}
	
	if ( data & DECEASED ) {
		pop_base_x += 384;
		const int INTERVAL = 64;
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedFirst ( pop_base_x + INTERVAL * 0, DECEASED_POP_Y ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedSecond( pop_base_x + INTERVAL * 1, DECEASED_POP_Y ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedThird ( pop_base_x + INTERVAL * 2, DECEASED_POP_Y ) ) );
		_enemies.push_back( EnemyPtr ( new EnemyDeceasedFourth( pop_base_x + INTERVAL * 3, DECEASED_POP_Y ) ) );
	}
	
	if ( data & FLOG_SMALL ) {
		for ( int i = 0; i < FLOG_SMALL_POP_NUM; i++ ) {
			_enemies.push_back( EnemyPtr( new EnemyFlogSmall( pop_base_x + i * 100, FLOG_SMALL_POP_Y ) ) );
		}
	}
	if ( data & FLOG ) {
		_enemies.push_back( EnemyPtr( new EnemyFlog( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & STONE_ROTE ) {
		_enemies.push_back( EnemyPtr( new EnemyStoneRote( pop_base_x, STONE_POP_Y ) ) );
	}

	if ( data & STONE_FLY ) {
		_enemies.push_back( EnemyPtr( new EnemyStoneFly( pop_base_x, STONE_POP_Y ) ) );
	}

	if ( data & GHOUL ) {
		_enemies.push_back( EnemyPtr( new EnemyGhoul( pop_base_x, POPUP_GROUND ) ) );
	}
	
	if ( data & EXTRUDEDSPRITS ) {
		_enemies.push_back( EnemyPtr( new EnemyExtrudedSpirits( pop_base_x, EXTRUDEDSPIRITS_POP_Y ) ) );
	}

	if ( data & ONYUDO ) {
		_enemies.push_back( EnemyPtr( new EnemyOnyudo( pop_base_x, BASE_POP_Y ) ) );
	}

	if ( data & WATER_GHOST ) {
		_enemies.push_back( EnemyPtr( new EnemyWaterGhost( pop_base_x, WATER_ENEMY_POP_Y ) ) );
	}

	if ( data & WATER_MONK ) {
		_enemies.push_back( EnemyPtr( new EnemyWaterMonk( pop_base_x, WATER_ENEMY_POP_Y ) ) );
	}
	
	if ( data & SKELETON_SPEAR ) {
		_enemies.push_back( EnemyPtr( new EnemySkeletonSpear( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & MIASMA_GRAY ) {
		_enemies.push_back( EnemyPtr( new EnemyMiasmaGray( pop_base_x, MOTH_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyMiasmaGray( pop_base_x + 200, MOTH_POP_Y + 30 ) ) );
	}
	if ( data & MIASMA_WHITE ) {
		_enemies.push_back( EnemyPtr( new EnemyMiasmaWhite( pop_base_x, MOTH_POP_Y ) ) );
		_enemies.push_back( EnemyPtr( new EnemyMiasmaWhite( pop_base_x + 200, MOTH_POP_Y + 30 ) ) );
	}
	if ( data & JIZO ) {
		_enemies.push_back( EnemyPtr( new EnemyJizo( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & EYE ) {
		_enemies.push_back( EnemyPtr( new EnemyEyeSpector( pop_base_x, BASE_POP_Y - 100 ) ) );
	}
	if ( data & BOW_DEMON ) {
		_enemies.push_back( EnemyPtr( new EnemyBowDemon( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & CROCODILE_SNAKE ) {
		_enemies.push_back( EnemyPtr( new EnemyCrocodileSnake( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & HUG_DEMON ) {
		_enemies.push_back( EnemyPtr( new EnemyHugDemon( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & BLOOD_POND_DEMON ) {
		_enemies.push_back( EnemyPtr( new EnemyBloodPondDemon( _enemy_stock, pop_base_x, BASE_POP_Y + 200 ) ) );
	}
	if ( data & BLUE_MONK ) {
		_enemies.push_back( EnemyPtr( new EnemyBlueMonk( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & ONE_EYES_SNAKE ) {
		_enemies.push_back( EnemyPtr( new EnemyOneEyesSnake( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & DECEASED_GREEN ) {
		for ( int i = 0; i < DECEASED_GREEN_POP_NUM; i++ ) {
			_enemies.push_back( EnemyPtr( new EnemyDeceasedGreen( pop_base_x + ( i * 100 ), DECEASED_GREEN_POP_Y ) ) );
		}
	}
	if ( data & HELL_FIRE ) {
		_enemies.push_back( EnemyPtr( new EnemyHellFire( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & ROCK_MASS ) {
		_enemies.push_back( EnemyPtr( new EnemyRockMassSoul( pop_base_x - 25, BASE_POP_Y + 50 ) ) );
		_enemies.push_back( EnemyPtr( new EnemyRockMassShell( _enemy_stock, pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & WIND_MONSTER ) {
		_enemies.push_back( EnemyPtr( new EnemyWindMonster( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & RAY_MONSTER ) {
		_enemies.push_back( EnemyPtr( new EnemyRayMonster( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & NECK_SKULL ) {
		_enemies.push_back( EnemyPtr( new EnemyRollOverNeckSkull( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & NECK_WOMAN ) {
		_enemies.push_back( EnemyPtr( new EnemyRollOverNeckWoman( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & BAT ) {
		_enemies.push_back( EnemyPtr( new EnemyBat( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & HAND ) {
		_enemies.push_back( EnemyPtr( new EnemyHandMonster( pop_base_x, BASE_POP_Y ) ) );
	}
	if ( data & NO_FACE ) {
	//	_enemies.push_back( EnemyPtr( new EnemyNoFace( pop_base_x, BASE_POP_Y ) ) );
	}

	if ( data & NO_NECK_GHOST ) {
		_enemies.push_back( EnemyPtr( new EnemyNoNeckGhost( _enemy_stock, pop_base_x - BG_SIZE * 2, REDBIRD_POP_Y ) ) );
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