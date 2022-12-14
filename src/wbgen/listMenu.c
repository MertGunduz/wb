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
void resetCleaners(int *counter, char *string);
void writeSubstringedData(WINDOW *window, char *data, int dataLen, int totalLen, int spacerValue, bool isLast);
void createTopListPanel(WINDOW *listTopPanel, char *word1, char *word2, char *word3, char *word4, char *word5, char *word6, int spacer);

/// @brief the main function for displaying the words
void listMenu()
{
    /* ui related variables */
    char wordDate[33];
    int spacer;
    char travelInput;
    bool isTerminalBig;

    /* file related variables */
    char wordReaderTrashVar[65]; /* file line reader trash var */
    
    char wordsFilePath[128];  /* words.txt path */
    char wordFilePath[128];  /* path for words */

    char wordTaker[65]; /* for cleaning the last /n in the txt file */
    char charTaker; /* for taking the char until /n */
    int ctC = 0;

    /* word.txt single file data */
    char totalLine[1025]; /* total line taker for word files */
    char wWordData[65];
    char wTypeData[65];
    char wOppositeData[65];
    char wdescData[257];
    char wExData[257];
    char wDateData[33];

    int totalWords = 0;
    int wct = 0;

    /* user input */
    int travels = 0;
    int travelI = 0;

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
        fileReadErrorMessage();
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
    curs_set(0);

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

        if (COLS >= 45)
        {
            spacer = COLS - 35;
            spacer = spacer / 5;

            /* methoooood */
            createTopListPanel(listTopPanel, "WORD", "TYPE", "OPPOSITE", "DESCRIPTION", "EX", "DATE", spacer);
            isTerminalBig = true;
        }
        else
        {
            spacer = COLS - 23;
            spacer = spacer / 5;

            createTopListPanel(listTopPanel, "WORD", "TYPE", "OPP", "DESC", "EX", "DATE", spacer);
            isTerminalBig = false;
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

                FILE *wordTxtFile = fopen(wordFilePath, "r");

                fgets(totalLine, 1024, wordTxtFile);

                /* extracting the total line into different variables */
                getWordData(totalLine, wWordData, wTypeData, wOppositeData, wdescData, wExData, wDateData);

                fclose(wordTxtFile);

                wmove(listPanel, i, 1);

                if (isTerminalBig)
                {
                    writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                    writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                    writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 7, spacer, false);
                    writeSubstringedData(listPanel, wdescData, strlen(wdescData), 10, spacer, false);
                    writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                    writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                }
                else
                {
                    writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                    writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                    writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 2, spacer, false);
                    writeSubstringedData(listPanel, wdescData, strlen(wdescData), 3, spacer, false);
                    writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                    writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                }

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
                wct = LINES - 4;
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

                FILE *wordTxtFile = fopen(wordFilePath, "r");

                fgets(totalLine, 1024, wordTxtFile);

                /* extracting the total line into different variables */
                getWordData(totalLine, wWordData, wTypeData, wOppositeData, wdescData, wExData, wDateData);

                fclose(wordTxtFile);

                wmove(listPanel, i, 1);

                if (isTerminalBig)
                {
                    writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                    writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                    writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 7, spacer, false);
                    writeSubstringedData(listPanel, wdescData, strlen(wdescData), 10, spacer, false);
                    writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                    writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                }
                else
                {
                    writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                    writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                    writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 2, spacer, false);
                    writeSubstringedData(listPanel, wdescData, strlen(wdescData), 3, spacer, false);
                    writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                    writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                }

                /* resetting the cleaner variables */
                resetCleaners(&ctC, wordTaker);
            }

            for (int i = wct - 1; i < LINES - 4; i++)
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

        /* exit key */
        writeKey(useWindow, 'q', "to exit", true);

        /* previous page key */
        writeKey(useWindow, 'b', "to go previous page", true);

        /* next page key */
        writeKey(useWindow, 'n', "to go next page", false);

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

        if (travelInput == 'b')
        {
            if (travels - getmaxy(listPanel) >= 0)
            {
                wclear(listPanel);

                travels = travels - getmaxy(listPanel);

                for (int i = travels; i < travels + getmaxy(listPanel); i++)
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

                    FILE *wordTxtFile2 = fopen(wordFilePath, "r");

                    if (wordTxtFile2 != NULL)
                    {
                        fgets(totalLine, 1024, wordTxtFile2);

                        /* extracting the total line into different variables */
                        getWordData(totalLine, wWordData, wTypeData, wOppositeData, wdescData, wExData, wDateData);

                        fclose(wordTxtFile2);

                        wmove(listPanel, travelI, 1);

                        if (isTerminalBig)
                        {
                            writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                            writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                            writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 7, spacer, false);
                            writeSubstringedData(listPanel, wdescData, strlen(wdescData), 10, spacer, false);
                            writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                            writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                        }
                        else
                        {
                            writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                            writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                            writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 2, spacer, false);
                            writeSubstringedData(listPanel, wdescData, strlen(wdescData), 3, spacer, false);
                            writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                            writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                        }

                        /* resetting the cleaner variables */
                        resetCleaners(&ctC, wordTaker);
                        travelI++;                    
                    }
                }

                fullrefresh(listPanel);
            } 

            travelI = 0;           
        }
        else if (travelInput == 'n')
        {
            if (travels + getmaxy(listPanel) <= totalWords)
            {
                wclear(listPanel);

                travels = travels + getmaxy(listPanel);

                for (int i = travels; i < travels + getmaxy(listPanel); i++)
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

                    FILE *wordTxtFile2 = fopen(wordFilePath, "r");

                    if (wordTxtFile2 != NULL)
                    {
                        fgets(totalLine, 1024, wordTxtFile2);

                        /* extracting the total line into different variables */
                        getWordData(totalLine, wWordData, wTypeData, wOppositeData, wdescData, wExData, wDateData);

                        fclose(wordTxtFile2);

                        wmove(listPanel, travelI, 1);

                        if (isTerminalBig)
                        {
                            writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                            writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                            writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 7, spacer, false);
                            writeSubstringedData(listPanel, wdescData, strlen(wdescData), 10, spacer, false);
                            writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                            writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                        }
                        else
                        {
                            writeSubstringedData(listPanel, wWordData, strlen(wWordData), 3, spacer, false);
                            writeSubstringedData(listPanel, wTypeData, strlen(wTypeData), 3, spacer, false);
                            writeSubstringedData(listPanel, wOppositeData, strlen(wOppositeData), 2, spacer, false);
                            writeSubstringedData(listPanel, wdescData, strlen(wdescData), 3, spacer, false);
                            writeSubstringedData(listPanel, wExData, strlen(wExData), 1, spacer, false);
                            writeSubstringedData(listPanel, wDateData, strlen(wDateData), 3, spacer, true);
                        }

                        /* resetting the cleaner variables */
                        resetCleaners(&ctC, wordTaker);
                        travelI++;
                    }
                    else
                    {
                        /* resetting the cleaner variables */
                        resetCleaners(&ctC, wordTaker);
                        travelI++;

                        for (int i = travelI - 1; i < getmaxy(listPanel); i++)
                        {
                            mvwprintw(listPanel, i, 1, "NO DATA");
                        }
                        
                        break;
                    }
                }

                fullrefresh(listPanel);
            }

            travelI = 0;
        }

        fullrefresh(listPanel);
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
    if (spacer > 1)
    {
        for (int i = 0; i < spacer; i++)
        {
            waddch(window, ' ');
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            waddch(window, ' ');
        }
    }
}

