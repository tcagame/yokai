#pragma once

#include <array>

class ChipDrawer {
public:
	enum CHIP {
		CHIP_TAROSUKE,
		CHIP_MOMOTARO,
		MAX_CHIP
	};
	struct ChipPos {
		int cx;
		int cy;
		ChipPos( ) {
		};
		ChipPos( int x, int y ) :
			cx( x ), cy( y ) {
		}
	};
public:
	ChipDrawer( );
	~ChipDrawer( );
	void draw( CHIP chip, int sx, int sy );
private:
	std::array< ChipPos, MAX_CHIP > _chip_pos;
};

