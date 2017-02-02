#pragma once

#include "Scene.h"
#include "smart_ptr.h"

class SceneResult : public Scene {
public:
	SceneResult( );
	virtual ~SceneResult( );
private:
	enum PHASE {
		PHASE_ONLYFRAME,
		PHASE_INWINDOW,
		PHASE_INCREASE,
		PHASE_WAIT,
	};
private:
	NEXT update( );
	void drawFrame( );
	void drawHeaven( ); 
	void drawHuman( );  
	void drawDamn( );   
	void drawHungry( ); 
	void drawHell( );
	void drawWindow( );
	void drawNumber( int offset, int num, double alpha );
private:
	int _level;
	int _count;
	PHASE _phase;
	int _phase_count;
	int _population;
};

