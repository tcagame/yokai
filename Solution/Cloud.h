#pragma once
#include "CloudManager.h"

class Cloud {
public:
	Cloud( CloudManager::CLOUD_CHIP cloud_chip, int x, int y );
	virtual ~Cloud( );
	virtual void draw( CameraPtr camera );
protected:
	int getX( );
	int getY( );
	CloudManager::CLOUD_CHIP getChip( );
private:
	CloudManager::CLOUD_CHIP _cloud_chip;
	int _x;
	int _y;
};

