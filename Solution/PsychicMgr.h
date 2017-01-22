#pragma once

#include "smart_ptr.h"
#include <list>

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
	std::list< PsychicPtr > _psychics;
};
