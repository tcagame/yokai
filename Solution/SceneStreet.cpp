#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"
#include "Field.h"
#include "Camera.h"
#include "Map.h"

SceneStreet::SceneStreet( ) {
	MapConstPtr map( new Map );
	_field = FieldPtr( new Field( map ) );

	_psychic_mgr = PsychicMgrPtr( new PsychicMgr( ) );
	_tarosuke = TarosukePtr( new Tarosuke( 50, 400, _psychic_mgr ) );
	_momotaro = MomotaroPtr( new Momotaro( 300, 100 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
	_camera = CameraPtr( new Camera( _tarosuke, map ) );
}

SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( );
	_momotaro->update( );
	_psychic_mgr->update( );
	_camera->update( );
	_field->update( _camera );

	_field->draw( );
	_tarosuke->draw( _chip_drawer, _camera );
	_momotaro->draw( _chip_drawer, _camera );
	_psychic_mgr->draw( );

	return NEXT_CONTINUE;
}
