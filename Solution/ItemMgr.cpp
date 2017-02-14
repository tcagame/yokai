#include "ItemMgr.h"
#include "Item.h"


ItemMgr::ItemMgr( ) {
}


ItemMgr::~ItemMgr( ) {
}

void ItemMgr::update( ) {

}

void ItemMgr::draw( CameraConstPtr camera ) const {

}

void ItemMgr::add( ItemPtr item ) {
	_items.push_back( item );
}