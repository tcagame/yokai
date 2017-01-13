#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int CHIP_SIZE = 34 * 6;
const int BG_SIZE = 768;
const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;
const int CHARA_MOVE_RATIO = 10;

enum GRAPH {
	GRAPH_PANEL,
	GRAPH_FRAME,
	GRAPH_FONT,
	GRAPH_CHARACTER,
	GRAPH_BG,
	GRAPH_BG_1,
	GRAPH_BG_2,
	GRAPH_EFFECT_0,
	GRAPH_MAPCHIPGUIDE,
};

enum DEVICE {
	DEVICE_1,
	DEVICE_2
};