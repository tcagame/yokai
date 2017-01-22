#pragma once

#include "smart_ptr.h"
#include "Scene.h"

PTR( Tarosuke );
PTR( Tarosuke );
PTR( Momotaro );
PTR( Field );
PTR( Camera );
PTR( PsychicMgr );
PTR( EnemyManager );
PTR( Status );
PTR( Power );

class SceneStreet : public Scene {
public:
	SceneStreet( bool solo );
	virtual ~SceneStreet( );
private:
	virtual NEXT update( );
private:
	PowerPtr _power;
	TarosukePtr _tarosuke;
	MomotaroPtr _momotaro;
	FieldPtr _field;
	CameraPtr _camera;
	PsychicMgrPtr _psychic_mgr;
	EnemyManagerPtr _enemy_mgr;
	StatusPtr _status;
};

