#include "CloudMgr.h"
#include "Cloud.h"
#include "Map.h"

CloudMgr::CloudMgr( ) {
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

void CloudMgr::add( CloudPtr cloud ) {
	_clouds.push_back( cloud );
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