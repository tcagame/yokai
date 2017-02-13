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
#include "Infomation.h"

static const int CLEAR_COUNT = 120;
static const int DEAD_COUNT = 150;
static const int DEATH_POINTS_COUNT = 80;
static const int WAIT_FADE_OUT_TIME = 600;

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
	drawer->loadGraph( GRAPH_IMPACT_BIG         , "street/other/impact_big.png");
	drawer->loadGraph( GRAPH_BOMB				, "street/other/bomb.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_0		, "street/status/status_power_0.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_1		, "street/status/status_power_1.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_2		, "street/status/status_power_2.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_3		, "street/status/status_power_3.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_4		, "street/status/status_power_4.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_5		, "street/status/status_power_5.png");
	drawer->loadGraph( GRAPH_STATUS_POWER_6		, "street/status/status_power_6.png");
	drawer->loadGraph( GRAPH_STATUS_MARKER		, "street/status/status_marker.png");
	drawer->loadGraph( GRAPH_STATUS_PLATE		, "street/status/status_plate.png");
	drawer->loadGraph( GRAPH_ENEMY_NORMAL		, "street/enemy/enemy_nomal.png");
	drawer->loadGraph( GRAPH_ENEMY_SMALL		, "street/enemy/enemy_small.png");
	drawer->loadGraph( GRAPH_ENEMY_BIG			, "street/enemy/enemy_big.png");
	drawer->loadGraph( GRAPH_REPLAY				, "street/status/status_replay.png" );
	drawer->loadGraph( GRAPH_GAMEOVER			, "street/status/status_gameover.png" );
	drawer->loadGraph( GRAPH_DEATH_POINT        , "street/status/status_deth_point.png" );


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
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_0.png" );
		break;
	case 1:
		map = MapPtr(new Map1);
		drawer->loadGraph(GRAPH_STATUS_MAP   , "street/status/status_map_1.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE , "street/status/status_title_1.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_bluedemon.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_RED		, "street/enemy/enemy_frog_red.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_1.png" );
		break;
	case 2:
		map = MapPtr(new Map2);
		drawer->loadGraph(GRAPH_STATUS_MAP, "street/status/status_map_2.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_2.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS         , "street/enemy/boss_sanzu.png");
		drawer->loadGraph(GRAPH_ENEMY_CROW         , "street/enemy/enemy_crow.png");
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_2.png" );
		break;
	case 3:
		map = MapPtr(new Map3);
		drawer->loadGraph(GRAPH_STATUS_MAP				, "street/status/status_map_3.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE			, "street/status/status_title_3.png");
		drawer->loadGraph(GRAPH_ENEMY_BOSS				, "street/enemy/boss_enma.png");
		drawer->loadGraph(GRAPH_ENEMY_ROCKMASS			, "street/enemy/enemy_rock_mass.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_MONSTER_BODY	, "street/enemy/enemy_tree_monster_body.png");
		drawer->loadGraph(GRAPH_ENEMY_TREE_MONSTER_ITEM	, "street/enemy/enemy_tree_monster_item.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL			, "street/enemy/enemy_fireball.png");
		drawer->loadGraph(GRAPH_ENEMY_BLOOD_POND		, "street/enemy/enemy_blood_pond.png");
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_3.png" );
		break;
	case 4:
		map = MapPtr(new Map4);
		drawer->loadGraph(GRAPH_STATUS_MAP  , "street/status/status_map_4.png");
		drawer->loadGraph(GRAPH_STATUS_TITLE, "street/status/status_title_4.png");
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_4.png" );
		break;
	case 5:
		map = MapPtr(new MapTest);
		drawer->loadGraph( GRAPH_STATUS_MAP			, "street/status/status_map_0.png");
		drawer->loadGraph( GRAPH_STATUS_TITLE		, "street/status/status_title_test.png");
		drawer->loadGraph( GRAPH_ENEMY_BOSS			, "street/enemy/boss_reddemon.png");
		drawer->loadGraph( GRAPH_ENEMY_ROCKMASS		, "street/enemy/enemy_rock_mass.png");
		drawer->loadGraph( GRAPH_ENEMY_TREE_BODY	, "street/enemy/enemy_tree_body.png");
		drawer->loadGraph( GRAPH_ENEMY_TREE_ITEM	, "street/enemy/enemy_tree_item.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_RED		, "street/enemy/enemy_frog_red.png" );
		drawer->loadGraph( GRAPH_ENEMY_FIREBALL		, "street/enemy/enemy_fireball.png");
		drawer->loadGraph( GRAPH_ENEMY_FLOG_GREEN	, "street/enemy/enemy_frog_green.png");
		drawer->loadGraph( GRAPH_ENEMY_BLOOD_POND	, "street/enemy/enemy_blood_pond.png");
		drawer->loadGraph( GRAPH_FAR_BG             , "street/other/bg_far_test.png" );
		break;
	}
	
	EnemyStockPtr stock = EnemyStockPtr( new EnemyStock( ) );

	_field = FieldPtr( new Field( map, stock ) );
	_camera = CameraPtr( new Camera( map ) );
	_power = PowerPtr( new Power );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
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
			game->setFade( Game::FADE_COVER );
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
			sound->playBGM( "yokai_se_31.wav", false );
			_phase = PHASE_DEAD;
			makeDeathPoints( );
			_phase_count = 0;
		}
		break;
	case PHASE_BOSS:
		if ( !_tarosuke->isCalling( ) ) {
			_enemy_mgr->attackBoss( );
		}
		if ( _enemy_mgr->isBossDead( ) ) {
			_enemy_mgr->clear( );
			_phase = PHASE_CLEAR;
			Infomation info;
			info.increaseDenominator( game->getStage( ) );
			info.increaseNumerator( game->getStage( ) );
			_phase_count = 0;
			SoundPtr sound = Sound::getTask( );
			sound->playBGM( "yokai_se_32.wav" );
		}
		if ( _power->get( ) == 0 ) {
			sound->playBGM( "yokai_se_31.wav", false );
			_phase = PHASE_DEAD;
			makeDeathPoints( );
			_phase_count = 0;
		}
		break;
	case PHASE_DEAD:
		if ( _phase_count > DEAD_COUNT ) {
			if ( game->isDemo( ) ) {
				return NEXT_TITLE;
			}
			DevicePtr device = Device::getTask( );
			if ( ( device->getButton( ) != 0 ) ||
				 ( _phase_count > WAIT_FADE_OUT_TIME ) ) {
				game->setFade( Game::FADE_OUT );
				_phase = PHASE_FADEOUT;
			}
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
	_tarosuke->adjust( _camera, _field );
	_momotaro->update( _field );
	_momotaro->adjust( _camera, _field  );
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
	if ( _phase == PHASE_DEAD && _phase_count > DEATH_POINTS_COUNT && !game->isDemo( ) ) {
		//@Ž€‚ñ‚¾êŠ‚w
		drawDeathPoints( );
		//‚°`‚Þ‚¨`‚Î`
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Sprite sprite(
			Drawer::Transform( ( SCREEN_WIDTH - 704 ) / 2, ( SCREEN_HEIGHT - 96 ) / 2 ), GRAPH_GAMEOVER );
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

void SceneStreet::makeDeathPoints( ) {
	GamePtr game = Game::getTask( );
	int stage = game->getStage( );
	int dx = _tarosuke->getX( );
	int dy = _tarosuke->getY( );

	if ( dy > BG_SIZE ) {
		dy = BG_SIZE;
	}
	
	Infomation info;
	info.increaseDenominator( game->getStage( ) );
	info.setHistroy( stage, dx, dy );

	for ( int i = 1; i < Infomation::HISTORY_NUM; i++ ) {
		int x = info.getHistoryX( stage, i );
		int y = info.getHistoryY( stage, i );
		if ( x + y == 0 ) {
			continue;
		}

		Vector pos( x - _camera->getX( ), y - _camera->getY( ) );
		if ( pos.x < -64 || pos.x > SCREEN_WIDTH + 64 ) {
			continue;
		}

		_death_points.push_back( pos );
	}
}

void SceneStreet::drawDeathPoints( ) {
	const int DEATH_CHIP_SIZE = 32;
	DrawerPtr drawer = Drawer::getTask( );
	int count = ( _phase_count - DEATH_POINTS_COUNT ) / 4;
	int size = ( _phase_count - DEATH_POINTS_COUNT ) / 4;
	if ( size > ( int )_death_points.size( ) ) {
		size = ( int )_death_points.size( );
	}
	
	std::list< Vector >::iterator it = _death_points.begin( );
	for ( int i = 0; i < size; i++ ) {
		int pattern = count - i - 1;
		if ( pattern > 3 ) {
			pattern = 3;
		}
		int sx = ( int )( *it ).x;
		int sy = ( int )( *it ).y;
		int tx = pattern % 2 * DEATH_CHIP_SIZE;
		int ty = pattern / 2 * DEATH_CHIP_SIZE;

		Drawer::Sprite sprite(
			Drawer::Transform( sx - DEATH_CHIP_SIZE / 2, sy - DEATH_CHIP_SIZE, tx, ty, DEATH_CHIP_SIZE, DEATH_CHIP_SIZE ),
			GRAPH_DEATH_POINT );
		drawer->setSprite( sprite );

		it++;
	}
}
