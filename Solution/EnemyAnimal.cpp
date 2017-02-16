#include "EnemyAnimal.h"

static const int MOVE_SPEED = 10;
static const int MAX_PATTERN = 4;
static const int WAIT_TIME = 25;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 0;
static const int RANGE = 80;
static const int JUMP_POWER = 30;

EnemyAnimal::EnemyAnimal( int x, int y, GRAPH graph ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ) {
	_graph = graph;
}

EnemyAnimal::~EnemyAnimal( ) {
}

void EnemyAnimal::act( ) {
	_act_count++;

	switch ( _action ) {
	case ACTION_STAND:
		actOnStanding( );
		break;
	case ACTION_YAWN:
		actOnYawning( );
		break;
	case ACTION_GROOM:
		actOnGrooming( );
		break;
	case ACTION_INTIMIDATE:
		actOnIntimidating( );
		break;
	case ACTION_FLOAT:
		actOnFloating( );
		break;
	}
}

void EnemyAnimal::actOnStanding( ) {
	setChipGraph( _graph, 1, 1 );

	if ( !isStanding( ) ) {
		_action = ACTION_FLOAT;
		_act_count = 0;
		return;
	}

	if ( getTargetY( ) < getY( ) - CHIP_SIZE ) {
		_action = ACTION_FLOAT;
		_act_count = 0;
		setAccelY( -JUMP_POWER );
		return;
	}

	setAccelX( 0 );
	int add = CHIP_SIZE + ( _graph == GRAPH_ENEMY_ANIMAL_CAT ) * CHIP_SIZE / 2;
	if ( getX( ) < getTargetX( ) - add ) {
		setAccelX( MOVE_SPEED );
	}
	if ( getX( ) > getTargetX( ) + add ) {
		setAccelX( -MOVE_SPEED );
	}
	if ( getAccelX( ) != 0 ) {
		const int MOTION[ 4 ] = { 0, 1, 2, 3 };
		int idx = _act_count / 5 % 4;
		int u = MOTION[ idx ] % 4;
		int v = MOTION[ idx ] / 4;
		setChipGraph( _graph, u, v );
	}

	switch ( rand( ) % 60 ) {
	case 0:
		_action = ACTION_GROOM;
		_act_count = 0;
		break;
	case 1:
		_action = ACTION_YAWN;
		_act_count = 0;
		break;
	case 2:
		_action = ACTION_INTIMIDATE;
		_act_count = 0;
		setAccelY( -JUMP_POWER / 2 );
		break;
		break;
	}
}

void EnemyAnimal::actOnYawning( ) {
	setAccelX( 0 );

	const int MOTION[ 7 ] = { 14, 15, 15, 15, 15, 15, 14 };
	int idx = _act_count / 5;
	int u = MOTION[ idx ] % 4;
	int v = MOTION[ idx ] / 4;
	setChipGraph( _graph, u, v );

	if ( idx == 7 - 1 ) {
		_action = ACTION_STAND;
	}
}

void EnemyAnimal::actOnGrooming( ) {
	setAccelX( 0 );

	const int MOTION[ 13 ] = { 4, 5, 6, 7, 8, 7, 8, 7, 8, 7, 6, 5, 4 };
	int idx = _act_count / 5;
	int u = MOTION[ idx ] % 4;
	int v = MOTION[ idx ] / 4;
	setChipGraph( _graph, u, v );

	if ( idx == 13 - 1 ) {
		_action = ACTION_STAND;
	}
}

void EnemyAnimal::actOnIntimidating( ) {
	const int MOTION[ 4 ] = { 9, 10, 11, 10 };
	int idx = _act_count / 5 % 4;
	int u = MOTION[ idx ] % 4;
	int v = MOTION[ idx ] / 4;
	setChipGraph( _graph, u, v );

	if ( isStanding( ) ) {
		_action = ACTION_STAND;
	}
}

void EnemyAnimal::actOnFloating( ) {
	setChipGraph( _graph, 0, 3 );
	if ( isStanding( ) ) {
		setChipGraph( _graph, 1, 3 );
		_action = ACTION_STAND;
	}

	setAccelX( 0 );
	if ( getX( ) < getTargetX( ) - CHIP_SIZE ) {
		setAccelX( MOVE_SPEED );
	}
	if ( getX( ) > getTargetX( ) + CHIP_SIZE ) {
		setAccelX( -MOVE_SPEED );
	}
}

void EnemyAnimal::damage( int pow ) {
}

Vector EnemyAnimal::getOverlappedPos( ) const {
	return Vector( -500, -500 );
}