#include "Inputter.h"
#include "Device.h"
#include "Application.h"
#include "Binary.h"
#include "Game.h"

Inputter::Inputter( ) :
_device( Device::getTask( ) ),
_record_idx( 0 ),
_replay( false ) {
	for ( int i = 0; i < 2 * DATA_NUM; i++ ) {
		_record.data[ i ].dir_x = 100;
		_record.data[ i ].dir_y = 0;
		_record.data[ i ].button = BUTTON_C;
		_record.data[ i ].push   = 0;
		_record.data[ i ].push   = ( i % 40 == 0 ) * BUTTON_C;
	}

	GamePtr game = Game::getTask( );
	_record.controller = game->getController( );
}

Inputter::~Inputter( ) {
}

void Inputter::load( const char * filename ) {
	_replay = true;

	BinaryPtr binary( new Binary );
	ApplicationPtr app = Application::getInstance( );
	if ( app->loadBinary( filename, binary ) ) {
		binary->read( ( void * )&_record, sizeof( Record ) );
	}
}

void Inputter::save( const char * filename ) {
	BinaryPtr binary( new Binary );
	binary->ensure( sizeof( Record ) );
	binary->write( ( void * )&_record, sizeof( Record ) );
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
				_now[ i ] = _record.data[ _record_idx * 2 + i ];
			}
			_record_idx++;
		} else {
			for ( int i = 0; i < 2; i++ ) {
				_now[ i ].dir_x = 100;
				_now[ i ].dir_y = 0;
				_now[ i ].button = rand( ) % 0x000f;
				_now[ i ].push   = rand( ) % 0x000f;
			}
		}
	} else {
		for ( int i = 0; i < 2; i++ ) {
			_now[ i ].dir_x  = _device->getDirX( i );
			_now[ i ].dir_y  = _device->getDirY( i );
			_now[ i ].button = _device->getButton( i );
			_now[ i ].push   = _device->getPush( i );
		}
	
		if ( _record_idx < DATA_NUM ) {
			_record.data[ _record_idx * 2 + 0 ] = _now[ 0 ];
			_record.data[ _record_idx * 2 + 1 ] = _now[ 1 ];
			_record_idx++;
		}
	}
}

char Inputter::getDirX( int idx ) const {
	return _now[ getID( idx ) ].dir_x;
}

char Inputter::getDirY( int idx ) const {
	return _now[ getID( idx ) ].dir_y;
}

unsigned char Inputter::getButton( int idx ) const {
	return _now[ getID( idx ) ].button;
}

unsigned char Inputter::getPush( int idx ) const {
	return _now[ getID( idx ) ].push;
}

int Inputter::getID( int idx ) const {
	return ( idx + _record.controller ) % 2;
}
