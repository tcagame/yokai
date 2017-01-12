#include "Map0.h"
#include <string>
/*
const char * BG_FILENAME[] = {
	"street/map0/map0_00_00.png",
	"street/map0/map0_01_00.png",
	"street/map0/map0_02_00.png",
	"street/map0/map0_03_00.png",
	"street/map0/map0_04_00.png",
	"street/map0/map0_05_00.png",
	"street/map0/map0_06_00.png",
	"street/map0/map0_07_00.png",
	"street/map0/map0_08_00.png",
	"street/map0/map0_09_00.png",
	"street/map0/map0_10_00.png",
	"street/map0/map0_00_01.png",
	"street/map0/map0_00_01.png",
	"street/map0/map0_00_01.png",
	"street/map0/map0_04_01.png",
	"street/map0/map0_05_01.png",
	"street/map0/map0_06_01.png",
	"street/map0/map0_07_01.png",
	"street/map0/map0_08_01.png",
	"street/map0/map0_09_01.png",
	"street/map0/map0_10_01.png",
	"street/map0/map0_11_01.png",
	"street/map0/map0_00_02.png",
	"street/map0/map0_00_02.png",
	"street/map0/map0_00_02.png",
	"street/map0/map0_04_02.png",
	"street/map0/map0_05_02.png",
	"street/map0/map0_06_02.png",
	"street/map0/map0_00_08.png",
	"street/map0/map0_01_03.png",
	"street/map0/map0_03_03.png",
	"street/map0/map0_04_03.png",
	"street/map0/map0_06_03.png",
	"street/map0/map0_07_03.png",
	"street/map0/map0_00_04.png",
	"street/map0/map0_02_04.png",
	"street/map0/map0_01_04.png",
	"street/map0/map0_03_04.png",
	"street/map0/map0_04_04.png",
	"street/map0/map0_00_10.png",
	"street/map0/map0_00_05.png",
	"street/map0/map0_00_05.png",
	"street/map0/map0_00_05.png",
	"street/map0/map0_06_05.png",
	"street/map0/map0_07_05.png",
	"street/map0/map0_08_05.png",
	"street/map0/map0_09_05.png",
	"street/map0/map0_12_06.png",
	"street/map0/map0_00_11.png",
	"street/map0/map0_01_11.png",
	"street/map0/map0_02_11.png",
};
*/

{
	{
		"street/map0/map0_00_01.png",
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
		"++++++++++++++++"
	}
}

Map0::Map0( ) {

}

Map0::~Map0( ) {
}

const char * Map0::getBGFilename( int idx ) const {
	return BG_FILENAME[ idx ];
}

