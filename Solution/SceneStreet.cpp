#include "SceneStreet.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"

SceneStreet::SceneStreet( ) {
	_tarosuke = TarosukePtr( new Tarosuke );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
}


SceneStreet::~SceneStreet( ) {
}

void SceneStreet::update( ) {
	draw( );
}

void SceneStreet::draw( ) {
	_tarosuke->draw( _chip_drawer );
}
