#include "PsychicMgr.h"
#include "Psychic.h"
#include "define.h"

PsychicMgr::PsychicMgr( ) {
	_psychic = PsychicPtr( new Psychic( ) );
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( ) {
	_psychic->update( );
}

void PsychicMgr::draw( CameraConstPtr camera ) {
	_psychic->draw( camera );
}

void PsychicMgr::shooting( int x, int y, bool right ) {
	_psychic->shooting( x, y, right );
}