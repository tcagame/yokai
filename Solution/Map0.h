#pragma once

#include "Map.h"
#include <array>

class Map0 : public Map {
public:
	Map0( );
	virtual ~Map0( );
	enum CHIP {
		CHIP_00,
		CHIP_01,
		CHIP_02,
		CHIP_03,
		CHIP_04,
		CHIP_05,
		CHIP_06,
		CHIP_07,
		CHIP_08,
		CHIP_09,
		CHIP_10,
		CHIP_11,
		CHIP_12,
		CHIP_13,
		CHIP_14,
		CHIP_15,
		CHIP_16,
		CHIP_17,
		CHIP_18,
		CHIP_19,
		CHIP_20,
		CHIP_21,
		CHIP_22,
		CHIP_23,
		CHIP_24,
		CHIP_25,
		CHIP_26,
		CHIP_27,
		CHIP_28,
		CHIP_29,
		CHIP_30,
		CHIP_31,
		CHIP_32,
		CHIP_33,
		CHIP_34,
		CHIP_35,
		CHIP_36,
		CHIP_37,
		CHIP_38,
		CHIP_39,
		CHIP_40,
		CHIP_41,
		CHIP_42,
		CHIP_43,
		CHIP_44,
		CHIP_45,
		CHIP_46,
		CHIP_47,
		CHIP_48,
		CHIP_49,
		CHIP_50,

		MAX_CHIP
	};
	struct MAP_CHIP {
		char * chip_path;
		MAP_CHIP( ) { };
		MAP_CHIP( char ch[ MAX_STRING ] ) {
			chip_path = ch;
		}
	};
	std::array< MAP_CHIP, MAX_CHIP > _map_chip;
};
