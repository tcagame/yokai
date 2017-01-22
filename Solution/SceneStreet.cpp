#include "SceneStreet.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Map.h"
#include "Drawer.h"
#include "PsychicMgr.h"
#include "EnemyManager.h"
#include "Status.h"
#include "Sound.h"
#include "Power.h"

SceneStreet::SceneStreet( bool solo ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_power = PowerPtr( new Power );
	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr, _power ) );
	_momotaro = MomotaroPtr( new Momotaro( _camera, _psychic_mgr, _power ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager );
	_status = StatusPtr( new Status( _power ) );
	
	if ( solo ) {
		_tarosuke->setSoloPlay( _momotaro );
	}

	DrawerPtr drawer = Drawer::getTask( );
<<<<<<< HEAD
	drawer->loadGraph( GRAPH_CHARACTER_1		 , "Character/Character1.png" );
	drawer->loadGraph( GRAPH_CHARACTER_2		 , "Character/Character2.png" );
	drawer->loadGraph( GRAPH_PSYCHIC			 , "Character/psychic.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG			 , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_CLOUD_SMALL		 , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE		 , "street/mapchipguide.png" );
	drawer->loadGraph( GRAPH_ENEMY				 , "street/Enemy0.png" );
	drawer->loadGraph( GRAPH_ENEMY_SMALL		 , "street/enemy_small.png" );
	drawer->loadGraph( GRAPH_ENEMY_TREE			 , "street/enemy_tree.png" );
=======
	drawer->loadGraph( GRAPH_CHARACTER_1		 , "street/player/Character1.png" );
	drawer->loadGraph( GRAPH_CHARACTER_2		 , "street/player/Character2.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG			 , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_CLOUD_SMALL		 , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE		 , "street/mapchipguide.png" );
	drawer->loadGraph( GRAPH_PSYCHIC			 , "psychic.png" );
	drawer->loadGraph( GRAPH_ENEMY				 , "street/enemy/Enemy0.png" );
	drawer->loadGraph( GRAPH_ENEMY_SMALL		 , "street/enemy/enemy_small.png" );
	drawer->loadGraph( GRAPH_ENEMY_TREE			 , "street/enemy/enemy_tree.png" );
>>>>>>> 582b2d30405a3c93eacbd3dbe7edba15bf769d5e
	drawer->loadGraph( GRAPH_STATUS_PLATE		 , "street/status/status_plate.png" );
	drawer->loadGraph( GRAPH_STATUS_POWER        , "street/status/status_power.png" );
	drawer->loadGraph( GRAPH_STATUS_MAP		     , "street/map0/status/status_map_0.png" );

	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "yokai_music_10.wav" );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( _field );
	_momotaro->update( _field );
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
	_status->draw( );

	return NEXT_CONTINUE;
}
