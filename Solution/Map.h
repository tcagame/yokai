#pragma once

static const int MAX_STRING = 20;

class Map {
public:
	Map( );
	virtual ~Map( );
	virtual const char * getBGFilename( int idx ) const = 0;
};
