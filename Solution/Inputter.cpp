#include "Inputter.h"
#include "Device.h"
#include "Application.h"
#include "Binary.h"

Inputter::Inputter( ) :
_device( Device::getTask( ) ),
_record_idx( 0 ),
_replay( false ) {
	for ( int i = 0; i < 2 * DATA_NUM; i++ ) {
		_record[ i ].dir_x = 100;
		_record[ i ].dir_y = 0;
		_record[ i ].button = BUTTON_C;
		_record[ i ].push   = 0;
		_record[ i ].push   = ( i % 40 == 0 ) * BUTTON_C;
	}
}

Inputter::~Inputter( ) {
}

void Inputter::load( const char * filename ) {
	_replay = true;

	BinaryPtr binary( new Binary );
	ApplicationPtr app = Application::getInstance( );
	app->loadBinary( filename, binary );
	binary->read( ( void * )_record, sizeof( _record ) );
}

void Inputter::save( const char * filename ) {
	BinaryPtr binary( new Binary );
	binary->ensure( sizeof( _record ) );
	binary->write( ( void * )_record, sizeof( _record ) );
	ApplicationPtr app = Application::getInstance( );
	app->saveBinary( filename, binary );
}

bool Inputter::isFinished( ) const {
	return _record_idx >= DATA_NUM;
}

void Inputter::update( ) {
	if ( _replay ) {
		if ( _record_idx < DATA_NUM ) {
			for ( int i = 0; i < 2; i++ ) {
				_data[ i ] = _record[ _record_idx * 2 + i ];
			}
			_record_idx++;
		} else {
			for ( int i = 0; i < 2; i++ ) {
				_data[ i ].dir_x = 100;
				_data[ i ].dir_y = 0;
				_data[ i ].button = rand( ) % 0x000f;
				_data[ i ].push   = rand( ) % 0x000f;
			}
		}
	} else {
		for ( int i = 0; i < 2; i++ ) {
			_data[ i ].dir_x  = _device->getDirX( i );
			_data[ i ].dir_y  = _device->getDirY( i );
			_data[ i ].button = _device->getButton( i );
			_data[ i ].push   = _device->getPush( i );
		}
	
		if ( _record_idx < DATA_NUM ) {
			_record[ _record_idx * 2 + 0 ] = _data[ 0 ];
			_record[ _record_idx * 2 + 1 ] = _data[ 1 ];
			_record_idx++;
		}
	}
}

char Inputter::getDirX( int idx ) const {
	return _data[ idx ].dir_x;
}

char Inputter::getDirY( int idx ) const {
	return _data[ idx ].dir_y;
}

unsigned char Inputter::getButton( int idx ) const {
	return _data[ idx ].button;
}

unsigned char Inputter::getPush( int idx ) const {
	return _data[ idx ].push;
}

