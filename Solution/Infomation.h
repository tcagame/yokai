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
		unsigned int denominator; // ����@�`�������W�l��
		unsigned int numerator;   // ���q�@�����ŏI�������l��
		unsigned int history_x[ HISTORY_NUM ];
		unsigned int history_y[ HISTORY_NUM ];
		unsigned int history_idx;
	};
private:
	Data _data;
};