void resetCleaners(int *counter, char *string)
{
    string[0] = '\0';
    *counter = 0;
}

/// @brief the function for placing the datas pixel perfect
/// @param window 
/// @param data 
/// @param dataLen 
/// @param totalLen 
/// @param spacerValue
/// @param isLast
void writeSubstringedData(WINDOW *window, char *data, int dataLen, int totalLen, int spacerValue, bool isLast)
{
    bool controller = false;

    wattron(window, A_ITALIC);

    if (!isLast)
    {
        for (int i = 0; i < totalLen + spacerValue - 2; i++)
        {
            if (i < dataLen)
            {
                waddch(window, data[i]);
            }
            else
            {
                waddch(window, ' ');
            }
        }
    }
    else
    {
        for (int i = 0; i < totalLen; i++)
        {
            if (i < dataLen)
            {
                waddch(window, data[i]);
            }
            else
            {
                waddch(window, ' ');
            }
        }
    }

    if (dataLen > totalLen + spacerValue - 2)
    {
        waddch(window, '~');

        if (isLast)
        {
            controller = true;
        }
    }
    else
    {
        if (!isLast)
        {
            waddch(window, ' ');
        }
    }

    if (!isLast)
    {
        waddch(window, ' ');
        waddch(window, ' ');
    }
    
    if (isLast && !controller)
    {
        waddch(window, '~');
    }

    wattroff(window, A_ITALIC);
}

/// @brief the function for creating the top list panel
/// @param listTopPanel 
/// @param word1 
/// @param word2 
/// @param word3 
/// @param word4 
/// @param word5 
/// @param word6 
/// @param spacer 
void createTopListPanel(WINDOW *listTopPanel, char *word1, char *word2, char *word3, char *word4, char *word5, char *word6, int spacer)
{
    wprintw(listTopPanel,  "%s", word1);
    spaceAdder(listTopPanel, spacer);

    wprintw(listTopPanel,  "%s", word2);
    spaceAdder(listTopPanel, spacer);
            
    wprintw(listTopPanel,  "%s", word3);
    spaceAdder(listTopPanel, spacer);
    
    wprintw(listTopPanel,  "%s", word4);
    spaceAdder(listTopPanel, spacer);
            
    wprintw(listTopPanel,  "%s", word5);
    spaceAdder(listTopPanel, spacer);
                
    wprintw(listTopPanel,  "%s", word6);
    spaceAdder(listTopPanel, spacer);
}