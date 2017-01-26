#include "Enemy.h"
#include "Psychic.h"
#include "Camera.h"
#include "Sound.h" 

PTR( Psychic );

Enemy::Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_size, int chip_foot, bool mass, int hp, int pow ) :
Character( x, y, chip_size, chip_foot, mass ),
_enemy_stock( enemy_stock ),
_hp( hp ),
_pow( pow ),
_head( true ) {
}

Enemy::~Enemy( ) {
}

bool Enemy::isOverlapped( CharacterPtr target ) const {
	Vector vec = getOverlappedPos( ) - target->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

bool Enemy::isHead( ) const {
	return _head;
}

void Enemy::steppedOn( ) {

}

void Enemy::setNoHead( ) {
	_head = false;
}

EnemyStockPtr Enemy::getEnemyStock( ) {
	return _enemy_stock;
}

void Enemy::damage( int pow ) {
	if ( pow < 0 ) {
		_hp = 0;
	} else {
		_hp -= pow;
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "yokai_se_25.wav" );
	}
}

bool Enemy::isFinished( ) const {
	return _hp <= 0;
}

int Enemy::getPow( ) const {
	return _pow;
}

bool Enemy::isOutSideScreen( CameraConstPtr camera ) const {
	bool result = false;
	int dead_left_side = camera->getX( );
	int dead_right_side = dead_left_side + BG_SIZE * BG_NUM;
	int x = getX( );
	int y = getY( );
	int size = getSize( );
	if ( x + size / 2 < dead_left_side ||
		 x - size / 2 > dead_right_side ) {
		result = true;
	}
	if ( y - size < 0 ||
		 y > SCREEN_HEIGHT ) {
		result = true;
	}

	return result;
}
