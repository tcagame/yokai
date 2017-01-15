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
	Cloud( int x, int y, const int WIDTH );
	virtual ~Cloud( );
	virtual void draw( CameraPtr camera );
	void update( );
	void updateAccel( );
	void moveVertical( );
	void updateChip( );
	virtual bool isExistence( int x, int y );
	int getX( );
	int getY( );
protected:
	CLOUD_CHIP getChip( );
private:
	CLOUD_CHIP _cloud_chip;
	int _x;
	int _y;
	int _accel;
	int _chip_count;
	int _turn_count;
	int _width;
};

