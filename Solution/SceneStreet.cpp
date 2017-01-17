#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Map.h"
#include "Drawer.h"
#include "PsychicMgr.h"

SceneStreet::SceneStreet( ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_psychic_mgr = PsychicMgrPtr( new PsychicMgr( ) );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr ) );
	_momotaro = MomotaroPtr( new Momotaro( 300, 100 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
	_camera = CameraPtr( new Camera( _tarosuke, map ) );

	
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CLOUD_SMALL , "street/cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG   , "street/cloud/Yokai_OBJ_cloud1.png" ); 
	drawer->loadGraph( GRAPH_MAPCHIPGUIDE, "street/mapchipguide.png" );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( _field );
	_momotaro->update( _field );
	_psychic_mgr->update( );
	_camera->update( );
	_field->update( _camera );

	_field->draw( _camera );
	_tarosuke->draw( _chip_drawer, _camera );
	_momotaro->draw( _chip_drawer, _camera );
	_psychic_mgr->draw( _camera );

	return NEXT_CONTINUE;
}
