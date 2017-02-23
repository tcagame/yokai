#include "EnemyDeceasedFirst.h"
#include "Sound.h"

static const int WAIT_ANIME_TIME = 6;
static const int CHIP_SIZE = 128;
static const int CHIP_FOOT = 0;
static const int HP  = 2;
static const int POW = 6;

EnemyDeceasedFirst::EnemyDeceasedFirst( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_count( 0 ),
_talked( false ) {
	setNoHead( );
}

EnemyDeceasedFirst::~EnemyDeceasedFirst( ) {
}

void EnemyDeceasedFirst::act( ) {
	const int ANIM[ 8 ] = { 0, 1, 2, 3, 4, 3, 2, 1 };
	_count++;
	int pattern = _count / WAIT_ANIME_TIME % 8;
	setChipGraph( GRAPH_ENEMY_NORMAL, pattern, 13 );
	if ( ( getX( ) > getCameraX( ) + SCREEN_WIDTH / 3 * 2 - 10 ) &&
		 ( getX( ) < getCameraX( ) + SCREEN_WIDTH / 3 * 2 + 10 ) ) {
		if ( !_talked ) {
			SoundPtr sound = Sound::getTask( );
			sound->playSE( "yokai_voice_04.wav", false );
			_talked = true;
		}
	}
}

void EnemyDeceasedFirst::damage( int pow ) {
}
