#pragma once

#include "Scene.h"

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
private:
	int _level;
};

