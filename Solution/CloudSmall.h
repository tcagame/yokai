#pragma once
#include "Cloud.h"

class CloudSmall : public Cloud {
public:
	CloudSmall( CloudManager::CLOUD_CHIP cloud_chip, int x, int y );
	virtual ~CloudSmall( );
	void draw( CameraPtr camera );
};
