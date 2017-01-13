#include "PsychicMgr.h"
#include "Psychic.h"
#include "Camera.h"
#include "define.h"

PsychicMgr::PsychicMgr( ) {
	_psychic = PsychicPtr( new Psychic( ) );
	_x = -CHIP_SIZE;
	_y = -CHIP_SIZE;
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( ) {
	_psychic->update( );
}

void PsychicMgr::draw( CameraConstPtr camera ) {
	_psychic->draw( _x - camera->getX( ) - CHIP_SIZE / 2, _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK, _right );
}

void PsychicMgr::shooting( int x, int y, bool right ) {
	_x = x;
	_y = y;
	_right = right;
}