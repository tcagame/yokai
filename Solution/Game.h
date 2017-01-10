#pragma once
#include "smart_ptr.h"
#include "Task.h"
#include <string>

PTR( Game );
PTR( Tarosuke );
PTR( ChipDrawer );

class Game : public Task {
public:
	static std::string getTag( ) { return "GAME"; }
	static GamePtr getTask( );
public:
	Game( );
	virtual ~Game( );
	void update( );
	void draw( );
private:
	TarosukePtr _tarosuke;
	ChipDrawerPtr _chip_drawer;
};

