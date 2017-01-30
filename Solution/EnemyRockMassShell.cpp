#include "EnemyRockMassShell.h"
#include "EnemyStoneMortgage.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 20;
static const int POW = 1;
static const int WAIT_ANIME_TIME = 10;

EnemyRockMassShell::EnemyRockMassShell( EnemyStockPtr enemy_stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
	_martgage = EnemyStoneMortgagePtr( new EnemyStoneMortgage( x, y ) );
	enemy_stock->addEnemy( ( EnemyPtr )_martgage );
}


EnemyRockMassShell::~EnemyRockMassShell( ) {
}

void EnemyRockMassShell::act( ) {
	const int ANIME[ ] = { 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 5 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 5;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );

	_martgage->setMove( false );
	if ( _act_count / WAIT_ANIME_TIME % anime_num > anime_num / 2 ) {
		_martgage->setMove( true );
	}
	if ( _act_count / WAIT_ANIME_TIME % anime_num > anime_num * 3 / 4 ) {
		_martgage->back( );
	}

	_act_count++;
}

void EnemyRockMassShell::damage( int pow ) {
}