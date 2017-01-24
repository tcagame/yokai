#pragma once

#include "smart_ptr.h"
#include "Task.h"
#include "Scene.h"
#include <string>
#include <list>

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
	enum FADE {
		FADE_IN,
		FADE_NONE,
		FADE_OUT,
		FADE_COVER,
	};
public:
	void update( );
	void initialize( );
	bool isDebug( ) const;
	bool isSolo( ) const;
	int getStage( ) const;
	void addDebugMessage( const char* string, ... );
	FADE getFade( ) const;
	void setFade( FADE fade );
private:
	void fade( );
	void option( );
	void changeScene( Scene::NEXT next );
private:
	ScenePtr _scene;
	bool _solo;
	int _stage;
	bool _debug;
	FADE _fade;
	int _fade_count;
	std::list< std::string > _debug_message;
};

