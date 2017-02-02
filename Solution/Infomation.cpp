#include "Infomation.h"

Infomation::Infomation( ) {
	for ( int i = 0; i < HISTORY_NUM; i++ ) {
		_data.history_x[ i ] = i * 200;
		_data.history_y[ i ] = i % 256 + 128;
	}
	_data.history_idx = 0;
	_data.denominator = 1234567890;
	_data.numerator = 987654321;
}

Infomation::~Infomation( ) {
}


int Infomation::getProbability( ) const {
	return _data.numerator * 1000 / _data.denominator;
}

int Infomation::getNumerator( ) const {
	return _data.numerator;
}

void Infomation::increaseDenominator( ) {
	_data.denominator++;
}

void Infomation::increaseNumerator( ) {
	_data.numerator++;
}

void Infomation::setHistroy( int x, int y ) {
	_data.history_x[ _data.history_idx ] = x;
	_data.history_y[ _data.history_idx ] = y;
}

int Infomation::getHistoryX( int idx ) const {
	return _data.history_x[ idx ];
}

int Infomation::getHistoryY( int idx ) const {
	return _data.history_y[ idx ];
}