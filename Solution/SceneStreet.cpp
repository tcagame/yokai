#include "SceneStreet.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Drawer.h"
#include "PsychicMgr.h"
#include "EnemyManager.h"
#include "Status.h"
#include "Sound.h"
#include "Power.h"
#include "Device.h"
#include "Keyboard.h"
#include "Game.h"
#include "Map0.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Map4.h"
#include "MapTest.h"

static const int CLEAR_COUNT = 120;

SceneStreet::SceneStreet( ) {
	GamePtr game = Game::getTask( );
	
	MapConstPtr map;
	switch ( game->getStage( ) ) {
	case 0:
		map = MapPtr( new Map0 );
		break;
	case 1:
		map = MapPtr( new Map1 );
		break;
	case 2:
		map = MapPtr( new Map2 );
		break;
	case 3:
		map = MapPtr( new Map3 );
		break;
	case 4:
		map = MapPtr( new Map4 );
		break;
	case 5:
		map = MapPtr( new MapTest );
		break;
	}

	_field = FieldPtr( new Field( map ) );
	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_power = PowerPtr( new Power );
	_momotaro = MomotaroPtr( new Momotaro( _psychic_mgr, _power ) );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr, _power, _momotaro ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager( map ) );
	_status = StatusPtr( new Status( _power ) );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER_1		 , "Character/Character1.png" );
	drawer->loadGraph( GRAPH_CHARACTER_2		 , "Character/Character2.png" );
	drawer->loadGraph( GRAPH_PSYCHIC			 , "Character/psychic.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG			 , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_CLOUD_SMALL		 , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE		 , "street/mapchipguide.png" );
	drawer->loadGraph( GRAPH_BOMB                , "street/bomb.png" );
	drawer->loadGraph( GRAPH_BOSS                , "street/enemy/boss_reddemon.png" );
	drawer->loadGraph( GRAPH_ENEMY_COMMON		 , "street/enemy/enemy_common.png" );
	drawer->loadGraph( GRAPH_ENEMY_SMALL		 , "street/enemy/enemy_small.png" );
	drawer->loadGraph( GRAPH_ENEMY_TREE			 , "street/enemy/enemy_tree.png" );
	drawer->loadGraph( GRAPH_STATUS_PLATE		 , "street/status/status_plate.png" );
	drawer->loadGraph( GRAPH_STATUS_POWER        , "street/status/status_power.png" );
	drawer->loadGraph( GRAPH_STATUS_MAP		     , "street/map0/status/status_map_0.png" );

	_phase = PHASE_NORMAL;
	_phase_count = 0;

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_10.wav" );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_phase_count++;

	switch ( _phase ) {
	case PHASE_NORMAL:
		if ( _camera->isLocked( ) ) {
			_phase = PHASE_BOSS;
			_phase_count = 0;
		}
		break;
	case PHASE_BOSS:
		_enemy_mgr->attackBoss( );
		if ( _enemy_mgr->isBossDead( ) ) {
			_enemy_mgr->clear( );
			_phase = PHASE_CLEAR;
			_phase_count = 0;
		}
		break;
	case PHASE_CLEAR:
		if ( _phase_count > CLEAR_COUNT ) {
			GamePtr game = Game::getTask( );
			game->setFade( Game::FADE_OUT );
		}
		break;
	case PHASE_FADEOUT:
		{
			GamePtr game = Game::getTask( );
			if ( game->getFade( ) == Game::FADE_COVER ) {
				return NEXT_STAGE;
			}
		}
		break;
	}

	_tarosuke->update( _field );
	_tarosuke->adjust( _camera );
	_momotaro->update( _field );
	_momotaro->adjust( _camera );
	_camera->update( _tarosuke );
	_enemy_mgr->update( _field, _camera, _tarosuke, _momotaro );
	_psychic_mgr->update( _camera, _tarosuke, _enemy_mgr );
	_status->update( );
	_field->update( _camera );

	_field->draw( _camera );
	_enemy_mgr->draw( _camera );
	_tarosuke->draw( _camera );
	_momotaro->draw( _camera );
	_psychic_mgr->draw( _camera );
	_field->drawCover( );
	_status->draw( );

	debugWarp( );

	return NEXT_CONTINUE;
}

void SceneStreet::debugWarp( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	int warp = 0;
	if ( keyboard->isPushKey( "D" ) ) {
		warp = 1;
	}
	if ( keyboard->isPushKey( "A" ) ) {
		warp = -1;
	}
	if ( warp == 0 ) {
		return;
	}

	_tarosuke->warp( warp );
}

