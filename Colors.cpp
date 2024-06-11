#include "Colors.h"

const Color eerieBlack = { 27, 32, 33, 255 };
const Color vanilla = { 227, 220, 149, 255 };
const Color pearl = { 227, 220, 194, 255 };
const Color hunterGreen = { 56, 102, 65, 255 };
const Color navy = { 0, 0, 128, 255 };
const Color mountPink = { 148, 110, 131, 255 };
const Color roseWood = { 107, 15, 26, 255 };
const Color buff = { 223, 160, 110, 255 };

std::vector<Color> GetCellColors()
{
	return { eerieBlack, vanilla, pearl, hunterGreen, navy, mountPink, roseWood, buff };
}