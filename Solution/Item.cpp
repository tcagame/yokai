#include "Item.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;

Item::Item( int x, int y ) :
Character( x, y, CHIP_SIZE, CHIP_FOOT, fales ) {
}


Item::~Item()
{
}
