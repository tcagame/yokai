#include "Enemy.h"
#include "Psychic.h"
#include "Camera.h"
#include "Sound.h" 

PTR( Psychic );

Enemy::Enemy( int x, int y, int chip_size, int chip_foot, bool mass, int hp, int pow ) :
Character( x, y, chip_size, chip_foot, mass ),
_hp( hp ),
_pow( pow ),
_head( true ),
_focus( false ) {
}

Enemy::~Enemy( ) {
}

void Enemy::focus( ) {
	_focus = true;
}

bool Enemy::isFocus( ) const {
	return _focus;
}

void Enemy::setTarget( int x, int y ) {
	_target_x = x;
	_target_y = y;
}

int Enemy::getTargetX( ) const {
	return _target_x;
}

int Enemy::getTargetY( ) const {
	return _target_y;
}

bool Enemy::isOverlapped( CharacterPtr target ) const {
	Vector vec = getOverlappedPos( ) - target->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

void Enemy::setCameraX( int x ) {
	_camera_x = x;
}

int Enemy::getCameraX( ) const {
	return _camera_x;
}

bool Enemy::isHead( ) const {
	return _head;
}

void Enemy::steppedOn( ) {

}

void Enemy::setNoHead( ) {
	_head = false;
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
	int left  = camera->getX( ) - BG_SIZE;
	int right = camera->getX( ) + BG_SIZE * ( BG_NUM + 1 );
	int x = getX( );
	int y = getY( );
	int size = getSize( );

	bool result = false;
	if ( x < left ||
		 x > right ) {
		result = true;
	}
	if ( y < -size ||
		 y > SCREEN_HEIGHT + size * 2 ) {
		result = true;
	}

	return result;
}

int Enemy::getHp( ) {
	return _hp;
}