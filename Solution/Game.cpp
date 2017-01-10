#include "Game.h"
#include "Tarosuke.h"
#include "ChipDrawer.h"

Game::Game( ) {
	_tarosuke = TarosukePtr( new Tarosuke );
	_chip_drawer = ChipDrawerPtr( new ChipDrawer );
}


Game::~Game( ) {

}

void Game::update( ) {
	draw( );
}

void Game::draw( ) {
	_tarosuke->draw( _chip_drawer );
}