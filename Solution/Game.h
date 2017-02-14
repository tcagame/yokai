#pragma once

#include "smart_ptr.h"
#include "Task.h"
#include "Scene.h"
#include <string>
#include <list>

PTR( Game );
PTR( Scene );
PTR( Power );

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
	bool isDemo( ) const;
	int getStage( ) const;
	void addDebugMessage( const char* string, ... );
	FADE getFade( ) const;
	void setFade( FADE fade );
	PowerPtr getPower( );
	bool isServer( ) const;
private:
	void fade( );
	void option( );
	void changeScene( );
private:
	ScenePtr _scene;
	PowerPtr _power;
	bool _server;
	bool _solo;
	bool _demo;
	int _stage;
	bool _debug;
	int _demo_count;
	FADE _fade;
	int _fade_count;
	std::list< std::string > _debug_message;
	Scene::NEXT _next;
	bool _info;
};

