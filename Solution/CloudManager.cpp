#include "CloudManager.h"
#include "Cloud.h"
#include "Drawer.h"
#include "define.h"
#include "CloudBig.h"
#include "CloudSmall.h"
#include "define.h"

CloudManager::CloudManager( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CLOUD_SMALL, "cloud/Yokai_OBJ_cloud2.png" );
	drawer->loadGraph( GRAPH_CLOUD_BIG, "cloud/Yokai_OBJ_cloud1.png" ); 
	int x = 1900;
	int y = 300;
	_clouds.push_back( CloudPtr( new CloudSmall( x, y ) ) );
	x += 400;
	_clouds.push_back( CloudPtr( new CloudBig( x, y ) ) );
}

CloudManager::~CloudManager( ) {
}

void CloudManager::draw( CameraPtr camera ) {
	std::list< CloudPtr >::iterator it = _clouds.begin( );
	while ( it != _clouds.end( ) ) {
		(*it)->draw( camera );
		it++;
	}
}

void CloudManager::update( ) {
	std::list< CloudPtr >::iterator it = _clouds.begin( );
	while ( it != _clouds.end( ) ) {
		(*it)->update( );
		it++;
	}
}

bool CloudManager::isCloudExistence( int x, int y ) {
	bool result = false;
	std::list< CloudPtr >::iterator it = _clouds.begin( );
	while ( it != _clouds.end( ) ) {
		result = (*it)->isExistence( x, y );
		_cloud_overlapped = *it;
		if ( result ) {
			break;
		}
		it++;
	}
	return result;
}

CloudPtr CloudManager::getCloudPtr( ) const {
	if ( !_cloud_overlapped ) {
		return CloudPtr( );
	}
	return _cloud_overlapped;
}
