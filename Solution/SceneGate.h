#pragma once

#include "Scene.h"
#include "smart_ptr.h"

class SceneGate : public Scene {
public:
	SceneGate( );
	virtual ~SceneGate( );
private:
	NEXT update( );
	void draw( ) const;
private:
	int _x;
	int _prob;
	int _map_offset_x;
	int _title_offset_x;
	int _clear_offset_y;
};

