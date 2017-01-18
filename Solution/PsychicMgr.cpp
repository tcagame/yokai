#include "PsychicMgr.h"
#include "Psychic.h"
#include "Camera.h"
#include "PsychicNormal.h"

PsychicMgr::PsychicMgr( CameraConstPtr camera ) :
_camera( camera ) {
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( ) {
	std::list< PsychicPtr >::iterator it = _psychics.begin( );
	while ( it != _psychics.end( ) ) {
		PsychicPtr psychic = *it;
		psychic->setRange( _camera->getX( ) );
		psychic->update( FieldPtr( ) );
		it++;
	}
}

void PsychicMgr::draw( CameraConstPtr camera ) {
	std::list< PsychicPtr >::iterator it = _psychics.begin( );
	while ( it != _psychics.end( ) ) {
		PsychicPtr psychic = *it;
		psychic->draw( camera );
		it++;
	}
}

void PsychicMgr::shoot( int x, int y, bool reverse ) {
	_psychics.push_back( PsychicPtr( new PsychicNormal( x, y, reverse ) ) );
}