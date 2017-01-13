#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Map.h"
#include "CloudManager.h"

SceneStreet::SceneStreet( ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_psychic_mgr = PsychicMgrPtr( new PsychicMgr( ) );
	_tarosuke = TarosukePtr( new Tarosuke( _psychic_mgr ) );
	_momotaro = MomotaroPtr( new Momotaro( 300, 100 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
	_camera = CameraPtr( new Camera( _tarosuke, map ) );
	_cloud_manager = CloudManagerPtr( new CloudManager );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( _field );
	_momotaro->update( _field );
	_psychic_mgr->update( );
	_tarosuke->update( _field );
	_momotaro->update( _field );
	_camera->update( );
	_field->update( _camera );

	_field->draw( );
	_cloud_manager->draw( _camera );
	_tarosuke->draw( _chip_drawer, _camera );
	_momotaro->draw( _chip_drawer, _camera );
	_psychic_mgr->draw( );

	return NEXT_CONTINUE;
}
