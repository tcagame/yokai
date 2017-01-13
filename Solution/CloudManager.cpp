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
	int interval =300;
	_clouds.push_back( CloudPtr( new CloudBig( CLOUD_CHIP::CLOUD_CHIP_0, x +   0, y ) ) );
	_clouds.push_back( CloudPtr( new CloudBig( CLOUD_CHIP::CLOUD_CHIP_1, x + interval, y + interval ) ) );
	_clouds.push_back( CloudPtr( new CloudBig( CLOUD_CHIP::CLOUD_CHIP_2, x + interval * 2, y ) ) );
	_clouds.push_back( CloudPtr( new CloudBig( CLOUD_CHIP::CLOUD_CHIP_3, x + interval * 3, y + interval ) ) );

	_clouds.push_back( CloudPtr( new CloudSmall( CLOUD_CHIP::CLOUD_CHIP_0, x + interval * 4, y ) ) );
	_clouds.push_back( CloudPtr( new CloudSmall( CLOUD_CHIP::CLOUD_CHIP_1, x + interval * 5, y + interval ) ) );
	_clouds.push_back( CloudPtr( new CloudSmall( CLOUD_CHIP::CLOUD_CHIP_2, x + interval * 6, y ) ) );
	_clouds.push_back( CloudPtr( new CloudSmall( CLOUD_CHIP::CLOUD_CHIP_3, x + interval * 7, y + interval ) ) );

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