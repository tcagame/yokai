#pragma once

class Scene {
public:
	enum NEXT {
		NEXT_CONTINUE,
		NEXT_TITLE,
		NEXT_DEMO,
		NEXT_INFO,
		NEXT_SELECT_1PLAYER_DEVICE_0,
		NEXT_SELECT_2PLAYER_DEVICE_0,
		NEXT_SELECT_1PLAYER_DEVICE_1,
		NEXT_SELECT_2PLAYER_DEVICE_1,
		NEXT_STAGE,
		NEXT_STREET,
		NEXT_RETRY,
		NEXT_RESULT,
		NEXT_THANKS,
		NEXT_DEBUG_STREET_0,
		NEXT_DEBUG_STREET_1,
		NEXT_DEBUG_STREET_2,
		NEXT_DEBUG_STREET_3,
		NEXT_DEBUG_STREET_4,
		NEXT_DEBUG_STREET_TEST,
		NEXT_DEBUG_RESULT,
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT update( ) = 0;
};


