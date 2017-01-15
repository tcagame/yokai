#include "PsychicMgr.h"
#include "Psychic.h"
#include "PsychicMomotaro.h"
#include "define.h"

PsychicMgr::PsychicMgr( ) {
	_psychic = PsychicPtr( new Psychic );
	_psychic_momotaro = PsychicMomotaroPtr( new PsychicMomotaro ); 
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( ) {
	_psychic->update( );
	_psychic_momotaro->update( );
}

void PsychicMgr::draw( CameraConstPtr camera ) {
	_psychic->draw( camera );
	_psychic_momotaro->draw( camera );
}

void PsychicMgr::shooting( int x, int y, bool right ) {
	_psychic->shooting( x, y, right );
}