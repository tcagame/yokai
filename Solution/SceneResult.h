#pragma once

#include "Scene.h"
#include "smart_ptr.h"

class SceneResult : public Scene {
public:
	SceneResult( );
	virtual ~SceneResult( );
private:
	NEXT update( );
	void drawFrame( );
	void drawHeaven( ); 
	void drawHuman( );  
	void drawDamn( );   
	void drawHungry( ); 
	void drawHell( );
	void drawNumber( );
private:
	int _level;
	int _count;
	int _offset_y;
	int _vy;
	int _continue_count;
};

