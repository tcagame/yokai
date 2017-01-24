#pragma once

#include "Scene.h"

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
private:
	NEXT update( );
	void act( );
	void draw( );
private:
	int _count;
	int _select;
};

