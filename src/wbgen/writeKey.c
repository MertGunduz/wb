/**
 * @file writeKey.c
 * 
 * @brief the main function for writing keys for description windows
 * 
 * @author Mehmet Mert Gunduz
 * @date 20/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief the main function for writing keys for description windows
/// @param window 
/// @param key 
/// @param keyExp 
/// @param isSeperate 
void writeKey(WINDOW *window, char key, char *keyExp, bool isSeperate)
{
    wattron(window, A_BOLD);
    waddch(window, '[');
    waddch(window, key);
    waddch(window, ']');
    wattroff(window, A_BOLD);
        
    wprintw(window, " %s", keyExp);

    if (isSeperate)
    {
        waddch(window, ',');
        waddch(window, ' ');    
    }
}