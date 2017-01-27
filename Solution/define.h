#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

const unsigned int NONE				= 0x00000000;
const unsigned int PURPLE			= 0x00000001;
const unsigned int REDBIRD			= 0x00000002;
const unsigned int MOTH				= 0x00000004;
const unsigned int TREE				= 0x00000008;
const unsigned int DECEASED			= 0x00000010;
const unsigned int FLOG_SMALL		= 0x00000020;
const unsigned int STONE_ROTE		= 0x00000040;
const unsigned int STONE_FLY		= 0x00000080;
const unsigned int GHOUL			= 0x00000100;
const unsigned int EXTRUDEDSPRITS	= 0x00000200;
const unsigned int ONYUDO			= 0x00000400;
const unsigned int WATER_GHOST		= 0x00000800;
const unsigned int WATER_MONK		= 0x00001000;
const unsigned int SKELETON_SPEAR	= 0x00002000;
const unsigned int MIASMA_GRAY		= 0x00004000;
const unsigned int JIZO				= 0x00008000;
const unsigned int FLOG				= 0x00010000;

enum GRAPH {
	GRAPH_FADE_BOARD,
	GRAPH_TITLE_PANEL,
	GRAPH_TITLE_FRAME,
	GRAPH_TITLE_FONT,
	GRAPH_GATE_BG,
	GRAPH_GATE_COVER,
	GRAPH_GATE_MAP,
	GRAPH_RESULT_FRAME,
	GRAPH_CHARACTER_1,
	GRAPH_CHARACTER_2,
	GRAPH_IMPACT,
	GRAPH_BOMB,
	GRAPH_BOSS_1,
	GRAPH_BOSS_2,
	GRAPH_BOSS_3,
	GRAPH_ENEMY_NOMAL,
	GRAPH_ENEMY_SMALL,
	GRAPH_ENEMY_BIG_1,
	GRAPH_ENEMY_BIG_2,
	GRAPH_ENEMY_TREE,
	GRAPH_ENEMY_EFFECT_JIZO,
	GRAPH_BG,
	GRAPH_BG_1,
	GRAPH_BG_2,
	GRAPH_BG_3,
	GRAPH_BG_4,
	GRAPH_COVER,
	GRAPH_COVER_1,
	GRAPH_COVER_2,
	GRAPH_COVER_3,
	GRAPH_COVER_4,
	GRAPH_PSYCHIC,
	GRAPH_MAPCHIPGUIDE,
	GRAPH_CLOUD_BIG,
	GRAPH_CLOUD_SMALL,
	GRAPH_STATUS_PLATE,
	GRAPH_STATUS_POWER,
	GRAPH_STATUS_MAP,
	MAX_GRAPH
};

enum DEVICE {
	DEVICE_1,
	DEVICE_2
};

enum FLOOR {
	FLOOR_ROAD,
	FLOOR_WATER,
	FLOOR_BOG,
};