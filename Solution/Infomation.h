#pragma once

class Infomation {
public:
	Infomation();
	virtual ~Infomation();
public:
	static const int HISTORY_NUM = 1000;
public:
	int getProbability( ) const;
	int getNumerator( ) const;
	void increaseDenominator( );
	void increaseNumerator( );
	void setHistroy( int x, int y );
	int getHistoryX( int idx ) const;
	int getHistoryY( int idx ) const;
private:
	struct Data {
		unsigned int denominator; // 分母　チャレンジ人数
		unsigned int numerator;   // 分子　ここで終了した人数
		unsigned int history_x[ HISTORY_NUM ];
		unsigned int history_y[ HISTORY_NUM ];
		unsigned int history_idx;
	};
private:
	Data _data;
};

