#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"
#include "Momotaro.h"

SceneStreet::SceneStreet( ) {
	_tarosuke = TarosukePtr( new Tarosuke );
	_momotaro = CharacterPtr( new Momotaro( 0, 32 ) );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
}


SceneStreet::~SceneStreet( ) {
}

void SceneStreet::update( ) {
	draw( );
}

void SceneStreet::draw( ) {
	_tarosuke->draw( _chip_drawer );
	_momotaro->draw( _chip_drawer );
}
