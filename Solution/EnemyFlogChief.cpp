#include "EnemyFlogChief.h"
#include "EnemyRedFlogSmall.h"

static const int WAIT_ANIME_TIME = 3;
static const int CHIP_SIZE = 256;
static const int CHIP_FOOT = 0;
static const int HP  = 30;
static const int POW = 6;
static const int MAX_ANIME_PATTERN = 9;
static const int CREATE_COUNT_FLOG = 30;
static const int SPEED = 5;
static const int ACCEL = 10;
static const int MAX_RAND = 500;


EnemyFlogChief::EnemyFlogChief( EnemyStockPtr stock, int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_anime_count( 0 ),
_stock( stock ){
}

EnemyFlogChief::~EnemyFlogChief( ) {
}

void EnemyFlogChief::act( ) {
	_anime_count++;
	_anime_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	const int MOTION[ 9 ] = {  0, 0, 0, 0, 1, 2, 3, 2, 3 };
	int u = MOTION[ ( _anime_count / WAIT_ANIME_TIME ) % MAX_ANIME_PATTERN ];

	if ( _anime_count % CREATE_COUNT_FLOG == 0 ) {
		EnemyPtr enemy = EnemyPtr( new EnemyRedFlogSmall( getX( ) - rand( ) % MAX_RAND + MAX_RAND / 3, 100 ) );
		_stock->addEnemy( enemy );
	}

	setChipGraph( GRAPH_ENEMY_FLOG_RED, u, 0 );
}