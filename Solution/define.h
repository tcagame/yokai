#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

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
	GRAPH_BG_3,
	GRAPH_BG_4,
	GRAPH_PSYCHIC,
	GRAPH_MAPCHIPGUIDE,
	GRAPH_CLOUD_BIG,
	GRAPH_CLOUD_SMALL,
	GRAPH_STATUS,
	MAX_GRAPH
};

enum DEVICE {
	DEVICE_1,
	DEVICE_2
};
