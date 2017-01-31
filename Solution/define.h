#pragma once

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT =  720;
const int BG_SIZE = 512;
const int BG_NUM = SCREEN_WIDTH / 512 + 2;
const int CHARA_MOVE_RATIO = 10;
const int GRAVITY_POWER = 3;

const unsigned long long NONE				= 0x0000000000000000;	//�Ȃ�
const unsigned long long DECEASED_PURPLE	= 0x0000000000000001;	//�S�ҁi���j
const unsigned long long MIASMA_WHITE		= 0x0000000000000002;	//�ŋC(���F)
const unsigned long long MIASMA_GRAY		= 0x0000000000000004;	//�ŋC(�D�F)
const unsigned long long REDBIRD			= 0x0000000000000008;	//�g��
const unsigned long long MOTH				= 0x0000000000000010;	//��
const unsigned long long TREE				= 0x0000000000000020;	//�l�ʎ�
const unsigned long long TREE_MONSTER	    = 0x0000000000000040;	//���d
const unsigned long long FLOG				= 0x0000000000000080;	//�K�}
const unsigned long long FLOG_SMALL			= 0x0000000000000100;	//�~�j�K�G��
const unsigned long long DECEASED			= 0x0000000000000200;	//���̖S��
const unsigned long long STONE_ROTE			= 0x0000000000000400;	//�΁i��]�j
const unsigned long long STONE_FLY			= 0x0000000000000800;	//�΁i��s�j
const unsigned long long GHOUL				= 0x0000000000001000;	//��S
const unsigned long long EXTRUDEDSPRITS		= 0x0000000000002000;	//��Ǝ�
const unsigned long long ONYUDO				= 0x0000000000004000;	//�����
const unsigned long long WATER_GHOST		= 0x0000000000008000;	//���S��
const unsigned long long WATER_MONK			= 0x0000000000010000;	//���V��
const unsigned long long SKELETON_SPEAR		= 0x0000000000020000;	//���[��
const unsigned long long JIZO				= 0x0000000000040000;	//�����n��
const unsigned long long EYE				= 0x0000000000080000;	//�ڋʂ̗d��
const unsigned long long BOW_DEMON			= 0x0000000000100000;	//�|�S
const unsigned long long HUG_DEMON			= 0x0000000000200000;	//�������S
const unsigned long long BLOOD_POND_DEMON	= 0x0000000000400000;	//���̒r�̋S
const unsigned long long BLUE_MONK			= 0x0000000000800000;	//�V��
const unsigned long long ONE_EYES_SNAKE		= 0x0000000001000000;	//��ڎ�
const unsigned long long DECEASED_GREEN		= 0x0000000002000000;	//�S�ҁi�΁j
const unsigned long long CROCODILE_SNAKE	= 0x0000000004000000;	//���j��
const unsigned long long HELL_FIRE			= 0x0000000008000000;	//�n����
const unsigned long long ROCK_MASS			= 0x0000000010000000;	//��̉�(��&�O�k)
const unsigned long long WIND_MONSTER		= 0x0000000020000000;	//���̗d��
const unsigned long long RAY_MONSTER		= 0x0000000040000000;	//�����G�C
const unsigned long long NECK_SKULL			= 0x0000000080000000;	//�򓪔؁i�h�N���j
const unsigned long long NECK_WOMAN			= 0x0000000100000000;	//�򓪔؁i���j
const unsigned long long BAT				= 0x0000000200000000;	//�R�E����
const unsigned long long HAND				= 0x0000000400000000;	//��̗d��
const unsigned long long NO_FACE			= 0x0000000800000000;	//�̂��؂�ڂ�
const unsigned long long NO_NECK_GHOST      = 0x0000001000000000;   //��Ȃ��H��
const unsigned long long NAKABON			= 0x0000002000000000;   //���~
const unsigned long long SHISHIMAI		    = 0x0000004000000000;   //���q��
const unsigned long long SHISHI_ONI			= 0x0000008000000000;	//���q���S
const unsigned long long YADOKARI			= 0x0000010000000000;	//���h�J���d��

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