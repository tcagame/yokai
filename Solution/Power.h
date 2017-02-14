#pragma once

class Power {
public:
	Power( );
	virtual ~Power( );
public:
	int get( ) const;
	void decrease( int pow );
	void reset( );
private:
	int _value;
};

