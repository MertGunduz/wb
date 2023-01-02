/**
 * @file addMenu.c
 * 
 * @brief the word adding menu of the wb, it opens a terminal ui and prompts some data from the user to generate word files
 * 
 * @author Mehmet Mert Gunduz
 * @date 17/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief the word adding menu of the wb, it opens a terminal ui and prompts some data from the user to generate word files
void addMenu()
{
    char word[65]; /* word data (example: discreet)*/
    char wordType[65]; /* word type data (example: adjective)*/
    char wordDesc[257]; /* word description data (example: careful not to cause embarrassment or attract too much attention, especially by keeping something secret)*/
    char wordExample[257]; /* word example data (example: The family made discreet enquiries about his background)*/
    char wordOpposite[65]; /* word opposite data (example: indiscreet)*/
    char wordDate[33]; /* word add date data (example: 05/1/2023)*/
    char dataChar = ' '; /* for getching the data */

    int x,y; /* for window data */

    int wordCt = 64;
    int wordTypeCt = 64;
    int wordDescCt = 256;
    int wordExCt = 256;
    int wordOppositeCt = 64;

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
        mvwprintw(topPanel, 0, 1, "ADD MENU");
        mvwprintw(topPanel, 0, (COLS - 2) / 2, "wb");
        mvwprintw(topPanel, 0, COLS - strlen(wordDate) - 1, "%s", wordDate);
       
        /* refresh the top panel */
        fullrefresh(topPanel);
    } 

    /******************************************
    * WORD WINDOW START
    ******************************************/
   WINDOW *wordWindow = newwin(3, COLS / 2 - 1, 2, 0);

   if (wordWindow != NULL)
   {
        wbkgd(wordWindow, COLOR_PAIR(100));

        getmaxyx(wordWindow, y, x);
        
        mvwprintw(wordWindow, 1, 1, "WORD: ");
        mvwprintw(wordWindow, 2, x - 3, "%d", wordCt);

        /* refresh the word window */
        fullrefresh(wordWindow);
    }
    
    /******************************************
    * WORD TYPE WINDOW START
    ******************************************/
    WINDOW *wordTypeWindow = newwin(3, COLS / 2 , 2, COLS / 2 + 1);

    if (wordTypeWindow != NULL)
    {
        wbkgd(wordTypeWindow, COLOR_PAIR(100));
        
        getmaxyx(wordTypeWindow, y, x);

        mvwprintw(wordTypeWindow, 1, 1, "WORD TYPE: ");

        /* writing the number counter to the right edge */
        if (COLS % 2 == 0)
        {
            mvwprintw(wordTypeWindow, 2, x - 4, "%d", wordTypeCt);
        }
        else
        {
            mvwprintw(wordTypeWindow, 2, x - 3, "%d", wordTypeCt);
        }

        /* refresh the word type window */
        fullrefresh(wordTypeWindow);
    }

    /******************************************
    * WORD OPPOSITE WINDOW START
    ******************************************/
    WINDOW *oppositeWordWindow = newwin(3, COLS, 6, 0);

    if (oppositeWordWindow != NULL)
    {
        wbkgd(oppositeWordWindow, COLOR_PAIR(100));

        getmaxyx(oppositeWordWindow, y, x);

        mvwprintw(oppositeWordWindow, 1, 1, "WORD OPPOSITE: ");
        mvwprintw(oppositeWordWindow, 2, x - 3, "%d", wordOppositeCt);

        /* refresh the word window */
        fullrefresh(oppositeWordWindow);
    }

    /******************************************
    * WORD OPPOSITE WINDOW START
    ******************************************/
    WINDOW *wordDescWindow = newwin(3, COLS, 10, 0);

    if (wordDescWindow != NULL)
    {
        wbkgd(wordDescWindow, COLOR_PAIR(100));

        getmaxyx(wordDescWindow, y, x);
        
        mvwprintw(wordDescWindow, 1, 1, "WORD DESCRIPTION: ");
        mvwprintw(wordDescWindow, 2, x - 4, "%d", wordDescCt);

        /* refresh the word window */
        fullrefresh(wordDescWindow);
    }

    /******************************************
    * WORD EXAMPLE WINDOW START
    ******************************************/
    WINDOW *wordExampleWindow = newwin(3, COLS, 14, 0);

    if (wordExampleWindow != NULL)
    {
        wbkgd(wordExampleWindow, COLOR_PAIR(100));

        getmaxyx(wordExampleWindow, y, x);
        
        mvwprintw(wordExampleWindow, 1, 1, "WORD EXAMPLE: ");
        mvwprintw(wordExampleWindow, 2, x - 4, "%d", wordExCt);

        /* refresh the word window */
        fullrefresh(wordExampleWindow);
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

    refresh();

    /******************************************
    * WORD INPUT
    ******************************************/    
    textInput(wordWindow, wordCt, strlen("WORD:"), getmaxx(wordWindow), word, 0);
    fullrefresh(wordWindow);

    textInput(wordTypeWindow, wordTypeCt, strlen("WORD TYPE:"), getmaxx(wordTypeWindow), wordType, 1);
    fullrefresh(wordTypeWindow);

    textInput(oppositeWordWindow, wordOppositeCt, strlen("WORD OPPOSITE:"), getmaxx(oppositeWordWindow), wordOpposite, 0);
    fullrefresh(oppositeWordWindow);

    textInput(wordDescWindow, wordDescCt, strlen("WORD DESCRIPTION:"), getmaxx(wordDescWindow), wordDesc, 0);
    fullrefresh(wordDescWindow);

    textInput(wordExampleWindow, wordExCt, strlen("WORD EXAMPLE:"), getmaxx(wordExampleWindow), wordExample, 0);
    fullrefresh(wordExampleWindow);

    /******************************************
    * WORD FILE GENERATION
    ******************************************/   
    char wordFilePath[128]; 
    char wordsFilePath[128];

    sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), word);
    sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

    /* adding the word name to the words list file */
    FILE *wordsFile = fopen(wordsFilePath, "a");

    if (wordsFile != NULL)
    {
        fprintf(wordsFile, "%s\n", word);
        fclose(wordsFile);
    }

    FILE *wordFile = fopen(wordFilePath, "w");

    if (wordFile != NULL)
    {
        fprintf(wordFile, "%s:%s:%s:%s:%s:%s\n", word, wordType, wordOpposite, wordDesc, wordExample, wordDate);
        fclose(wordFile);
    }

    delwin(topPanel);
    delwin(wordWindow);
    delwin(wordTypeWindow);
    delwin(oppositeWordWindow);
    delwin(wordDescWindow);
    delwin(wordExampleWindow);
    endwin();
}