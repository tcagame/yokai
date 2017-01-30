#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

const unsigned int NONE				= 0x00000000;	//なし
const unsigned int DECEASED_PURPLE	= 0x00000001;	//亡者（紫）
const unsigned int REDBIRD			= 0x00000002;	//紅鳥
const unsigned int MOTH				= 0x00000004;	//蛾
const unsigned int TREE				= 0x00000008;	//人面樹
const unsigned int DECEASED			= 0x00000010;	//沼の亡者
const unsigned int FLOG_SMALL		= 0x00000020;	//ミニガエル
const unsigned int STONE_ROTE		= 0x00000040;	//石（回転）
const unsigned int STONE_FLY		= 0x00000080;	//石（飛行）
const unsigned int GHOUL			= 0x00000100;	//餓鬼
const unsigned int EXTRUDEDSPRITS	= 0x00000200;	//顔と手
const unsigned int ONYUDO			= 0x00000400;	//大入道
const unsigned int WATER_GHOST		= 0x00000800;	//水亡霊
const unsigned int WATER_MONK		= 0x00001000;	//水坊主
const unsigned int SKELETON_SPEAR	= 0x00002000;	//槍骸骨
const unsigned int MIASMA_GRAY		= 0x00004000;	//毒気(灰色)
const unsigned int JIZO				= 0x00008000;	//化け地蔵
const unsigned int FLOG				= 0x00010000;	//ガマ
const unsigned int EYE				= 0x00020000;	//目玉の妖怪
const unsigned int GROW_FACE        = 0x00040000;	//人面樹から成る顔
const unsigned int BOW_DEMON        = 0x00080000;	//弓鬼
const unsigned int CROCODILE_SNAKE	= 0x00100000;	//ワニ蛇
const unsigned int HUG_DEMON		= 0x00200000;	//抱きつき鬼
const unsigned int BLOOD_POND_DEMON	= 0x00400000;	//血の池の鬼
const unsigned int BLUE_MONK		= 0x00800000;	//青坊主
const unsigned int ONE_EYES_SNAKE	= 0x01000000;	//一つ目蛇
const unsigned int MIYASMA_WHITE	= 0x02000000;	//毒気(白色)
const unsigned int DECEASED_GREEN	= 0x04000000;	//亡者（緑）

enum GRAPH {
	GRAPH_FADE_BOARD,
	GRAPH_TITLE_PANEL,
	GRAPH_TITLE_FRAME,
	GRAPH_TITLE_FONT,
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
	GRAPH_BOMB,
	GRAPH_BOSS,
	GRAPH_ENEMY_NOMAL,
	GRAPH_ENEMY_SMALL,
	GRAPH_ENEMY_BIG,
	GRAPH_ENEMY_TREE,
	GRAPH_ENEMY_FIREBALL,
	GRAPH_ENEMY_FLOG,
	GRAPH_ENEMY_EFFECT_NOMAL,
	GRAPH_ENEMY_EFFECT_SMALL,
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
	DEVICE_1,
	DEVICE_2
};

enum FLOOR {
	FLOOR_ROAD,
	FLOOR_WATER,
	FLOOR_BOG,
};