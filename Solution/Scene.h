#pragma once

class Scene {
public:
	enum NEXT {
		NEXT_CONTINUE,
		NEXT_TITLE,
		NEXT_SELECT_1PLAYER,
		NEXT_SELECT_2PLAYER,
		NEXT_STAGE,
		NEXT_STREET,
		NEXT_RESULT,
		NEXT_DEBUG_0,
		NEXT_DEBUG_1,
		NEXT_DEBUG_2,
		NEXT_DEBUG_3,
		NEXT_DEBUG_4,
		NEXT_DEBUG_TEST,
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT update( ) = 0;
};


