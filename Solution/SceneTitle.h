#pragma once

#include "Scene.h"

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
	NEXT update( );
private:
	enum GRAPH {
		GRAPH_FONT,
		GRAPH_FRAME,
		GRAPH_PANEL,
	};
private:
	void act( );
	void draw( );
private:
	int _count;
	bool _finish;
};

