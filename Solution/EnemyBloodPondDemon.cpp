#include "EnemyBloodPondDemon.h"

static const int CHIP_SIZE = 264;
static const int CHIP_FOOT = 0;
static const int HP = 10;
static const int POW = 2;
static const int WAIT_AINME_TIME = 10;

EnemyBloodPondDemon::EnemyBloodPondDemon( int x, int y ) :
Enemy( x, y, CHIP_SIZE, CHIP_FOOT, false, HP, POW ),
_action( ACTION_WAIT ),
_act_count( 0 ) {
}


EnemyBloodPondDemon::~EnemyBloodPondDemon( ) {
}

void EnemyBloodPondDemon::act( ) {
	updateChip( );
	_act_count++;
}

void EnemyBloodPondDemon::updateChip( ) {
	switch ( _action ) {
	case ACTION_WAIT:
		setChipGraph( GRAPH_ENEMY_BIG_2, 2, 4 );
		//ÇΩÇÎÇ∑ÇØÇ™ãﬂïtÇ¢ÇΩÇÁçUåÇÉÇÅ[ÉVÉáÉì
		//_action = ACTION_ATTACK;
		break;
	case ACTION_ATTACK:
		updateChipAttack( );
		break;
	}
}

void EnemyBloodPondDemon::updateChipAttack( ) {
	const int ANIME[ ] = { 0, 1, 0, 1, 0, 1, 2, 3, 2, 1 };
	int max_anime = sizeof( ANIME ) / sizeof( ANIME[ 0 ] );
	int u = ANIME[ _act_count / WAIT_AINME_TIME % max_anime ];
	int v = 4;
	setChipGraph( GRAPH_ENEMY_BIG_2, u, v );
}