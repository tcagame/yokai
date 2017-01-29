#include "PsychicMomotaro.h"
#include "Drawer.h"
#include "Camera.h"
#include "define.h"

static const int CHIP_SIZE = 128;
static const int RADIUS = 32;
static const double SPEED = 2.0;
static const double ACCEL = 0.1;

PsychicMomotaro::PsychicMomotaro( int x, int y, bool right ) :
Psychic( x, y ) {
	setPow( 1 );
	setChipSize( 0 );

	_pos = Vector( x, y );
	Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, 1 ), rand( ) % 1000 * PI2 / 1000 ); 

	int v = -1;
	if ( right ) {
		v = 1;
	}
	_vec = mat.multiply( Vector( 0, SPEED * v ) );
	_accel = Vector( ACCEL * v, 0 );
	
	for ( int j = 0; j < DIV_NUM; j++ ) {
		_vec += _accel;
		_vec = _vec.normalize( ) * SPEED;
		_pos += _vec;
	}
}

PsychicMomotaro::~PsychicMomotaro( ) {
}

void PsychicMomotaro::act( ) {
	if ( _pos.x < getRange( ) || _pos.x > getRange( ) + SCREEN_WIDTH ) {
		finish( );
	}

	for ( int j = 0; j < DIV_NUM; j++ ) {
		_vec += _accel;
		_vec = _vec.normalize( ) * SPEED;
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

		DrawerPtr drawer = Drawer::getTask( );
		Drawer::Transform trans( sx, sy, tx, ty, CHIP_SIZE, CHIP_SIZE, sx + draw_size, sy + draw_size );
		Drawer::Sprite sprite( trans, GRAPH_PSYCHIC, Drawer::BLEND_ADD, 0.1 );
		drawer->setSprite( sprite );
	}
}

Vector PsychicMomotaro::getOverlappedPos( ) const {
	return _pos;
}

double PsychicMomotaro::getOverlappedRadius( ) const {
	return RADIUS;
}
