#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

const unsigned long long NONE				= 0x0000000000000000;	//なし
const unsigned long long DECEASED_PURPLE	= 0x0000000000000001;	//亡者（紫）
const unsigned long long MIASMA_WHITE		= 0x0000000000000002;	//毒気(白色)
const unsigned long long MIASMA_GRAY		= 0x0000000000000004;	//毒気(灰色)
const unsigned long long REDBIRD			= 0x0000000000000008;	//紅鳥
const unsigned long long MOTH				= 0x0000000000000010;	//蛾
const unsigned long long TREE				= 0x0000000000000020;	//人面樹
const unsigned long long TREE_MONSTER	    = 0x0000000000000040;	//樹妖
const unsigned long long FLOG				= 0x0000000000000080;	//ガマ
const unsigned long long FLOG_SMALL			= 0x0000000000000100;	//ミニガエル
const unsigned long long DECEASED			= 0x0000000000000200;	//沼の亡者
const unsigned long long STONE_ROTE			= 0x0000000000000400;	//石（回転）
const unsigned long long STONE_FLY			= 0x0000000000000800;	//石（飛行）
const unsigned long long GHOUL				= 0x0000000000001000;	//餓鬼
const unsigned long long EXTRUDEDSPRITS		= 0x0000000000002000;	//顔と手
const unsigned long long ONYUDO				= 0x0000000000004000;	//大入道
const unsigned long long WATER_GHOST		= 0x0000000000008000;	//水亡霊
const unsigned long long WATER_MONK			= 0x0000000000010000;	//水坊主
const unsigned long long SKELETON_SPEAR		= 0x0000000000020000;	//槍骸骨
const unsigned long long JIZO				= 0x0000000000040000;	//化け地蔵
const unsigned long long EYE				= 0x0000000000080000;	//目玉の妖怪
const unsigned long long BOW_DEMON			= 0x0000000000100000;	//弓鬼
const unsigned long long HUG_DEMON			= 0x0000000000200000;	//抱きつき鬼
const unsigned long long BLOOD_POND_DEMON	= 0x0000000000400000;	//血の池の鬼
const unsigned long long BLUE_MONK			= 0x0000000000800000;	//青坊主
const unsigned long long ONE_EYES_SNAKE		= 0x0000000001000000;	//一つ目蛇
const unsigned long long DECEASED_GREEN		= 0x0000000002000000;	//亡者（緑）
const unsigned long long CROCODILE_SNAKE	= 0x0000000004000000;	//ワニ蛇
const unsigned long long HELL_FIRE			= 0x0000000008000000;	//地獄火
const unsigned long long ROCK_MASS			= 0x0000000010000000;	//岩の塊(魂&外殻)
const unsigned long long WIND_MONSTER		= 0x0000000020000000;	//風の妖怪
const unsigned long long RAY_MONSTER		= 0x0000000040000000;	//化けエイ
const unsigned long long NECK_SKULL			= 0x0000000080000000;	//飛頭蛮（ドクロ）
const unsigned long long NECK_WOMAN			= 0x0000000100000000;	//飛頭蛮（女）
const unsigned long long BAT				= 0x0000000200000000;	//コウモリ
const unsigned long long HAND				= 0x0000000400000000;	//手の妖怪
const unsigned long long NO_FACE			= 0x0000000800000000;	//のっぺらぼう
const unsigned long long NO_NECK_GHOST      = 0x0000001000000000;   //首なし幽霊
const unsigned long long NAKABON			= 0x0000002000000000;   //中盆
const unsigned long long SHISHIMAI		    = 0x0000004000000000;   //獅子舞
const unsigned long long SHISHI_ONI			= 0x0000008000000000;	//獅子舞鬼
const unsigned long long YADOKARI			= 0x0000010000000000;	//ヤドカリ妖怪

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
	GRAPH_ENEMY_TREE_2,
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