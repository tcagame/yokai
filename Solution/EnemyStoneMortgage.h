#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyStoneMortgage : public Enemy {
public:
	EnemyStoneMortgage( int x, int y, int type );
	virtual ~EnemyStoneMortgage( );
	void setMove( bool moveing );
	void back( );
private:
	void act( );
	void updateChip( );
	void actMove( );;
	bool isOutSideScreen( CameraConstPtr camera ) const;
private:
	const Vector _base_pos;
	const int _type;
	double _vy;
	int _count;
	bool _moveing;
	Vector _return_pos;
};

