#pragma once

#include "Psychic.h"

class PsychicTarosuke : public Psychic {
public:
	PsychicTarosuke( int x, int y, bool reverse, int power );
	virtual ~PsychicTarosuke( );
private:
	void act( );
private:
	bool _dir_right;
	bool _outward;
	int _motion_count;
	int _power;
};

