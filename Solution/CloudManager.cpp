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
	int x = 0;
	int y = 0;
	_clouds.push_back( CloudPtr( new CloudSmall( x, y ) ) );
	x = 300;
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