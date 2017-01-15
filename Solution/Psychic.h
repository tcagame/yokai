#pragma once

#include "smart_ptr.h"
#include "define.h"

PTR( Camera );

class Psychic {
public:
	Psychic( );
	virtual ~Psychic( );
	void update( );
	void draw( CameraConstPtr camera );
	void shooting( int x, int y, bool right );
private:
	enum PSYCHIC {
		PSYCHIC_BLUE,
		PSYCHIC_YELLOW,
		MAX_PSYCHIC
	};
	enum STATE {
		STATE_WAIT,
		STATE_CHARGE,
		STATE_RELEASE,
		MAX_STATE
	};
private:
	void move( );
private:
	int _x;
	int _y;
	bool _right;
	STATE _state;
	CHIP_POS _chip_pos[ MAX_STATE ][ MAX_PSYCHIC ];
};