#pragma once

#include "Scene.h"
#include "smart_ptr.h"

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
	int _prob;
};

