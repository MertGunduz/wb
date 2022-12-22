/**
 * @file listMenu.c
 * 
 * @brief the main function for displaying the words
 * 
 * @author Mehmet Mert Gunduz
 * @date 20/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

void spaceAdder(WINDOW *window, int spacer);

/// @brief the main function for displaying the words
void listMenu()
{
    char wordDate[33]; /* word add date data (example: 05/1/2023)*/
    int spacer;
    char travelInput;

    initscr();
    noecho();
    keypad(stdscr, true);

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
        mvwprintw(topPanel, 0, 1, "LIST MENU");
        mvwprintw(topPanel, 0, (COLS - 2) / 2, "wb");
        mvwprintw(topPanel, 0, COLS - strlen(wordDate) - 1, "%s", wordDate);
       
        /* refresh the top panel */
        fullrefresh(topPanel);
    } 

    /******************************************
    * LIST TOP DESCRIPTION PANEL START
    ******************************************/
    WINDOW *listTopPanel = newwin(1, COLS, 2, 0); // WORD - TYPE - OPPOSITE - DESCRIPTION - EXAMPLE - DATE  

    if (listTopPanel != NULL)
    {        
        wbkgd(listTopPanel, COLOR_PAIR(100));

        waddch(listTopPanel, ' ');

        if (COLS >= 43)
        {

            spacer = COLS - 43;
            spacer = spacer / 4;

            wprintw(listTopPanel,  "WORD");
            spaceAdder(listTopPanel, spacer);

            wprintw(listTopPanel,  "TYPE");
            spaceAdder(listTopPanel, spacer);
            
            wprintw(listTopPanel,  "OPPOSITE");
            spaceAdder(listTopPanel, spacer);

            wprintw(listTopPanel,  "DESCRIPTION");
            spaceAdder(listTopPanel, spacer);
            
            wprintw(listTopPanel,  "EXAMPLE");
            spaceAdder(listTopPanel, spacer);
                
            wprintw(listTopPanel,  "DATE");
            spaceAdder(listTopPanel, spacer);
        }
        else
        {
            spacer = COLS - 35;
            spacer = spacer / 4;

            wprintw(listTopPanel,  "WORD");
            spaceAdder(listTopPanel, spacer);

            wprintw(listTopPanel,  "TYPE");
            spaceAdder(listTopPanel, spacer);
            
            wprintw(listTopPanel,  "OPP...");
            spaceAdder(listTopPanel, spacer);

            wprintw(listTopPanel,  "DESC...");
            spaceAdder(listTopPanel, spacer);
            
            wprintw(listTopPanel,  "EX...");
            spaceAdder(listTopPanel, spacer);
                
            wprintw(listTopPanel,  "DATE");
            spaceAdder(listTopPanel, spacer);
        }

        fullrefresh(listTopPanel);
    }

    WINDOW *listPanel;

    if (LINES >= 19)
    {
        listPanel = newwin(15, COLS, 3, 0);
    }
    else
    {
        listPanel = newwin(LINES - 5, COLS, 3, 0);
    }

    if (listPanel != NULL)
    {
        wbkgd(listPanel, COLOR_PAIR(100));

        fullrefresh(listPanel);

        if (LINES >= 19)
        {
            for (int i = 0; i < 15; i++)
            {
                mvwprintw(listPanel, i, 1, "%d", i);
            }
        }
        else
        {
            for (int i = 0; i < LINES - 5; i++)
            {
                mvwprintw(listPanel, i, 1, "%d", i);
            }
        }

        fullrefresh(listPanel);
    }

    int lengthOfList = getmaxy(listPanel);

    WINDOW *useWindow = newwin(1, COLS, lengthOfList + 4, 0);

    if (useWindow != NULL)
    {
        wbkgd(useWindow, COLOR_PAIR(100));

        fullrefresh(useWindow);
    }

    /******************************************
    * BACKGROUND PATTERN DESIGN
    ******************************************/
    attron(COLOR_PAIR(101));

    for (int i = 0; i < COLS; i++)
    {
        mvprintw(lengthOfList + 5, i, "_");
    }

    for (int i = lengthOfList + 6; i < LINES; i++)
    {
        for (int j = 0; j < COLS; j=j+3)
        {
            mvprintw(i, j, "wb ");
        }
    }

    refresh();

    do
    {
        travelInput = getch();
    } while (travelInput != 'q');
    
    delwin(topPanel);
    delwin(listTopPanel);
    delwin(listPanel);
    delwin(useWindow);
    endwin();
}

void spaceAdder(WINDOW *window, int spacer)
{
    if (spacer > 0)
    {
        for (int i = 0; i < spacer; i++)
        {
            waddch(window, ' ');
        }
    }
    else
    {
        waddch(window, ' ');
    }
}