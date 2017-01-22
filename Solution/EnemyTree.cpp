#include "EnemyTree.h"

static const int CHIP_SIZE = 384;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;

EnemyTree::EnemyTree( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( enemy_stock, x, y, GRAPH_ENEMY_TREE, CHIP_SIZE, CHIP_FOOT ) {
}

EnemyTree::~EnemyTree( ) {
}

void EnemyTree::act( ) {
}

double EnemyTree::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTree::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}