#pragma once

class Infomation {
public:
	Infomation( );
	virtual ~Infomation();
public:
	static const int HISTORY_NUM = 1000;
public:
	int getProbability( int stage_idx ) const;
	int getNumerator( int stage_idx ) const;
	void increaseDenominator( int stage_idx );
	void increaseNumerator( int stage_idx );
	void setHistroy( int stage_idx, int x, int y );
	int getHistoryX( int stage_idx, int idx ) const;
	int getHistoryY( int stage_idx, int idx ) const;
	void increasePopulation( int result_idx );
	int getPopulation( int result_idx ) const;
private:
	struct Data {
		unsigned int denominator[ 5 ]; // 分母　チャレンジ人数 // 0 : 1面 4: 5面
		unsigned int numerator[ 5 ];   // 分子　ここで終了した人数
		unsigned int history_x[ 5 ][ HISTORY_NUM ];
		unsigned int history_y[ 5 ][ HISTORY_NUM ];
		unsigned int history_idx;
		unsigned int population[ 5 ]; // 0 :地獄　4:天界
	};
private:
	void save( );
	void load( );
private:
	Data _data;
};

