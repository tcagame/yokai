#pragma once

#include "smart_ptr.h"
#include "Scene.h"

PTR( Tarosuke );
PTR( Tarosuke );
PTR( Momotaro );
PTR( Field );
PTR( Camera );
PTR( PsychicMgr );

class SceneStreet : public Scene {
public:
	SceneStreet( );
	virtual ~SceneStreet( );
	virtual NEXT update( );
private:
	TarosukePtr _tarosuke;
	MomotaroPtr _momotaro;
	FieldPtr _field;
	CameraPtr _camera;
	PsychicMgrPtr _psychic_mgr;
};

