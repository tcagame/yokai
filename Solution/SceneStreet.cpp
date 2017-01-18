#include "SceneStreet.h"
#include "Tarosuke.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Map.h"
#include "Drawer.h"
#include "PsychicMgr.h"

SceneStreet::SceneStreet( ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_camera = CameraPtr( new Camera( map ) );
	_psychic_mgr = PsychicMgrPtr( new PsychicMgr( _camera ) );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr ) );
	_momotaro = MomotaroPtr( new Momotaro( _camera ) );
	
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER   , "Yokai_OBJ_myCharacter.png" );
	drawer->loadGraph( GRAPH_CLOUD_SMALL , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG   , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE, "street/mapchipguide.png" );
	drawer->loadGraph( GRAPH_EFFECT_0    , "Yokai_OBJ_effect0.png" );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( _field );
	_momotaro->update( _field );
	_psychic_mgr->update( );
	_camera->update( _tarosuke );
	_field->update( _camera );

	_field->draw( _camera );
	_tarosuke->draw( _camera );
	_momotaro->draw( _camera );
	_psychic_mgr->draw( _camera );

	return NEXT_CONTINUE;
}
