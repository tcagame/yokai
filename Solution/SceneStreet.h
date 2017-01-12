#pragma once

#include "smart_ptr.h"
#include "Scene.h"

PTR( Tarosuke );
PTR( ChipDrawer );
PTR( Character );

class SceneStreet : public Scene {
public:
	SceneStreet( );
	virtual ~SceneStreet( );
	virtual NEXT update( );
private:
	void draw( );
private:
	ChipDrawerPtr _chip_drawer;
	CharacterPtr _tarosuke;
	CharacterPtr _momotaro;
};

