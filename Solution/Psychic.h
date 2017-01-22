#pragma once

#include "Character.h"

class Psychic : public Character {
public:
	Psychic( int x, int y );
	virtual ~Psychic( );
public:
	void setRange( int range_x, int target_x, int target_y );
	int getRange( ) const;
	int getTargetX( ) const;
	int getTargetY( ) const;
	bool isFinished( ) const;
	int getPow( ) const;
	virtual void hit( ) = 0;
protected:
	void finish( );
	void setPow( int pow );
private:
	int _pow;
	int _range_x;
	int _target_x;
	int _target_y;
	bool _finished;
};
