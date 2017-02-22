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
	static const int DATA_NUM = 2000;
	struct Record {
		struct Data {
			char dir_x;
			char dir_y;
			unsigned char button;
			unsigned char push;
		};
		Data data[ 2 * DATA_NUM ];
		int controller;
	};
private:
	int getID( int idx ) const;
private:
	DevicePtr _device;
	Record::Data _now[ 2 ];
	Record _record;
	int _record_idx;
	bool _replay;
};

