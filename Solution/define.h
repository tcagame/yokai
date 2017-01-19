#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 768;
const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;
const int CHIP_FOOT_BLANK = 25;

enum GRAPH {
	GRAPH_PANEL,
	GRAPH_FRAME,
	GRAPH_FONT,
	GRAPH_CHARACTER,
	GRAPH_BG,
	GRAPH_BG_1,
	GRAPH_BG_2,
	GRAPH_PSYCHIC,
	GRAPH_MAPCHIPGUIDE,
	GRAPH_CLOUD_BIG,
	GRAPH_CLOUD_SMALL,
	GRAPH_ENEMY_PURPLE_YOKAI,
};

enum DEVICE {
	DEVICE_1,
	DEVICE_2
};

struct CHIP_POS {
		int cx;
		int cy;
		CHIP_POS( ) {
		};
		CHIP_POS( int x, int y ) :
			cx( x ), cy( y ) {
		}
};

enum DIR {
	DIR_RIGHT,
	DIR_LEFT,
};