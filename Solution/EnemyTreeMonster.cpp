#include "EnemyTreeMonster.h"
#include "EnemyBranchMonster.h"



static const int CHIP_SIZE = 512;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;
static const int HP  = 20;
static const int POW = 12;
static const int CREATE_COUNT_BRANCH = 50;
static const int BORN_1_X = -130;
static const int BORN_1_Y = -50;


EnemyTreeMonster::EnemyTreeMonster( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_TREE_MONSTER_BODY, 0, 0 );
	setChipReverse( false );
	_stock = stock;
	focus( );
	setNoHead( );
}


EnemyTreeMonster::~EnemyTreeMonster( ) {

}

void EnemyTreeMonster::act( ) {	
	_count++;
	x = getX( ) + BORN_1_X;
	y = getY( ) + BORN_1_Y;
	if ( _count % CREATE_COUNT_BRANCH == 30 ) {
		_stock->addEnemy( EnemyPtr( new EnemyBranchMonster( _stock, x, y ) ) );
	}
}

double EnemyTreeMonster::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTreeMonster::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}