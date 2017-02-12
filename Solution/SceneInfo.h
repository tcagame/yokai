#pragma once

#include "Scene.h"

class SceneInfo : public Scene {
public:
	SceneInfo( );
	virtual ~SceneInfo( );
private:
	NEXT update( );
	int _count;
};

