#pragma once

#include "smart_ptr.h"
#include "Psychic.h"
#include "mathmatics.h"
#include <array>

class PsychicMomotaro : public Psychic {
public:
	PsychicMomotaro( int x, int y, bool right );
	virtual ~PsychicMomotaro( );
private:
	void act( );
	void hit( bool killed );
	virtual void draw( CameraConstPtr camera, bool bright = false ) const;
	Vector getOverlappedPos( ) const;
	double getOverlappedRadius( ) const;
private:
	static const int TAIL_NUM = 60;
	static const int DIV_NUM = 10;
	Vector _pos;
	Vector _vec;
	Vector _accel;
	std::array< Vector, TAIL_NUM > _tails;
	int _count;
};

