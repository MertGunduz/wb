/**
 * @file bgColorSet.c
 * 
 * @brief sets the terminal to pure black and white text
 * 
 * @author Mehmet Mert Gunduz
 * @date 17/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief sets the terminal to pure black and white text
void bgColorSet()
{
    init_color(PURE_BLACK_COLOR, 0, 0, 0);
    init_pair(1, COLOR_WHITE, PURE_BLACK_COLOR);

    bkgd(COLOR_PAIR(1));
}