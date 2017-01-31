#include "EnemyRockMassShell.h"
#include "EnemyStoneMortgage.h"
#include "EnemyRockMassSoul.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 20;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;

EnemyRockMassShell::EnemyRockMassShell( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ) {
}

EnemyRockMassShell::~EnemyRockMassShell( ) {
}

void EnemyRockMassShell::act( ) {
	const int ANIME[ ] = { 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 5 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ WAIT_ANIME_TIME % anime_num ];
	int v = 5;
	setChipGraph( GRAPH_ENEMY_ROCKMASS, u, v );
}

void EnemyRockMassShell::damage( int pow ) {
}