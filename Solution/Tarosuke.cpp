#include "Tarosuke.h"
#include "ChipDrawer.h"

Tarosuke::Tarosuke( ) {

}


Tarosuke::~Tarosuke( ) {

}

void Tarosuke::draw( ChipDrawerPtr chip_drawer ) {
	int x = 0;
	int y = 0;
	chip_drawer->draw( ChipDrawer::CHIP_TAROSUKE, x, y );
}