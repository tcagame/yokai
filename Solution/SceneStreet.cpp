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
#include "EnemyStock.h"
#include "Inputter.h"

static const int CLEAR_COUNT = 120;
static const int DEAD_COUNT = 150;

SceneStreet::SceneStreet() {
	srand( 0 );

	GamePtr game = Game::getTask( );

	DrawerPtr drawer = Drawer::getTask();
	drawer->loadGraph( GRAPH_CHARACTER_1		, "Character/Character1.png");
	drawer->loadGraph( GRAPH_CHARACTER_2		, "Character/Character2.png");
	drawer->loadGraph( GRAPH_PSYCHIC			, "Character/psychic.png");
	drawer->loadGraph( GRAPH_CLOUD_BIG			, "street/cloud/Yokai_OBJ_cloud1.png");
	drawer->loadGraph( GRAPH_CLOUD_SMALL		, "street/cloud/Yokai_OBJ_cloud2.png");
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE		, "street/other/mapchipguide.png");
	drawer->loadGraph( GRAPH_IMPACT				, "street/other/impact.png");
	drawer->loadGraph( GRAPH_BOMB				, "street/other/bomb.png");
	drawer->loadGraph( GRAPH_STATUS_POWER		, "street/status/status_power.png");
	drawer->loadGraph( GRAPH_STATUS_MARKER		, "street/status/status_marker.png");
	drawer->loadGraph( GRAPH_STATUS_PLATE		, "street/status/status_plate.png");
	drawer->loadGraph( GRAPH_ENEMY_NORMAL		, "street/enemy/enemy_nomal.png");
	drawer->loadGraph( GRAPH_ENEMY_SMALL		, "street/enemy/enemy_small.png");
	drawer->loadGraph( GRAPH_ENEMY_BIG			, "street/enemy/enemy_big.png");
	drawer->loadGraph( GRAPH_REPLAY				, "street/status/status_replay.png" );
	drawer->loadGraph( GRAPH_GAMEOVER			, "street/status/status_gameover.png" );

	_inputter = InputterPtr( new Inputter );
	if ( game->isDemo( ) ) {
		if ( game->isSolo( ) ) {
			switch ( game->getStage( ) ) {
			case 0: _inputter->load( "record/record_solo_0" ); break;
			case 1: _inputter->load( "record/record_solo_1" ); break;
			case 2: _inputter->load( "record/record_solo_2" ); break;
			case 3: _inputter->load( "record/record_solo_3" ); break;
			case 4: _inputter->load( "record/record_solo_4" ); break;
			}
		} else {
			switch ( game->getStage( ) ) {
			case 0: _inputter->load( "record/record_coop_0" ); break;
			case 1: _inputter->load( "record/record_coop_1" ); break;
			case 2: _inputter->load( "record/record_coop_2" ); break;
			case 3: _inputter->load( "record/record_coop_3" ); break;
			case 4: _inputter->load( "record/record_coop_4" ); break;
			}
		}
	}

	MapConstPtr map;
	switch ( game->getStage( ) ) {
	case 0:
		map = MapPtr(new Map0);
		drawer->loadGraph(GRAPH_STATUS_MAP   , "street/status/status_map_0.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE , "street/status/status_title_0.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_BODY       , "street/enemy/enemy_tree_body.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_ITEM       , "street/enemy/enemy_tree_item.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_GREEN	, "street/enemy/enemy_frog_green.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_reddemon.png");
		break;
	case 1:
		map = MapPtr(new Map1);
		drawer->loadGraph(GRAPH_STATUS_MAP   , "street/status/status_map_1.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE , "street/status/status_title_1.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_bluedemon.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_RED		, "street/enemy/enemy_frog_red.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		break;
	case 2:
		map = MapPtr(new Map2);
		drawer->loadGraph(GRAPH_STATUS_MAP, "street/status/status_map_2.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_2.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_sanzu.png");
		break;
	case 3:
		map = MapPtr(new Map3);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_3.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_3.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS        , "street/enemy/boss_enma.png");
		drawer->loadGraph(GRAPH_ENEMY_ROCKMASS, "street/enemy/enemy_rock_mass.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_MONSTER_BODY, "street/enemy/enemy_tree_monster_body.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_MONSTER_ITEM, "street/enemy/enemy_tree_monster_item.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		break;
	case 4:
		map = MapPtr(new Map4);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_4.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_4.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		break;
	case 5:
		map = MapPtr(new MapTest);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_0.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_test.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_bluedemon.png");
		drawer->loadGraph(GRAPH_ENEMY_ROCKMASS, "street/enemy/enemy_rock_mass.png");
		drawer->loadGraph( GRAPH_ENEMY_TREE_BODY			, "street/enemy/enemy_tree_body.png");
		drawer->loadGraph( GRAPH_ENEMY_TREE_ITEM			, "street/enemy/enemy_tree_item.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_RED				, "street/enemy/enemy_frog_red.png" );
		break;
	}
	
	EnemyStockPtr stock = EnemyStockPtr( new EnemyStock( ) );

	_field = FieldPtr( new Field( map, stock ) );
	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_power = PowerPtr( new Power );
	_momotaro = MomotaroPtr( new Momotaro( _inputter, _psychic_mgr, _power ) );
	_tarosuke = TarosukePtr( new Tarosuke( _inputter, _psychic_mgr, _power, _momotaro ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager( map, stock ) );
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
	GamePtr game = Game::getTask( );
	SoundPtr sound = Sound::getTask( );
	
	if ( game->isDemo( ) ) {
		DevicePtr device = Device::getTask( );
		if ( _inputter->isFinished( ) || device->getPush( ) != 0 ) {
			return NEXT_TITLE;
		}
	}

	switch ( _phase ) {
	case PHASE_NORMAL:
		if ( _camera->isLocked( ) ) {
			_phase = PHASE_BOSS;
			_phase_count = 0;
			switch ( game->getStage( ) ) {
			case 0:
				sound->playBGM( "yokai_music_04.wav" );
				break;
			case 1:
				sound->playBGM( "yokai_music_04.wav" );
				break;
			case 2:
				sound->playBGM( "yokai_music_04.wav" );
				break;
			case 3:
				sound->playBGM( "yokai_music_02.wav" );
				break;
			case 4:
				sound->playBGM( "yokai_music_08.wav" );
				break;
			case 5:
				sound->playBGM( "yokai_music_02.wav" );
				break;
			}
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
			if ( game->isDemo( ) ) {
				return NEXT_TITLE;
			}
			game->setFade( Game::FADE_OUT );
			_phase = PHASE_FADEOUT;
		}
		break;
	case PHASE_CLEAR:
		if ( _phase_count > CLEAR_COUNT ) {
			if ( game->isDemo( ) ) {
				return NEXT_TITLE;
			}
			game->setFade( Game::FADE_OUT );
			_phase = PHASE_FADEOUT;
		}
		break;
	case PHASE_FADEOUT:
		if ( game->getFade( ) == Game::FADE_COVER ) {
			if ( !game->isDemo( ) ) {
				if ( game->isSolo( ) ) {
					switch ( game->getStage( ) ) {
					case 0: _inputter->save( "record/record_solo_0" ); break;
					case 1: _inputter->save( "record/record_solo_1" ); break;
					case 2: _inputter->save( "record/record_solo_2" ); break;
					case 3: _inputter->save( "record/record_solo_3" ); break;
					case 4: _inputter->save( "record/record_solo_4" ); break;
					}
				} else {
					switch ( game->getStage( ) ) {
					case 0: _inputter->save( "record/record_coop_0" ); break;
					case 1: _inputter->save( "record/record_coop_1" ); break;
					case 2: _inputter->save( "record/record_coop_2" ); break;
					case 3: _inputter->save( "record/record_coop_3" ); break;
					case 4: _inputter->save( "record/record_coop_4" ); break;
					}
				}
			}
			if ( _power->get( ) > 0 ) {
				return NEXT_STAGE;
			} else {
				return NEXT_RESULT;
			}
		}
		break;
	}

	_inputter->update( );
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

	if ( game->isDemo( ) ) {
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Sprite sprite(
			Drawer::Transform( 0, SCREEN_HEIGHT * 9 / 10 ), GRAPH_REPLAY );
		drawer->setSprite( sprite );
	}
	if ( _phase == PHASE_DEAD && _phase_count > 90 && !game->isDemo( ) ) {
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Sprite sprite(
			Drawer::Transform( 400, 240 ), GRAPH_GAMEOVER );
		drawer->setSprite( sprite );
	}

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

