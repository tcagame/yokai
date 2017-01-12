#pragma once

#include "smart_ptr.h"
#include "Scene.h"

PTR( Tarosuke );
PTR( ChipDrawer );
PTR( Tarosuke );
PTR( Momotaro );
PTR( Field );
PTR( Camera );

class SceneStreet : public Scene {
public:
	SceneStreet( );
	virtual ~SceneStreet( );
	virtual NEXT update( );
private:
	ChipDrawerPtr _chip_drawer;
	TarosukePtr _tarosuke;
	MomotaroPtr _momotaro;
	FieldPtr _field;
	CameraPtr _camera;
};

