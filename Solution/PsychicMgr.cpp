#include "PsychicMgr.h"
#include "Psychic.h"
#include "Camera.h"
#include "Tarosuke.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Drawer.h"

static const int IMPACT_COUNT = 8;
static const int IMPACT_SIZE = 128;

PsychicMgr::PsychicMgr( ) {
	for ( int i = 0; i < IMPACT_NUM; i++ ) {
		_impact[ i ].count = IMPACT_COUNT;
	}
	_idx_impact = 0;
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
				if ( !enemy->isFinished( ) ) {
					addImpact( psychic->getOverlappedPos( ) );
				}
			}
		}

		it++;
	}

	updateImpact( );
}

void PsychicMgr::draw( CameraConstPtr camera ) const {
	std::list< PsychicPtr >::const_iterator it = _psychics.begin( );
	while ( it != _psychics.end( ) ) {
		PsychicPtr psychic = *it;
		psychic->draw( camera, true );
		it++;
	}

	drawImpact( camera );
}

void PsychicMgr::shoot( PsychicPtr psychic ) {
	_psychics.push_back( psychic );
}

void PsychicMgr::addImpact( const Vector& pos ) {
	_impact[ _idx_impact ].pos = pos;
	_impact[ _idx_impact ].count = 0;
	_idx_impact = ( _idx_impact + 1 ) % IMPACT_NUM;
}

void PsychicMgr::updateImpact( ) {
	for ( int i = 0; i < IMPACT_NUM; i++ ) {
		_impact[ i ].count++;
	}
}

void PsychicMgr::drawImpact( CameraConstPtr camera ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < IMPACT_NUM; i++ ) {
		int idx = ( _idx_impact + i ) % IMPACT_NUM;
		if ( _impact[ idx ].count >= IMPACT_COUNT ) {
			continue;
		}
		int pattern = _impact[ idx ].count / ( IMPACT_COUNT / 4 );
		int tx = pattern % 2 * IMPACT_SIZE;
		int ty = pattern / 2 * IMPACT_SIZE;

		int sx = ( int )_impact[ idx ].pos.x - camera->getX( ) - IMPACT_SIZE / 2;
		int sy = ( int )_impact[ idx ].pos.y - camera->getY( ) - IMPACT_SIZE / 2;

		Drawer::Transform trans( sx, sy, tx, ty, IMPACT_SIZE, IMPACT_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_IMPACT, Drawer::BLEND_ADD, 1.0 );
		drawer->setSprite( sprite );
	}
}
