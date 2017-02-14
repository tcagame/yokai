#include "EnemyDeceasedFirst.h"
#include "Sound.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;

EnemyDeceasedFirst::EnemyDeceasedFirst( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ) {
	setNoHead( );
}

EnemyDeceasedFirst::~EnemyDeceasedFirst( ) {
}

void EnemyDeceasedFirst::act( ) {
	const int MAX_ANIME_PATTERN = 5;
	_count++;
	_count %= WAIT_ANIME_TIME * MAX_ANIME_PATTERN;
	int pattern = _count / WAIT_ANIME_TIME % ( MAX_ANIME_PATTERN - 1 );
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 13 );
	if ( ( getX( ) > getCameraX( ) + SCREEN_WIDTH / 2 - 10 ) &&
		 ( getX( ) < getCameraX( ) + SCREEN_WIDTH / 2 + 10 ) ) {
		SoundPtr sound = Sound::getTask( );
		if ( !sound->isPlayingSE( "yokai_voice_04.wav" ) ) {
			sound->playSE( "yokai_voice_04.wav", false );
		}
	}
}

void EnemyDeceasedFirst::damage( int pow ) {
}
