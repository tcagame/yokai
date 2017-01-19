#pragma once

#include "Scene.h"

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
	NEXT update( );
private:
	void act( );
	void draw( );
private:
	int _count;
	bool _finish;
	int _select;
};

