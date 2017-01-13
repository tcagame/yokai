#pragma once
#include "Cloud.h"

class CloudBig : public Cloud {
public:
	CloudBig( CloudManager::CLOUD_CHIP cloud_chip, int x, int y );
	virtual ~CloudBig( );
	void draw( CameraPtr Camera );
};

