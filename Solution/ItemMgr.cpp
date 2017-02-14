#include "ItemMgr.h"
#include "Item.h"


ItemMgr::ItemMgr( ) {
}


ItemMgr::~ItemMgr( ) {
}

void ItemMgr::update( ) {
	std::list< ItemPtr >::iterator it = _items.begin( );
	while ( it != _items.end( ) ) {
		ItemPtr item = *it;
		item->update( );
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