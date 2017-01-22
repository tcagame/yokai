#include "PsychicMgr.h"
#include "Psychic.h"
#include "Camera.h"
#include "Tarosuke.h"
#include "EnemyManager.h"
#include "Enemy.h"

PsychicMgr::PsychicMgr( ) {
}

PsychicMgr::~PsychicMgr( ) {
}

void PsychicMgr::update( CameraConstPtr camera, TarosukeConstPtr tarosuke, EnemyManagerPtr enemy_mgr ) {
	std::list< PsychicPtr >::iterator it = _psychics.begin( );
	while ( it != _psychics.end( ) ) {
		PsychicPtr psychic = *it;
		psychic->setRange( camera->getX( ), tarosuke->getX( ), tarosuke->getY( ) - 64 );
		psychic->update( FieldPtr( ) );

		if ( psychic->isFinished( ) ) {
			it = _psychics.erase( it );
			continue;
		}
		
		int pow = psychic->getPow( );
		if ( pow > 0 ) {
			EnemyPtr enemy = enemy_mgr->getOverlappedEnemy( psychic );
			if ( enemy ) {
				psychic->hit( );
				enemy->damage( pow );
			}
		}

		it++;
	}
}

void PsychicMgr::draw( CameraConstPtr camera ) const {
	std::list< PsychicPtr >::const_iterator it = _psychics.begin( );
	while ( it != _psychics.end( ) ) {
		PsychicPtr psychic = *it;
		psychic->draw( camera, true );
		it++;
	}
}

void PsychicMgr::shoot( PsychicPtr psychic ) {
	_psychics.push_back( psychic );
}
