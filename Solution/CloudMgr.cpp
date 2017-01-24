#include "CloudMgr.h"
#include "Cloud.h"

CloudMgr::CloudMgr( ) {
	_clouds.push_back( CloudPtr( new Cloud( 2300, 250, true  ) ) );
	_clouds.push_back( CloudPtr( new Cloud( 2850, 250, false ) ) );
	_clouds.push_back( CloudPtr( new Cloud( 3250, 250, false ) ) );
	_clouds.push_back( CloudPtr( new Cloud( 3500, 250, true  ) ) );
}


CloudMgr::~CloudMgr( ) {

}

void CloudMgr::update( ) {
	std::list< CloudPtr >::iterator ite = _clouds.begin( );
	while ( ite != _clouds.end( ) ) {
		(*ite)->update( );
		ite++;
	}
}

void CloudMgr::draw( CameraConstPtr camera ) {
	std::list< CloudPtr >::iterator ite = _clouds.begin( );
	while ( ite != _clouds.end( ) ) {
		(*ite)->draw( camera );
		ite++;
	}
}

CloudPtr CloudMgr::getOnStanding( int src_x, int src_y, int dst_y ) {
	std::list< CloudPtr >::iterator ite = _clouds.begin( );
	CloudPtr standing_cloud = CloudPtr( );
	while ( ite != _clouds.end( ) ) {
		if ( (*ite)->isStanding( src_x, src_y, dst_y ) ) {
			standing_cloud = (*ite);
		}
		if ( standing_cloud ) {
			break;
		}
		ite++;
	}
	return standing_cloud;
}
