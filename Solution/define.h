#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

enum GRAPH {
	GRAPH_FADE_BOARD,
	GRAPH_TITLE_PANEL,
	GRAPH_TITLE_FRAME,
	GRAPH_TITLE_FONT,
	GRAPH_PLAYERCHOICE,
	GRAPH_REPLAY,
	GRAPH_CURSOR,
	GRAPH_GAMEOVER,
	GRAPH_GATE_BG,
	GRAPH_GATE_COVER,
	GRAPH_GATE_MAP,
	GRAPH_GATE_TITLE,
	GRAPH_RESULT_FRAME,
	GRAPH_RESULT_OBJ,
	GRAPH_STATUS_PLATE,
	GRAPH_STATUS_POWER,
	GRAPH_STATUS_MAP,
	GRAPH_STATUS_MARKER,
	GRAPH_STATUS_TITLE,
	GRAPH_CHARACTER_1,
	GRAPH_CHARACTER_2,
	GRAPH_IMPACT,
	GRAPH_IMPACT_BIG,
	GRAPH_BOMB,
	GRAPH_ENEMY_BOSS,
	GRAPH_ENEMY_NORMAL,
	GRAPH_ENEMY_SMALL,
	GRAPH_ENEMY_BIG,
	GRAPH_ENEMY_TREE_BODY,
	GRAPH_ENEMY_TREE_ITEM,
	GRAPH_ENEMY_TREE_MONSTER_BODY,
	GRAPH_ENEMY_TREE_MONSTER_ITEM,
	GRAPH_ENEMY_FIREBALL,
	GRAPH_ENEMY_FLOG_GREEN,
	GRAPH_ENEMY_FLOG_RED,
	GRAPH_ENEMY_ROCKMASS,
	GRAPH_ENEMY_CROW,
	GRAPH_ENEMY_BLOOD_POND,
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
	MAX_GRAPH
};

enum DEVICE {
	DEVICE_1 = 0,
	DEVICE_2 = 1,
};

enum FLOOR {
	FLOOR_ROAD,
	FLOOR_WATER,
	FLOOR_BOG,
	FLOOR_NEEDLE,
};