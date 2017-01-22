#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Field );
PTR( Camera );
PTR( Tarosuke );
PTR( Momotaro );
PTR( EnemyStock );
PTR( PsychicTarosuke );
PTR( PsychicMomotaro );

class EnemyManager : public std::enable_shared_from_this< EnemyManager > {
public:
	EnemyManager( );
	virtual ~EnemyManager( );
	void update( FieldPtr field, CameraConstPtr camera, TarosukePtr tarosuke, MomotaroPtr momotaro );
	void draw( CameraPtr camera );
	bool isOutSideScreenEnemy( EnemyPtr enemy, CameraConstPtr camera );
	std::list< EnemyPtr > getEnemyList( );
protected:
	void addEnemy( EnemyPtr enemy );
private:
	void createByField( unsigned int enemy_data,  CameraConstPtr camera );
private:
	std::list< EnemyPtr > _enemies;
	EnemyStockPtr _enemy_stock;
};

