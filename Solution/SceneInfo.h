#pragma once

#include "Scene.h"
#include "mathmatics.h"
#include <array>

class SceneInfo : public Scene {
public:
	SceneInfo( );
	virtual ~SceneInfo( );
private:
	struct Data {
		Vector pos;
		Vector target;
		int graph;
		int width;
		int height;
		int count;
	};
private:
	NEXT update( );
	int _count;
	std::array< Data, 3 > _data;
};

