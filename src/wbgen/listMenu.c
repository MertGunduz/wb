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
int takeFileLength(FILE *file);
void resetCleaners(int *counter, char *string);

/// @brief the main function for displaying the words
void listMenu()
{
    /* ui related variables */
    char wordDate[33];
    int spacer;
    char travelInput;

    /* file related variables */
    char wordReaderTrashVar[65]; /* file line reader trash var */
    
    char wordsFilePath[128];  /* words.txt path */
    char wordFilePath[128];  /* path for words */

    char wordTaker[64]; /* for cleaning the last /n in the txt file */
    char charTaker; /* for taking the char until /n */
    int ctC = 0;

    char totalLine[1025]; /* total line taker for word files */

    int totalWords = 0;
    int wct = 0;

    /* file path variable initialization */
    sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

    /******************************************
    * FILE READING START
    ******************************************/
    /* file total line reading */
    FILE *wordsLineFile = fopen(wordsFilePath, "r");
    totalWords = takeFileLength(wordsLineFile);
    fclose(wordsLineFile);

    /* initialize the size of the totalwords, the variable for storing all the words */
    char words[totalWords][65];

    /* file words reading */
    FILE *wordsFile = fopen(wordsFilePath, "r");

    if (wordsFile == NULL)
    {
        // can't access reading the file message
        exit(0);
    }

    while (!feof(wordsFile))
    {
        fgets(words[wct], 64, wordsFile);
        wct++;
    }

    fclose(wordsFile);

    /******************************************
    * NCURSES START
    ******************************************/
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

    /******************************************
    * LIST PANEL START
    ******************************************/
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
            if (wct >= 19)
            {
                wct = 19;
            }

            for (int i = 0; i < wct - 1; i++)
            {
                /* cleaning the \n from the words */
                do
                {  
                    charTaker = words[i][ctC];

                    wordTaker[ctC] = charTaker;
                    ctC++;
                } while (words[i][ctC] != '\n');

                wordTaker[ctC] = '\0';

                /* the word file path generation */
                sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), wordTaker);

                mvwprintw(listPanel, i, 1, "%s", wordFilePath);

                /* resetting the cleaner variables */
                resetCleaners(&ctC, wordTaker);
            }

            for (int i = wct - 1; i < 19; i++)
            {
                mvwprintw(listPanel, i, 1, "NO DATA");
            }
        }
        else
        {
            if (wct > LINES - 5)
            {
                wct = LINES - 5;
            }

            for (int i = 0; i < wct - 1; i++)
            {
                /* cleaning the \n from the words */
                do
                {  
                    charTaker = words[i][ctC];

                    wordTaker[ctC] = charTaker;
                    ctC++;
                } while (words[i][ctC] != '\n');

                wordTaker[ctC] = '\0';

                /* the word file path generation */
                sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), wordTaker);

                mvwprintw(listPanel, i, 1, "%s", wordFilePath);

                /* resetting the cleaner variables */
                resetCleaners(&ctC, wordTaker);
            }

            for (int i = wct - 1; i < LINES - 5; i++)
            {
                mvwprintw(listPanel, i, 1, "NO DATA");
            }
            
        }

        fullrefresh(listPanel);
    }

    int lengthOfList = getmaxy(listPanel);

    /******************************************
    *  USE WINDOW START
    ******************************************/
    WINDOW *useWindow = newwin(1, COLS, lengthOfList + 4, 0);

    if (useWindow != NULL)
    {
        wbkgd(useWindow, COLOR_PAIR(100));

        waddch(useWindow, ' ');

        wattron(useWindow, A_BOLD);
        waddch(useWindow, '[');
        waddch(useWindow, 'q');
        waddch(useWindow, ']');
        wattroff(useWindow, A_BOLD);
        
        wprintw(useWindow, " to exit");

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

/// @brief the function for setting the resolution of ui
/// @param window 
/// @param spacer 
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

/// @brief the function for taking the total lines in a txt file 
/// @param file 
/// @return total lines of the text
int takeFileLength(FILE *file)
{
    int totalWords = 0;
    char wordReaderTrashVar[65];

    if (file == NULL)
    {
        exit(0);
    }

    while (!feof(file))
    {
        fgets(wordReaderTrashVar, 64, file);
        totalWords++;
    }

    /* corrector for totalwords */
    totalWords--;

    return totalWords;
}

void resetCleaners(int *counter, char *string)
{
    string[0] = '\0';
    *counter = 0;
}