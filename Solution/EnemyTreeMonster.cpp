#include "EnemyTreeMonster.h"
#include "EnemyBranchMonster.h"


static const int CHIP_SIZE = 512;
static const int CHIP_FOOT = 10;
static const int GRAPH_HEIGHT = 256;
static const int HP  = 10;
static const int POW = 3;
static const int CREATE_COUNT_GRAW_FACE = 120;
static const int BORN_1_X = -130;
static const int BORN_1_Y = -50;


EnemyTreeMonster::EnemyTreeMonster( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
	setChipGraph( GRAPH_ENEMY_TREE_2, 0, 0 );
	setChipReverse( false );
	x = getX( ) + BORN_1_X;
	y = getY( ) + BORN_1_Y;
	stock->addEnemy( EnemyPtr( new EnemyBranchMonster( x, y ) ) );
}


EnemyTreeMonster::~EnemyTreeMonster( ) {

}

void EnemyTreeMonster::act( ) {
}

double EnemyTreeMonster::getOverlappedRadius( ) const {
	return GRAPH_HEIGHT / 2 * 0.8;
}

Vector EnemyTreeMonster::getOverlappedPos( ) const {
	return Vector( getX( ), getY( ) + CHIP_FOOT - GRAPH_HEIGHT / 2 );
}