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
static const int DEAD_COUNT = 120;

SceneStreet::SceneStreet() {
	DrawerPtr drawer = Drawer::getTask();
	drawer->loadGraph(GRAPH_CHARACTER_1   , "Character/Character1.png");
	drawer->loadGraph(GRAPH_CHARACTER_2   , "Character/Character2.png");
	drawer->loadGraph(GRAPH_PSYCHIC       , "Character/psychic.png");
	drawer->loadGraph(GRAPH_CLOUD_BIG     , "street/cloud/Yokai_OBJ_cloud1.png");
	drawer->loadGraph(GRAPH_CLOUD_SMALL   , "street/cloud/Yokai_OBJ_cloud2.png");
	drawer->loadGraph(GRAPH_MAPCHIPGUIDE  , "street/other/mapchipguide.png");
	drawer->loadGraph(GRAPH_IMPACT        , "street/other/impact.png");
	drawer->loadGraph(GRAPH_BOMB          , "street/other/bomb.png");
	drawer->loadGraph(GRAPH_ENEMY_NOMAL   , "street/enemy/enemy_nomal.png");
	drawer->loadGraph(GRAPH_ENEMY_SMALL   , "street/enemy/enemy_small.png");
	drawer->loadGraph(GRAPH_ENEMY_BIG_1   , "street/enemy/enemy_big1.png");
	drawer->loadGraph(GRAPH_ENEMY_BIG_2   , "street/enemy/enemy_big2.png");
	drawer->loadGraph(GRAPH_ENEMY_TREE    , "street/enemy/enemy_tree.png");
	drawer->loadGraph(GRAPH_ENEMY_FIREBALL, "street/enemy/enemy_fireball.png");
	drawer->loadGraph(GRAPH_ENEMY_FLOG    , "street/enemy/enemy_frog_green.png");
	drawer->loadGraph(GRAPH_STATUS_PLATE  , "street/status/status_plate.png");
	drawer->loadGraph(GRAPH_STATUS_POWER  , "street/status/status_power.png");
	drawer->loadGraph(GRAPH_STATUS_MARKER , "street/status/status_marker.png");

	GamePtr game = Game::getTask( );
	
	MapConstPtr map;
	switch ( game->getStage( ) ) {
	case 0:
		map = MapPtr(new Map0);
		drawer->loadGraph(GRAPH_STATUS_MAP   , "street/status/status_map_0.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE , "street/status/status_title_0.png");
		drawer->loadGraph(GRAPH_BOSS         , "street/enemy/boss_reddemon.png");
		break;
	case 1:
		map = MapPtr(new Map1);
		drawer->loadGraph(GRAPH_STATUS_MAP   , "street/status/status_map_1.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE , "street/status/status_title_1.png");
		drawer->loadGraph(GRAPH_BOSS         , "street/enemy/boss_bluedemon.png");
		break;
	case 2:
		map = MapPtr(new Map2);
		drawer->loadGraph(GRAPH_STATUS_MAP, "street/status/status_map_2.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_2.png");
		drawer->loadGraph(GRAPH_BOSS         , "street/enemy/boss_sanzu.png");
		break;
	case 3:
		map = MapPtr(new Map3);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_3.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_3.png");
		drawer->loadGraph(GRAPH_BOSS        , "street/enemy/boss_sanzu.png");
		break;
	case 4:
		map = MapPtr(new Map4);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_4.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_4.png");
		break;
	case 5:
		map = MapPtr(new MapTest);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_0.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_test.png");
		drawer->loadGraph(GRAPH_BOSS         , "street/enemy/boss_bluedemon.png");
		break;
	}

	_field = FieldPtr( new Field( map ) );
	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_power = PowerPtr( new Power );
	_momotaro = MomotaroPtr( new Momotaro( _psychic_mgr, _power ) );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr, _power, _momotaro ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager( map ) );
	_status = StatusPtr( new Status( _power, _field, _tarosuke ) );

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
			SoundPtr sound = Sound::getTask( );
			sound->playBGM( "yokai_music_04.wav" );
		}
		if ( _power->get( ) == 0 ) {
			_phase = PHASE_DEAD;
			_phase_count = 0;
		}
		break;
	case PHASE_BOSS:
		if ( !_tarosuke->isCalling( ) ) {
			_enemy_mgr->attackBoss( );
		}
		if ( _power->get( ) == 0 ) {
			_phase = PHASE_DEAD;
			_phase_count = 0;
		}
		if ( _enemy_mgr->isBossDead( ) ) {
			_enemy_mgr->clear( );
			_phase = PHASE_CLEAR;
			_phase_count = 0;
			SoundPtr sound = Sound::getTask( );
			sound->playBGM( "yokai_se_32.wav" );
		}
		break;
	case PHASE_DEAD:
		if ( _phase_count > DEAD_COUNT ) {
			GamePtr game = Game::getTask( );
			game->setFade( Game::FADE_OUT );
			_phase = PHASE_FADEOUT;
		}
		break;
	case PHASE_CLEAR:
		if ( _phase_count > CLEAR_COUNT ) {
			GamePtr game = Game::getTask( );
			game->setFade( Game::FADE_OUT );
			_phase = PHASE_FADEOUT;
		}
		break;
	case PHASE_FADEOUT:
		{
			GamePtr game = Game::getTask( );
			if ( game->getFade( ) == Game::FADE_COVER ) {
				if ( _power->get( ) > 0 ) {
					return NEXT_STAGE;
				} else {
					return NEXT_RESULT;
				}
			}
		}
		break;
	}

	_tarosuke->update( _field );
	_tarosuke->adjust( _camera );
	_momotaro->update( _field );
	_momotaro->adjust( _camera );
	_camera->update( _tarosuke );
	_status->update( );

	if ( !_tarosuke->isCalling( ) ) {
		_enemy_mgr->update( _field, _camera, _tarosuke, _momotaro );
		_psychic_mgr->update( _camera, _tarosuke, _enemy_mgr );
		_field->update( _camera );
	}

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

