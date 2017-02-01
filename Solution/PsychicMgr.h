#pragma once

#include "smart_ptr.h"
#include "mathmatics.h"
#include <list>
#include <array>

PTR( Psychic );
PTR( Camera );
PTR( Tarosuke );
PTR( Psychic );
PTR( EnemyManager );
PTR( Enemy );

class PsychicMgr {
public:
	PsychicMgr( );
	virtual ~PsychicMgr( );
public:
	void shoot( PsychicPtr psychic );
	void update( CameraConstPtr camera, TarosukeConstPtr tarosuke, EnemyManagerPtr enemy_mgr );
	void draw( CameraConstPtr camera ) const;
	EnemyPtr getOverlappedEnemy( PsychicPtr pcychic, EnemyManagerPtr enemy_mgr );
private:
	static const int IMPACT_NUM = 20;
	struct Impact {
		Vector pos;
		int count;
		bool big;
	};
private:
	void addImpact( const Vector& pos, bool big );
	void drawImpact( CameraConstPtr camera ) const;
	void updateImpact( );
private:
	std::list< PsychicPtr > _psychics;
	std::array< Impact, IMPACT_NUM > _impact;
	int _idx_impact;
};
