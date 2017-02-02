#include "EnemyTree.h"
#include "EnemyGrowface.h"

static const int CHIP_SIZE = 512;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;
static const int HP  = 15;
static const int POW = 10;
static const int CREATE_COUNT_GRAW_FACE = 25;

static const int OFFSET_X = -257;
static const int OFFSET_Y = 10;
static const int FACE_NUM = 10;
static const int MX[ FACE_NUM ] {  24,  46,  45, 122, 217, 324, 354, 431, 496, 473 };
static const int MY[ FACE_NUM ] { 240, 320, 400, 389, 267, 214, 341, 352, 310, 230 };

EnemyTree::EnemyTree( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_TREE_BODY, 0, 0 );
	setChipReverse( false );
	_stock = stock;
	_create_idx = 0;
	focus( );
}

EnemyTree::~EnemyTree( ) {
}

void EnemyTree::act( ) {
	_count++;
	if ( _count % CREATE_COUNT_GRAW_FACE == 0 ) {
		_create_idx = ( _create_idx + 1 ) % FACE_NUM;
		int x = getX( ) + MX[ _create_idx ] + + OFFSET_X;
		int y = 0 + MY[ _create_idx ] + + OFFSET_Y;
		_stock->addEnemy( EnemyPtr( new EnemyGrowFace( shared_from_this( ), x, y ) ) );
	}
}

double EnemyTree::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTree::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}