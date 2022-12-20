/**
 * @file fullrefresh.c
 * 
 * @brief refreshes the stdscr and the specified window
 * 
 * @author Mehmet Mert Gunduz
 * @date 20/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief refreshes the stdscr and the specified window
void fullrefresh(WINDOW *window)
{
    refresh();
    wrefresh(window);
}