#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int CHIP_SIZE = 34 * 6;
const int BG_SIZE = 758;
const int MAPCHIP_NUM = 16;
const int MAPCHIP_SIZE = BG_SIZE / MAPCHIP_NUM;

enum GRAPH {
	GRAPH_PANEL,
	GRAPH_FRAME,
	GRAPH_FONT,
	GRAPH_CHARACTER,
	GRAPH_BG,
	GRAPH_BG_1,
	GRAPH_BG_2,
};