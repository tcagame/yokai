#include "EnemyTree.h"
#include "EnemyGrowface.h"

static const int CHIP_SIZE = 384;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;
static const int HP  = 10;
static const int POW = 3;
static const int CREATE_COUNT_GRAW_FACE = 60;

EnemyTree::EnemyTree( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_TREE, 0, 0 );
	setChipReverse( false );
}

EnemyTree::~EnemyTree( ) {
}

void EnemyTree::act( ) {
	_count++;
	if ( _count % CREATE_COUNT_GRAW_FACE == 0 ) {
		int x = getX( );
		int y = getY( );
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( x, y ) ) );
	}
}

double EnemyTree::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTree::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}