#pragma once

class Psychic {
public:
	Psychic( );
	virtual ~Psychic( );
	void update( );
	void draw( int x, int y, bool right );
private:
	enum PSYCHIC {
		PSYCHIC_BLUE,
		PSYCHIC_YELLOW,
		MAX_PSYCHIC
	};
	struct CHIP_POS {
		int cx;
		int cy;
		CHIP_POS( ) {
		};
		CHIP_POS( int x, int y ) :
			cx( x ), cy( y ) {
		}
	};

};
