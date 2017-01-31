#include "EnemyHandMonster.h"
#include "EnemyHandMonsterAttack.h"

static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 6;
static const int WAIT_APPEAR_TIME = 50;
static const int WAIT_ANIME_TIME = 3;
static const int ATTACK_FOOT = 30;

EnemyHandMonster::EnemyHandMonster( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_stock( stock ),
_act_count( 0 ),
_action( ACTION_WAIT ) {
	setChipReverse( true );
}


EnemyHandMonster::~EnemyHandMonster( ) {
}

void EnemyHandMonster::act( ) {
	int u = 0;
	int v = 0;
	switch( _action ) {
	case ACTION_WAIT:
		actWait( );
		break;
	case ACTION_THROW:
		actThrow( );
		break;
	}


	_act_count++;
}

void EnemyHandMonster::actWait( ) {
	if ( _act_count > WAIT_APPEAR_TIME ) {
		_action = ACTION_THROW;
		_act_count = 0;
	}
}

void EnemyHandMonster::actThrow( ) {
	const int ANIME[ ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_ANIME_TIME % anime_num ];
	int v = 0;
	setChipGraph( GRAPH_ENEMY_NORMAL, u, v );

	if ( u == 10 ) {
		if ( _act_count % WAIT_ANIME_TIME == 0 ) {
			_stock->addEnemy( EnemyPtr( new EnemyHandMonsterAttack( getX( ), getY( ) - ATTACK_FOOT ) ) );
		}
	}
	if ( u == 0 ) {
		setAccelY( -1000 );
	}
}