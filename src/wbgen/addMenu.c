/**
 * @file addMenu.c
 * 
 * @brief the word adding menu for the wb, it opens a terminal ui and asks user some data to generate word files
 * @brief word, word type, word description, word sentence example, word opposite 
 * 
 * @author Mehmet Mert Gunduz
 * @date 17/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief the word adding menu for the wb, opens a terminal ui and asks user some data to generate word files
void addMenu()
{
    char word[65]; /**< word data (example: discreet)*/
    char wordType[65]; /**< word type data (example: adjective)*/
    char wordDesc[257]; /**< word description data (example: careful not to cause embarrassment or attract too much attention, especially by keeping something secret)*/
    char wordExample[257]; /**< word example data (example: The family made discreet enquiries about his background)*/
    char wordOpposite[65]; /**< word opposite data (example: indiscreet)*/
    char wordDate[33]; /**< word add date data (example: 05/1/2023)*/

    initscr();
        
    if (colorCheck())
    {
        start_color();
        bgColorSet();
    }
    else
    {
        endwin();
        terminalColorError();
        exit(0);
    }

    getch();
    endwin();
}