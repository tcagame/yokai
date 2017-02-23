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
static const int WAIT_FADE_OUT_TIME = 1000;
static const int CHOICE_CURSORY_X = 475;
static const int CHOICE_CURSORY_Y = 440;
static const int CHOICE_FONT_X = 400;
static const int CHOICE_FONT_Y = 250;
static const int GAME_OVER_TIME =100;


SceneStreet::SceneStreet( ) :
_select( 0 ),
_count( 0 ) {
	srand( 0 );

	GamePtr game = Game::getTask( );

	DrawerPtr drawer = Drawer::getTask();
	drawer->loadGraph( GRAPH_CHARACTER_1		, "Character/Character1.png");
	drawer->loadGraph( GRAPH_CHARACTER_2		, "Character/Character2.png");
	drawer->loadGraph( GRAPH_PSYCHIC			, "Character/psychic.png");
	drawer->loadGraph( GRAPH_CLOUD_BIG			, "street/cloud/Yokai_OBJ_cloud1.png");
	drawer->loadGraph( GRAPH_CLOUD_SMALL		, "street/cloud/Yokai_OBJ_cloud2.png");
	drawer->loadGraph( GRAPH_ITEM		        , "street/other/item.png");
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
	drawer->loadGraph( GRAPH_STATUS_CONTINUE    , "street/status/status_continue.png");
	drawer->loadGraph( GRAPH_STATUS_PLATE		, "street/status/status_plate.png");
	drawer->loadGraph( GRAPH_ENEMY_NORMAL		, "street/enemy/enemy_nomal.png");
	drawer->loadGraph( GRAPH_ENEMY_SMALL		, "street/enemy/enemy_small.png");
	drawer->loadGraph( GRAPH_ENEMY_BIG			, "street/enemy/enemy_big.png");
	drawer->loadGraph( GRAPH_ENEMY_ANIMAL_DOG   , "street/enemy/enemy_dog.png");
	drawer->loadGraph( GRAPH_ENEMY_ANIMAL_CAT   , "street/enemy/enemy_cat.png");
	drawer->loadGraph( GRAPH_DEATH_POINT        , "street/status/status_deth_point.png" );
	drawer->loadGraph( GRAPH_FONT_REPLAY		, "font/font_replay.png" );
	drawer->loadGraph( GRAPH_FONT_GAMEOVER	    , "font/font_gameover.png" );
	drawer->loadGraph( GRAPH_FONT_CONTINUE	    , "font/font_continue.png" );
	drawer->loadGraph( GRAPH_FONT_CURSOR		, "font/font_cursor.png" );


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

	PowerPtr pow = game->getPower( );

	_field = FieldPtr( new Field( map, stock ) );
	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_momotaro = MomotaroPtr( new Momotaro( _inputter, _psychic_mgr, pow ) );
	_tarosuke = TarosukePtr( new Tarosuke( _inputter, _psychic_mgr, pow, _momotaro ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager( map, stock ) );
	_status = StatusPtr( new Status( pow, _field, _tarosuke ) );
	_phase = PHASE_NORMAL;
	_phase_count = 0;

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_12.wav" );

	_count++;
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_phase_count++;
	GamePtr game = Game::getTask( );
	SoundPtr sound = Sound::getTask( );
	PowerPtr pow = game->getPower( );
	
	if ( game->isDemo( ) ) {
		DevicePtr device = Device::getTask( );
		if ( _inputter->isFinished( ) || device->getPush( 0 ) != 0 || device->getPush( 1 ) != 0 ) {
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
		if ( pow->get( ) == 0 ) {
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
			_phase_count = 0;
			if ( game->getContinueCount( ) == 0 ) {
				Infomation info;
				info.increaseDenominator( game->getStage( ) );
				info.increaseNumerator( game->getStage( ) );
			}
			SoundPtr sound = Sound::getTask( );
			sound->playBGM( "yokai_se_32.wav" );
		}
		if ( pow->get( ) == 0 ) {
			sound->playBGM( "yokai_se_31.wav", false );
			_phase = PHASE_DEAD;
			makeDeathPoints( );
			_phase_count = 0;
		}
		break;
	case PHASE_DEAD:
		if ( _phase_count > DEAD_COUNT ) {
			//デモ
			if ( game->isDemo( ) ) {
				return NEXT_TITLE;
			}
			//一定時間orボタンでリザルトへ移動
			if ( _phase_count > WAIT_FADE_OUT_TIME ) {
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
	case PHASE_CONTINUE:
		_phase = PHASE_NORMAL;
		_enemy_mgr->clear( );
		game->getPower( )->reset( );
		_tarosuke->rebirth( );
		sound->playBGM( "yokai_music_12.wav" );
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
			if ( pow->get( ) > 0 ) {
				return NEXT_STAGE;
			} else {
				return NEXT_THANKS;
			}
		}
		break;
	}

	_inputter->update( );
	_tarosuke->update( _field );
	_tarosuke->adjust( _camera, _field );
	_momotaro->update( _field );
	_momotaro->adjust( _camera, _field  );


	if ( !_tarosuke->isCalling( ) ) {
		_camera->update( _tarosuke );
		_status->update( );
		_enemy_mgr->update( _field, _camera, _tarosuke, _momotaro );
		_psychic_mgr->update( _camera, _tarosuke, _enemy_mgr );
		_field->update( _camera, _tarosuke );
	}

	_field->draw( _camera );
	_enemy_mgr->draw( _camera );
	_tarosuke->draw( _camera );
	_momotaro->draw( _camera );
	_psychic_mgr->draw( _camera );
	_field->drawCover( );
	_status->draw( );

	if ( _phase == PHASE_DEAD && _phase_count > DEATH_POINTS_COUNT ) {
		updatePhaseDead( );
	}

	if ( game->isDemo( ) ) {
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Sprite sprite(
			Drawer::Transform( 0, SCREEN_HEIGHT * 9 / 10 ), GRAPH_FONT_REPLAY );
		drawer->setSprite( sprite );
	}
	debugWarp( );

	return NEXT_CONTINUE;
}

void SceneStreet::updatePhaseDead( ) {
	DevicePtr device = Device::getTask( );
	if ( _count >= GAME_OVER_TIME ) {
		for ( int i = 0; i < 2; i++ ) {
			if ( device->getDirY( i ) < 0 && _select != 0 ) {
				_select = 0;
				SoundPtr sound = Sound::getTask( );
				sound->playSE( "yokai_se_06.wav" );
			}
			if ( device->getDirY( i ) > 0 && _select != 1  ) {
				_select = 1;
				SoundPtr sound = Sound::getTask( );
				sound->playSE( "yokai_se_06.wav" );
			}
			if ( device->getButton( i ) != 0 ) {
				GamePtr game = Game::getTask( );
				if ( _select == 0 ) {
					game->increaseContinueCount( );
					_phase = PHASE_CONTINUE;
				} else {
					game->setFade( Game::FADE_OUT );
					_phase = PHASE_FADEOUT;
				}
			}
		}
	}
	drawPhaseDead( );
	_count++;
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

	if ( game->getContinueCount( ) == 0 ) {
		info.increaseDenominator( game->getStage( ) );
	}

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

void SceneStreet::drawPhaseDead( ) {
	drawDeathPoints( );
	if ( _count < GAME_OVER_TIME ) {
		drawGameOver( );
	}
	if (_count >= GAME_OVER_TIME ) {
		drawContinue( );
	}
}

void SceneStreet::drawGameOver( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans = Drawer::Transform( ( SCREEN_WIDTH - 704 ) / 2, ( SCREEN_HEIGHT - 96 ) / 2 );
	Drawer::Sprite sprite( trans, GRAPH_FONT_GAMEOVER );
	drawer->setSprite( sprite );
}

void SceneStreet::drawContinue( ) {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Sprite sprite_cusory(
			Drawer::Transform( CHOICE_CURSORY_X, CHOICE_CURSORY_Y + _select * 110 ),
			GRAPH_FONT_CURSOR );
	drawer->setSprite( sprite_cusory );
	
	Drawer::Sprite sprite_playerchoice(
		Drawer::Transform( CHOICE_FONT_X, CHOICE_FONT_Y ),
		GRAPH_FONT_CONTINUE );
	drawer->setSprite( sprite_playerchoice );
}
