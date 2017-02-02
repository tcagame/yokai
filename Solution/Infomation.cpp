#include "Infomation.h"
#include "Binary.h"
#include "Application.h"

const char * FILENAME = "record/information";

Infomation::Infomation( bool loading ) {
	for ( int j = 0; j < 5; j++ ) {
		for ( int i = 0; i < HISTORY_NUM; i++ ) {
			_data.history_x[ j ][ i ] = 0;
			_data.history_y[ j ][ i ] = 0;
		}
		_data.history_idx = 0;

		_data.denominator[ j ] = 0;
		_data.numerator[ j ] = 0;
		_data.population[ j ] = 0;
	}

	if ( loading ) {
		load( );
	}
}

Infomation::~Infomation( ) {
	save( );
}

void Infomation::load( ) {
	BinaryPtr binary( new Binary );
	ApplicationPtr app = Application::getInstance( );
	app->loadBinary( FILENAME, binary );
	binary->read( ( void * )&_data, sizeof( _data ) );
}

void Infomation::save( ) {
	BinaryPtr binary( new Binary );
	binary->ensure( sizeof( _data ) );
	binary->write( ( void * )&_data, sizeof( _data ) );
	ApplicationPtr app = Application::getInstance( );
	app->saveBinary( FILENAME, binary );
}

int Infomation::getProbability( int stage_idx ) const {
	if ( _data.denominator[ stage_idx ] == 0 ) {
		return 0;
	}
	return _data.numerator[ stage_idx ] * 1000 / _data.denominator[ stage_idx ];
}

int Infomation::getNumerator( int stage_idx ) const {
	return _data.numerator[ stage_idx ];
}

void Infomation::increaseDenominator( int stage_idx ) {
	_data.denominator[ stage_idx ]++;
}

void Infomation::increaseNumerator( int stage_idx ) {
	_data.numerator[ stage_idx ]++;
}

void Infomation::setHistroy( int stage_idx, int x, int y ) {
	_data.history_idx = ( _data.history_idx + 1 ) % HISTORY_NUM;
	_data.history_x[ stage_idx ][ _data.history_idx ] = x;
	_data.history_y[ stage_idx ][ _data.history_idx ] = y;
}

int Infomation::getHistoryX( int stage_idx, int idx ) const {
	if ( idx == _data.history_idx ) {
		return 0;
	}
	idx = ( idx + _data.history_idx ) % HISTORY_NUM;
	return _data.history_x[ stage_idx ][ idx ];
}

int Infomation::getHistoryY( int stage_idx, int idx ) const {
	if ( idx == _data.history_idx ) {
		return 0;
	}
	idx = ( idx + _data.history_idx ) % HISTORY_NUM;
	return _data.history_y[ stage_idx ][ idx ];
}

void Infomation::increasePopulation( int result_idx ) {
	_data.population[ result_idx ]++;
}

int Infomation::getPopulation( int result_idx ) const {
	return _data.population[ result_idx ];
}