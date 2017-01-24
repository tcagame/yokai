#pragma once

class Scene {
public:
	enum NEXT {
		NEXT_CONTINUE,
		NEXT_TITLE,
		NEXT_SELECT_1PLAYER,
		NEXT_SELECT_2PLAYER,
		NEXT_GATE,
		NEXT_STREET,
		NEXT_TEST,
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT update( ) = 0;
};


