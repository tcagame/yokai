#pragma once

#include "Boss.h"

class BossEnma : public Boss {
public:
	BossEnma( EnemyStockPtr stock, int x );
	virtual ~BossEnma( );
private:
	void act( );
	void attack( );
	void updateChip( );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
	int _anime_count;
	int _attack_count;
};
