#pragma once
#include "CloudManager.h"

class Cloud {
public:
	enum CLOUD_CHIP {
		CLOUD_CHIP_0,
		CLOUD_CHIP_1,
		CLOUD_CHIP_2,
		CLOUD_CHIP_3
	};
public:
	Cloud( int x, int y );
	virtual ~Cloud( );
	virtual void draw( CameraPtr camera );
	void update( );
	void updatePos( );
	void updateChip( );
protected:
	int getX( );
	int getY( );
	CLOUD_CHIP getChip( );
private:
	CLOUD_CHIP _cloud_chip;
	int _x;
	int _y;
	int _chip_count;
};

