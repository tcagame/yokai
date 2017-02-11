#include "PsychicMomotaro.h"
#include "Drawer.h"
#include "Camera.h"
#include "define.h"

static const int CHIP_SIZE = 128;
static const int RADIUS = 32;
static const double SPEED = 1.5;
static const double ACCEL = 0.05;
static const int COUNT = 30;

PsychicMomotaro::PsychicMomotaro( const Vector& pos, const Vector& target ) :
Psychic( 0, 0 ),
_pos( pos ),
_target( target ) {
	setPow( 1 );
	setChipSize( 0 );

	_pos += ( pos - target ).normalize( ) * ( CHIP_SIZE / 4 );
	Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, 1 ), rand( ) % 1000 * PI2 / 1000 ); 
	_vec = mat.multiply( Vector( 0, SPEED ) );
	
	for ( int j = 0; j < DIV_NUM * 2; j++ ) {
		Vector v = _target - _pos;
		v = v.normalize( ) * ACCEL;
		_vec = ( _vec + v ).normalize( ) * SPEED;
		_pos += _vec;
	}

	_count = COUNT;
}

PsychicMomotaro::~PsychicMomotaro( ) {
}

void PsychicMomotaro::act( ) {
	if ( _pos.x < getRange( ) || _pos.x > getRange( ) + SCREEN_WIDTH ) {
		finish( );
	}

	_count--;
	if ( _count <= 0 ) {
		finish( );
	}

	for ( int j = 0; j < DIV_NUM; j++ ) {
		Vector v = _target - _pos;
		v = v.normalize( ) * ACCEL;
		_vec = ( _vec + v ).normalize( ) * SPEED;
		_pos += _vec;

		for ( int i = 0; i < TAIL_NUM - 1; i++ ) {
			_tails[ i ] = _tails[ i + 1 ];
		}
		_tails[ TAIL_NUM - 1 ] = _pos;
	}
}

void PsychicMomotaro::hit( bool killed ) {
	finish( );
}

void PsychicMomotaro::draw( CameraConstPtr camera, bool bright ) const {
	int tx = 0 * CHIP_SIZE;
	int ty = 3 * CHIP_SIZE;

	for ( int i = 0; i < TAIL_NUM; i++ ) {
		if ( _tails[ i ].isOrijin( ) ) {
			continue;
		}
		int draw_size = CHIP_SIZE * ( i + 1 ) / TAIL_NUM;
		int sx = ( int )_tails[ i ].x - camera->getX( ) - draw_size / 2;
		int sy = ( int )( _tails[ i ].y + sin( _tails[ i ].x / 30.0 ) * 10 ) - camera->getY( ) - draw_size / 2;
		double alpha = 0.1 * _count / ( COUNT / 5 );
		if ( alpha > 0.1 ) {
			alpha = 0.1;
		}
		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx + draw_size, sy + draw_size );
		Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, alpha );
		drawer->setSprite( sprite );
	}
}

Vector PsychicMomotaro::getOverlappedPos( ) const {
	return _pos;
}

double PsychicMomotaro::getOverlappedRadius( ) const {
	return RADIUS;
}
