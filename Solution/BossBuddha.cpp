#include "BossBuddha.h"
#include "EnemyFireball.h"

static const int OFFSET_X = 414;
static const int OFFSET_Y = 155;
static const int HP = 30;
static const int POW = 10;
static const int RADIUS = 100;
static const int SPEED = 5;
static const int CREATE_COUNT_FIREBALL = 10;

BossBuddha::BossBuddha( EnemyStockPtr stock, int x ) :
Boss( OFFSET_X + x, OFFSET_Y, 0, HP, POW ),
_stock( stock ),
_count( 0 ) {
	
}

BossBuddha::~BossBuddha( ) {
}

void BossBuddha::act( ) {
}

void BossBuddha::attack( ) {
	_count++;
	if ( _count % CREATE_COUNT_FIREBALL == 0 ) {
		Vector pos( getX( ) + rand( ) % SCREEN_WIDTH - SCREEN_WIDTH / 2, -32 );
		Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, -1 ), rand( ) % 1000 * PI / 2 / 1000 );
		Vector vec = mat.multiply( Vector( 0, SPEED ) );
		_stock->addEnemy( EnemyPtr( new EnemyFireball( pos, vec ) ) );
	}
}

double BossBuddha::getOverlappedRadius( ) const {
	return RADIUS;
}

