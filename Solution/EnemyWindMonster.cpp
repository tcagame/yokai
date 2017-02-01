#include "EnemyWindMonster.h"
#include "EnemyWindMonsterAttack.h"

static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP = 6;
static const int POW = 6;
static const int WAIT_ANIME_TIME = 5;
static const int MOVE_SPEED_X = 15;
static const int MOVE_SPEED_Y = 1;
static const int CREATE_INTERVAL = 13;

EnemyWindMonster::EnemyWindMonster( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_act_count( 0 ),
_stock( stock ) {
}


EnemyWindMonster::~EnemyWindMonster( ) {
}

void EnemyWindMonster::act( ) {
	setAccelX( -MOVE_SPEED_X );
	setAccelY( MOVE_SPEED_Y );
	const int WIDTH_NUM = 5;
	const int ANIME[ ] = {	0, 1, 2, 3, 4,
							5, 6, 7, 8, 9,
							8, 7, 6, 5, 4,
							3, 2, 1 };
	int anime_num = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int idx = _act_count / WAIT_ANIME_TIME % anime_num;
	int u = ANIME[ idx ] % WIDTH_NUM;
	int v = ANIME[ idx ] / WIDTH_NUM + 1;
	setChipGraph( GRAPH_ENEMY_BIG, u, v );
	if ( idx >= 6 ) {
		setAccelX( 0 );
		setAccelY( 0 );
		if ( idx >= 8 ) {
			if ( _act_count % CREATE_INTERVAL == 0 ) {
				_stock->addEnemy( EnemyPtr( new EnemyWindMonsterAttack( getX( ) - 50, getY( ) ) ) );
			}
		}
	}
	_act_count++;
}