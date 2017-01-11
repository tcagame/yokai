#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"

SceneStreet::SceneStreet( ) {
	_tarosuke = CharacterPtr( new Tarosuke( 0, 0 ) );
	_momotaro = CharacterPtr( new Momotaro( 300, 0 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
}


SceneStreet::~SceneStreet( ) {
}

void SceneStreet::update( ) {
	_tarosuke->update( );
	_momotaro->update( );
	draw( );
}

void SceneStreet::draw( ) {
	_tarosuke->draw( _chip_drawer );
	_momotaro->draw( _chip_drawer );
}
