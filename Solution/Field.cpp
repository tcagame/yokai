#include "Field.h"
#include "Drawer.h"
#include "define.h"
#include "Camera.h"
#include "Map.h"
#include "CloudManager.h"

Field::Field( MapConstPtr map ) :
_map( map ) {
	_idx = -1;
	_x = 0;
	_y = -48; // 最終的にはカメラから取得
	
	//_clouds.push_back( CloudPtr( new CloudBig( 2200, 275 ) ) );
	//_clouds.push_back( CloudPtr( new CloudSmall( 2850, 275 ) ) );
	//_clouds.push_back( CloudPtr( new CloudSmall( 3250, 275 ) ) );
	//_clouds.push_back( CloudPtr( new CloudBig( 3500, 275 ) ) );
}


Field::~Field( ) {
}

void Field::update( CameraConstPtr camera ) {
	int idx = camera->getX( ) / BG_SIZE;
	if ( idx != _idx ) {
		_idx = idx;

		DrawerPtr drawer = Drawer::getTask( );

		for ( int i = 0; i < 3; i++ ) {
			drawer->unloadGraph( GRAPH_BG + i );
		}

		for ( int i = 0; i < 3; i++ ) {
			drawer->loadGraph( GRAPH_BG + i, _map->getFilename( _idx + i ) );
		}
	}

	_x = idx * BG_SIZE - camera->getX( );
	_y = -camera->getY( );
}

void Field::draw( ) const {
	drawBG( );
	drawChip( );
}

void Field::drawBG( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	
	for ( int i = 0; i < 3; i++ ) {
		Drawer::Sprite sprite( 
			Drawer::Transform( _x + i * BG_SIZE, _y ),
			GRAPH_BG + i );
		drawer->setSprite( sprite );
	}
}

void Field::drawChip( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < 3; i++ ) {
		int bg_idx = _idx + i;
		for ( int j = 0; j < MAPCHIP_NUM * MAPCHIP_NUM; j++ ) {
			bool b = _map->isChip( bg_idx, j );
			if ( !b ) {
				continue;
			}

			int x = _x + i * BG_SIZE + j % MAPCHIP_NUM * MAPCHIP_SIZE;
			int y = _y               + j / MAPCHIP_NUM * MAPCHIP_SIZE;
			Drawer::Sprite sprite( 
				Drawer::Transform( x, y ),
				GRAPH_MAPCHIPGUIDE );
			drawer->setSprite( sprite );
		}
	}
}

bool Field::isChip( int x, int y ) const {
	// mapクラスにチップと重なっているか確認する Map::isChipを使う

	if ( x < 0 || x >= _map->getLength( ) * BG_SIZE ||
		 y < 0 || y >= BG_SIZE ) {
		return false;
	}

	int bg_idx = x / BG_SIZE;
	int chip_idx = x % BG_SIZE / MAPCHIP_SIZE + y / MAPCHIP_SIZE * MAPCHIP_NUM; 

	return _map->isChip( bg_idx, chip_idx );
}

Field::Collision Field::getCollision( int src_x, int src_y, int dst_x, int dst_y ) const {
	Collision collision;
	collision.overlapped_x = false;
	collision.overlapped_y = false;
	collision.adjust_x = 0;
	collision.adjust_y = 0;
	
	if ( dst_y > src_y ) {
		if ( !isChip( src_x, src_y ) && isChip( dst_x, dst_y ) ) {
			collision.adjust_y = dst_y / MAPCHIP_SIZE * MAPCHIP_SIZE - 1;
			collision.overlapped_y = true;
		}
	}

	{
		if ( !isChip( src_x, src_y ) && isChip( dst_x, src_y ) ) {
			int dif = _x % MAPCHIP_SIZE;
			int x = dst_x / MAPCHIP_SIZE * MAPCHIP_SIZE;
			if ( dif < MAPCHIP_SIZE / 2 ) {
				x -= 1;
			} else {
				x += MAPCHIP_SIZE;
			}
			collision.adjust_x = x;
			collision.overlapped_x = true;
		}
	}

	return collision;
}

