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
	int _panel_count;
	int _count;
	int _select;
	int _tarosuke_x;
	int _tarosuke_vx;
	bool _tarosuke_right;
	bool _tarosuke_move;
};

