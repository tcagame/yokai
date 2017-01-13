#include "PsychicMgr.h"

PsychicMgr::PsychicMgr( ) {
	_psychic = PsychicPtr( new Psychic( ) );
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( ) {
	_psychic->update( );
}

void PsychicMgr::draw( ) {
	_psychic->draw( _x, _y, _right );
}

void PsychicMgr::shooting( int x, int y, bool right ) {
	_x = x;
	_y = y;
	_right = right;
}