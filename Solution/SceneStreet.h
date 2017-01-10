#pragma once

#include "smart_ptr.h"
#include "Scene.h"

PTR( Tarosuke );
PTR( ChipDrawer );

class SceneStreet : public Scene {
public:
	SceneStreet();
	virtual ~SceneStreet();
	virtual void update( );
private:
	void draw( );
private:
	TarosukePtr _tarosuke;
	ChipDrawerPtr _chip_drawer;
};

