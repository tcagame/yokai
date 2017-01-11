#include "Tarosuke.h"
#include "ChipDrawer.h"

Tarosuke::Tarosuke( int x, int y ) : 
Character( x, y ) {
	setChip( ChipDrawer::CHIP::CHIP_TAROSUKE );

}


Tarosuke::~Tarosuke( ) {

}

