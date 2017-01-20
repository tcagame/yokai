#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 768;
const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;
const int CHIP_FOOT_BLANK = 25;
const int CHIP_SIZE = 128;

const unsigned int PURPLE = 0x00000001;
const unsigned int REDBIRD = 0x00000002;

enum GRAPH {
	GRAPH_PANEL,
	GRAPH_FRAME,
	GRAPH_FONT,
	GRAPH_CHARACTER_1,
	GRAPH_CHARACTER_2,
	GRAPH_ENEMY,
	GRAPH_BG,
	GRAPH_BG_1,
	GRAPH_BG_2,
	GRAPH_PSYCHIC,
	GRAPH_MAPCHIPGUIDE,
	GRAPH_CLOUD_BIG,
	GRAPH_CLOUD_SMALL,
	GRAPH_STATUS
};

enum DEVICE {
	DEVICE_1,
	DEVICE_2
};
