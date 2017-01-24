#pragma once

#include "smart_ptr.h"
#include "mathmatics.h"
#include <list>
#include <array>

PTR( Enemy );
PTR( Field );
PTR( Camera );
PTR( Tarosuke );
PTR( Momotaro );
PTR( EnemyStock );
PTR( Psychic );
PTR( Boss );
PTR( Map );

class EnemyManager : public std::enable_shared_from_this< EnemyManager > {
public:
	EnemyManager( MapConstPtr map );
	virtual ~EnemyManager( );
public:
	void update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro );
	void draw( CameraPtr camera );
	EnemyPtr getOverlappedEnemy( PsychicPtr pcychic );
	void clear( );
protected:
	void addEnemy( EnemyPtr enemy );
private:
	static const int BOMB_NUM = 20;
	struct Bomb {
		Vector pos;
		int count;
	};
private:
	void createByField( unsigned int enemy_data,  CameraConstPtr camera );
	void addBomb( const Vector& pos );
	void drawBomb( CameraConstPtr camera ) const;
	void updateBomb( );
private:
	std::list< EnemyPtr > _enemies;
	EnemyStockPtr _enemy_stock;
	std::array< Bomb, BOMB_NUM > _bombs;
	int _idx_bomb;
	BossPtr _boss;
};

