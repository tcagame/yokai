#include "EnemyRedFlogSmall.h"
#include "Sound.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 3;
static const int WAIT_ANIME_TIME = 40;
static const int SMASHED_COUNT = 5;
static const int JUMP_POWER = -20;
static const int MOVE_SPEED = 5;

EnemyRedFlogSmall::EnemyRedFlogSmall( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_smashed_count( 0 ),
_time( 1 ){

}


EnemyRedFlogSmall::~EnemyRedFlogSmall() {
}

void EnemyRedFlogSmall::steppedOn( ) {
	if ( _smashed_count == 0 ) {
		_smashed_count = 1;
	}
}

void EnemyRedFlogSmall::act( ) {
	_time++;
	if ( _smashed_count > 0 ) {
		_smashed_count++;
		setChipGraph( GRAPH_ENEMY_SMALL, 3, 3 );
		if ( _smashed_count > SMASHED_COUNT ) {
			damage( -1 );
		}
	} else {
		const int MAX_ANIME_PATTERN = 2;
		_act_count++;
		_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
		int pattern = _act_count / WAIT_ANIME_TIME;
		setChipGraph( GRAPH_ENEMY_SMALL, pattern, 3 );
	}
	if ( isStanding( ) ) {
		setAccelX( 0 );
		if ( _time % 30 == 0 ) {
			setAccelY( JUMP_POWER );
			SoundPtr sound = Sound::getTask( );
			sound->playSE( "yokai_voice_05.wav" );
		}
	}
	if( !isStanding( ) ) {
		setAccelX( -MOVE_SPEED );
	}
}
