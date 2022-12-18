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
    char word[65]; /* word data (example: discreet)*/
    char wordType[65]; /* word type data (example: adjective)*/
    char wordDesc[257]; /* word description data (example: careful not to cause embarrassment or attract too much attention, especially by keeping something secret)*/
    char wordExample[257]; /* word example data (example: The family made discreet enquiries about his background)*/
    char wordOpposite[65]; /* word opposite data (example: indiscreet)*/
    char wordDate[33]; /* word add date data (example: 05/1/2023)*/

    initscr();
        
    if (colorCheck())
    {
        start_color();
        bgColorSet();
        init_color(COLOR_BLACK, 150, 150, 150);
        init_pair(100, COLOR_WHITE, COLOR_BLACK);
        init_pair(101, COLOR_BLACK, PURE_BLACK_COLOR);
    }
    else
    {
        endwin();
        terminalColorError();
        exit(0);
    }

    /******************************************
    * PANEL START
    ******************************************/
    WINDOW *topPanel = newwin(1, COLS, 0, 0);

    if (topPanel != NULL)
    {
        wbkgd(topPanel, COLOR_PAIR(100));

        /* date & time */
        time_t T = time(NULL);
        struct tm tm = *localtime(&T);

        sprintf(wordDate, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        /* top panel information printing */
        mvwprintw(topPanel, 0, 1, "ADD MENU");
        mvwprintw(topPanel, 0, (COLS - 2) / 2, "wb");
        mvwprintw(topPanel, 0, COLS - strlen(wordDate) - 1, "%s", wordDate);
       
        /* refresh the top panel */
        refresh();
        wrefresh(topPanel);
    } 

    /******************************************
    * WORD WINDOW START
    ******************************************/
   WINDOW *wordWindow = newwin(3, COLS / 2 - 1, 2, 0);

   if (wordWindow != NULL)
   {
        wbkgd(wordWindow, COLOR_PAIR(100));
        
        mvwprintw(wordWindow, 1, 1, "WORD: ");

        /* move to input textbox */
        //wmove(wordWindow, 1, 7);

        /* refresh the word window */
        refresh();
        wrefresh(wordWindow);

        /* take input */
        //wgetnstr(wordWindow, word, 64);
    }
    
    /******************************************
    * WORD TYPE WINDOW START
    ******************************************/
    WINDOW *wordTypeWindow = newwin(3, COLS / 2 , 2, COLS / 2 + 1);

    if (wordTypeWindow != NULL)
    {
        wbkgd(wordTypeWindow, COLOR_PAIR(100));
        
        mvwprintw(wordTypeWindow, 1, 1, "WORD TYPE: ");

        /* move to input textbox */
        //wmove(wordTypeWindow, 1, 7);

        /* refresh the word window */
        refresh();
        wrefresh(wordTypeWindow);

        /* take input */
        //wgetnstr(wordTypeWindow, word, 64);
    }

    /******************************************
    * WORD OPPOSITE WINDOW START
    ******************************************/
    WINDOW *oppositeWordWindow = newwin(3, COLS, 6, 0);

    if (oppositeWordWindow != NULL)
    {
        wbkgd(oppositeWordWindow, COLOR_PAIR(100));
        
        mvwprintw(oppositeWordWindow, 1, 1, "WORD OPPOSITE: ");

        /* move to input textbox */
        //wmove(oppositeWordWindow, 1, 7);

        /* refresh the word window */
        refresh();
        wrefresh(oppositeWordWindow);

        /* take input */
        //wgetnstr(oppositeWordWindow, word, 64);
    }

    /******************************************
    * WORD OPPOSITE WINDOW START
    ******************************************/
    WINDOW *wordDescWindow = newwin(3, COLS, 10, 0);

    if (wordDescWindow != NULL)
    {
        wbkgd(wordDescWindow, COLOR_PAIR(100));
        
        mvwprintw(wordDescWindow, 1, 1, "WORD DESCRIPTION: ");

        /* move to input textbox */
        //wmove(wordDescWindow, 1, 7);

        /* refresh the word window */
        refresh();
        wrefresh(wordDescWindow);

        /* take input */
        //wgetnstr(wordDescWindow, word, 64);
    }

    /******************************************
    * WORD EXAMPLE WINDOW START
    ******************************************/
    WINDOW *wordExampleWindow = newwin(3, COLS, 14, 0);

    if (wordExampleWindow != NULL)
    {
        wbkgd(wordExampleWindow, COLOR_PAIR(100));
        
        mvwprintw(wordExampleWindow, 1, 1, "WORD EXAMPLE: ");

        /* move to input textbox */
        //wmove(wordExampleWindow, 1, 7);

        /* refresh the word window */
        refresh();
        wrefresh(wordExampleWindow);

        /* take input */
        //wgetnstr(wordExampleWindow, word, 64);
    }

    /******************************************
    * BACKGROUND PATTERN DESIGN
    ******************************************/
    attron(COLOR_PAIR(101));

    for (int i = 0; i < COLS; i++)
    {
        mvprintw(17, i, "_");
    }

    for (int i = 18; i < LINES; i++)
    {
        for (int j = 0; j < COLS; j=j+3)
        {
            mvprintw(i, j, "wb ");
        }
    }

    curs_set(0);

    getch();

    delwin(topPanel);
    delwin(wordWindow);
    delwin(wordTypeWindow);
    delwin(oppositeWordWindow);
    delwin(wordDescWindow);
    delwin(wordExampleWindow);
    endwin();
}