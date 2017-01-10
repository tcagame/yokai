#pragma once

#include "smart_ptr.h"
#include "Task.h"
#include <string>

PTR( Game );
PTR( Scene );

class Game : public Task {
public:
	static std::string getTag( ) { return "GAME"; }
	static GamePtr getTask( );
public:
	Game( );
	virtual ~Game( );
	void update( );
private:
	ScenePtr _scene;
};

