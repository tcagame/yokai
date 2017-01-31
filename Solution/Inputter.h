#pragma once

#include "smart_ptr.h"
#include "Device.h"

PTR( Device );

class Inputter {
public:
	Inputter( );
	virtual ~Inputter();
public:
	enum MODE {
		MODE_RECORD,
		MODE_REPLAY,
	};
public:
	void update( );
	char getDirX( int idx = 0 ) const;
	char getDirY( int idx = 0 ) const;
	unsigned char getButton( int idx = 0 ) const;
	unsigned char getPush( int idx = 0 ) const;
	bool isFinished( ) const;
	void load( const char * filename );
	void save( const char * filename );
private:
	struct Data {
		char dir_x;
		char dir_y;
		unsigned char button;
		unsigned char push;
	};
	static const int DATA_NUM = 5000;
private:
	DevicePtr _device;
	Data _data[ 2 ];
	Data _record[ 2 * DATA_NUM ];
	int _record_idx;
	bool _replay;
};

