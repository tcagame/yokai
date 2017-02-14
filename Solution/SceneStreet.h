#pragma once

#include "smart_ptr.h"
#include "Scene.h"
#include "mathmatics.h"
#include <list>

PTR( Tarosuke );
PTR( Momotaro );
PTR( Field );
PTR( Camera );
PTR( PsychicMgr );
PTR( EnemyManager );
PTR( Status );
PTR( EnemyStock );
PTR( Inputter );
PTR( Game );

class SceneStreet : public Scene {
public:
	SceneStreet( );
	virtual ~SceneStreet( );
private:
	enum PHASE {
		PHASE_NORMAL,
		PHASE_BOSS,
		PHASE_DEAD,
		PHASE_CLEAR,
		PHASE_CONTINUE,
		PHASE_FADEOUT,
	};
private:
	virtual NEXT update( );
	void updatePhaseDead( );
	void debugWarp( );
	void makeDeathPoints( );
	void drawDeathPoints( );
	void drawPhaseDead( );
	void drawGameOver( );
	void drawContinue( );
private:
	InputterPtr _inputter;
	TarosukePtr _tarosuke;
	MomotaroPtr _momotaro;
	FieldPtr _field;
	CameraPtr _camera;
	PsychicMgrPtr _psychic_mgr;
	EnemyManagerPtr _enemy_mgr;
	StatusPtr _status;
	PHASE _phase;
	int _phase_count;
	int _select;
	int _count;
	std::list< Vector > _death_points;
};

