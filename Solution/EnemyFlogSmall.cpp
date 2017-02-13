#include "EnemyFlogSmall.h"
#include "Sound.h"

static const int CHIP_SIZE = 64;
static const int CHIP_FOOT = 0;
static const int HP = 2;
static const int POW = 3;
static const int WAIT_ANIME_TIME = 40;
static const int SMASHED_COUNT = 5;

EnemyFlogSmall::EnemyFlogSmall( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, true, HP, POW ),
_act_count( 0 ),
_smashed_count( 0 ) {
}


EnemyFlogSmall::~EnemyFlogSmall( ) {
}

void EnemyFlogSmall::steppedOn( ) {
	if ( _smashed_count == 0 ) {
		_smashed_count = 1;
	}
}

void EnemyFlogSmall::act( ) {
	if ( _smashed_count > 0 ) {
		_smashed_count++;
		setChipGraph( GRAPH_ENEMY_SMALL, 3, 2 );
		if ( _smashed_count > SMASHED_COUNT ) {
			damage( -1 );
		}
	} else {
		setAccelY( 3 );
		const int MAX_ANIME_PATTERN = 2;
		_act_count++;
		_act_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
		int pattern = _act_count / WAIT_ANIME_TIME;
		setChipGraph( GRAPH_ENEMY_SMALL, pattern, 2 );
	}

	if ( _act_count == 0 ) {
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_voice_07.wav" );
	}
}
