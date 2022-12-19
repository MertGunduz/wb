/**
 * @file textInput.c
 * 
 * @brief the function for working with the text input system
 * 
 * @author Mehmet Mert Gunduz
 * @date 18/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

#define BACKSPACE_CHAR 127
#define INPUT_BITS 2

void cleanLetterCounter(WINDOW *window, int winX);
void printLetterCounter(WINDOW *window, int ct, int locationSetter, int winX);
void firstPosition(WINDOW *window, int wordstrlen);

/// @brief the function for working with the text input system
/// @param window the main window
/// @param ct the letter counter, in every input decreases by one (in backspace increases by 1)
/// @param wordstrlen the header words length (WORD: [5])
/// @param winX the length of the window (getmaxx(window))
/// @param string (string for initializing the data)
/// @param locationSetter the location setter for the half panels
void textInput(WINDOW *window, int ct, int wordstrlen, int winX, char *string, int locationSetter)
{
    char mc; /**< main char for taking the data one by one */

    int limit = ct; /**< takes the ct and initializes it to limit, used for checking the backspace if there is no input */ 
    int firstPositionX = wordstrlen + 2; /**< takes the first position x*/

    int i = 0;
    int iR;

    int sc = 0;

    bool isReached;

    /* go to the first position */
    firstPosition(window, wordstrlen);

    do
    {
        mc = wgetch(window);

        if (mc == BACKSPACE_CHAR)
        {
            if (ct != limit)
            {
                sc--;
                string[sc] = '\0'; 
                
                ct++;

                // deleting character
                if (i <= iR + 1)
                {
                    mvwdelch(window, 1, getcurx(window) - 1);
                    isReached = false;
                }

                i--;
            }
        }
        else
        {
            if (ct != 0)
            {
                if (mc != KEY_ENTER && mc != '\n')
                {
                    string[sc] = mc; 
                    sc++;
                }
                
                ct--;
                
                /* if cursor is not in the last place */
                if (!isReached)
                {
                    if (getcurx(window) + 1 + locationSetter != winX - 1)
                    {
                        waddch(window, mc);
                    }
                    else
                    {
                        waddch(window, '~');
                        isReached = true;

                        iR = i;
                    }
                }

                i++;
            }
        }
    } while (mc != KEY_ENTER && mc != '\n');

    string[sc++] = '\0';
    
    isReached = false;
    i = 0; iR = 0; sc = 0;
}

/// @brief cleans the letter counter
/// @param window 
/// @param winX 
void cleanLetterCounter(WINDOW *window, int winX)
{
    mvwdelch(window, 2, winX -1);
    mvwdelch(window, 2, winX -2);
    mvwdelch(window, 2, winX -3);
    mvwdelch(window, 2, winX -4);
}

/// @brief prints the letter counter
/// @param window 
/// @param ct 
/// @param locationSetter 
void printLetterCounter(WINDOW *window, int ct, int locationSetter, int winX)
{
    cleanLetterCounter(window, winX);

    if (ct >= 100)
    {
        mvwprintw(window, 2, getmaxx(window) - 4 - locationSetter, "%d", ct);
    }
    else if (ct >= 10)
    {
        mvwprintw(window, 2, getmaxx(window) - 3 - locationSetter, "%d", ct);
    }
    else if (ct > 0)
    {
        mvwprintw(window, 2, getmaxx(window) - 2 - locationSetter, "%d", ct);
    }
    else if (ct <= 0)
    {
        mvwprintw(window, 2, getmaxx(window) - 2 - locationSetter, "0");
    } 
}

void firstPosition(WINDOW *window, int wordstrlen)
{
    wmove(window, 1, wordstrlen + 2);
}