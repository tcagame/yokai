#include "ItemMgr.h"
#include "Item.h"
#include "Tarosuke.h"
#include "Camera.h"

ItemMgr::ItemMgr( ) {
}


ItemMgr::~ItemMgr( ) {
}

void ItemMgr::update( CameraConstPtr camera, TarosukePtr tarosuke ) {
	Vector pos = tarosuke->getOverlappedPos( );
	std::list< ItemPtr >::iterator it = _items.begin( );
	while ( it != _items.end( ) ) {
		ItemPtr item = *it;
		if ( item->update( pos ) ) {
			tarosuke->heal( );
			it = _items.erase( it );
			continue;
		}
		if ( item->isOutOfScreen( camera->getX( ) ) ) {
			it = _items.erase( it );
			continue;
		}

		it++;
	}
}

void ItemMgr::draw( CameraConstPtr camera ) const {
	std::list< ItemPtr >::const_iterator it = _items.begin( );
	while ( it != _items.end( ) ) {
		ItemPtr item = *it;
		item->draw( camera );
		it++;
	}
}

void ItemMgr::add( ItemPtr item ) {
	_items.push_back( item );
}