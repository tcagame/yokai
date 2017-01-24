#pragma once

#include "Scene.h"

class SceneGate : public Scene {
public:
	SceneGate( );
	virtual ~SceneGate( );
private:
	NEXT update( );
	void act( );
	void draw( ) const;
private:
	int _x;
};

