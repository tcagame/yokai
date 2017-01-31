#pragma once

class Scene {
public:
	enum NEXT {
		NEXT_CONTINUE,
		NEXT_TITLE,
		NEXT_DEMO,
		NEXT_SELECT_1PLAYER,
		NEXT_SELECT_2PLAYER,
		NEXT_STAGE,
		NEXT_STREET,
		NEXT_RESULT,
		NEXT_DEBUG_STREET_0,
		NEXT_DEBUG_STREET_1,
		NEXT_DEBUG_STREET_2,
		NEXT_DEBUG_STREET_3,
		NEXT_DEBUG_STREET_4,
		NEXT_DEBUG_STREET_TEST,
		NEXT_DEBUG_RESULT_1,
		NEXT_DEBUG_RESULT_2,
		NEXT_DEBUG_RESULT_3,
		NEXT_DEBUG_RESULT_4,
		NEXT_DEBUG_RESULT_5,
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT update( ) = 0;
};


