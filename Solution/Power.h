#pragma once

class Power {
public:
	Power( );
	virtual ~Power( );
public:
	int get( ) const;
	void decrease( int pow );
private:
	int _value;
};

