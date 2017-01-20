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

SceneStreet::SceneStreet( bool solo ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr ) );
	_momotaro = MomotaroPtr( new Momotaro( _camera, _psychic_mgr ) );
	_enemy_mgr = EnemyManagerPtr( new EnemyManager );
	_status = StatusPtr( new Status );
	
	if ( solo ) {
		_tarosuke->setSoloPlay( _momotaro );
	}

	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER			 , "Yokai_OBJ_myCharacter.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG			 , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_CLOUD_SMALL		 , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE		 , "street/mapchipguide.png" );
	drawer->loadGraph( GRAPH_PSYCHIC			 , "psychic.png" );
	drawer->loadGraph( GRAPH_ENEMY_PURPLE_YOKAI	 , "street/enemy/Yokai_OBJ_enemy_purple.png" );
	drawer->loadGraph( GRAPH_ENEMY_REDBIRD		 , "street/enemy/Yokai_OBJ_enemy_RedBird.png" );
	drawer->loadGraph( GRAPH_ENEMY_REDBIRD_ATTACK, "street/enemy/Yokai_OBJ_enemy_RedBird_attack.png" );
	drawer->loadGraph( GRAPH_STATUS				 , "street/Yokai_UI_plate.png" );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( _field );
	_momotaro->update( _field );
	_camera->update( _tarosuke );
	_enemy_mgr->update( _field, _camera, _tarosuke, _momotaro );
	_psychic_mgr->update( _camera, _tarosuke );
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
