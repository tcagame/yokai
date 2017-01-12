#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"
#include "Field.h"

SceneStreet::SceneStreet( ) {
	_tarosuke = CharacterPtr( new Tarosuke( 0, 500 ) );
	_momotaro = CharacterPtr( new Momotaro( 300, 0 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
	_field = FieldPtr( new Field );
}


SceneStreet::~SceneStreet( ) {
}

Scene::NEXT SceneStreet::update( ) {
	_tarosuke->update( );
	_momotaro->update( );
	draw( );

	return NEXT_CONTINUE;
}

void SceneStreet::draw( ) {
	_field->draw( );
	_tarosuke->draw( _chip_drawer );
	_momotaro->draw( _chip_drawer );
}
