#pragma once

class Scene {
public:
	enum NEXT {
		NEXT_CONTINUE,
		NEXT_TITLE,
		NEXT_STREET_1PLAYER,
		NEXT_STREET_2PLAYER,
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT update( ) = 0;
};


