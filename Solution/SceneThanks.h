#pragma once
#include "Scene.h"

class SceneThanks : public Scene {
public:
	SceneThanks( );
	virtual ~SceneThanks( );
public:
	NEXT update( );
	void draw( );
private:
	int _next_count;
};

