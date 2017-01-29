#include "EnemyTree.h"
#include "EnemyGrowface.h"

static const int CHIP_SIZE = 384;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;
static const int HP  = 10;
static const int POW = 3;
static const int CREATE_COUNT_GRAW_FACE = 120;
static const int BORN_1_X = 20;
static const int BORN_1_Y = 110;
static const int BORN_2_X = -30;
static const int BORN_2_Y = 150;
static const int BORN_3_X = -40;
static const int BORN_3_Y = 70;
static const int BORN_4_X = -220;
static const int BORN_4_Y = 110;

EnemyTree::EnemyTree( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_TREE, 0, 0 );
	setChipReverse( false );
	_stock = stock;
}

EnemyTree::~EnemyTree( ) {
}

void EnemyTree::act( ) {
	_count++;
	if ( _count % CREATE_COUNT_GRAW_FACE == 0 ) {
		int x = getX( ) - BORN_1_X;
		int y = getY( ) - BORN_1_Y;
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( x, y ) ) );
	}
	if ( _count % CREATE_COUNT_GRAW_FACE == 30 ) {
		int x = getX( ) - BORN_2_X;
		int y = getY( ) - BORN_2_Y;
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( x, y ) ) );
	}
	if ( _count % CREATE_COUNT_GRAW_FACE == 60 ) {
		int x = getX( ) - BORN_3_X;
		int y = getY( ) - BORN_3_Y;
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( x, y ) ) );
	}
	if ( _count % CREATE_COUNT_GRAW_FACE == 90 ) {
		int x = getX( ) - BORN_4_X;
		int y = getY( ) - BORN_4_Y;
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( x, y ) ) );
	}
}

double EnemyTree::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTree::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}