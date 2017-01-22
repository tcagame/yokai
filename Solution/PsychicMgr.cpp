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
		EnemyPtr overlapped = getOverlappedEnemy( psychic, enemy_mgr );
		if ( overlapped ) {
			overlapped->damage( );
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

EnemyPtr PsychicMgr::getOverlappedEnemy( PsychicPtr pcychic, EnemyManagerPtr enemy_mgr ) {
	std::list< EnemyPtr > enemies = enemy_mgr->getEnemyList( );
	std::list<EnemyPtr>::iterator ite = enemies.begin( );
	EnemyPtr overlapped = EnemyPtr( );

	while ( ite != enemies.end( ) ) {
		if ( (*ite)->isOverlapped( pcychic ) ) {
			overlapped = (*ite);
			break;
		}
		ite++;
	}
	return overlapped;
}