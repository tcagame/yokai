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
public:
	void update( );
	void initialize( );
	bool isDebug( ) const;
	bool isSolo( ) const;
	int getStage( ) const;
private:
	ScenePtr _scene;
	bool _solo;
	int _stage;
	bool _debug;
};

