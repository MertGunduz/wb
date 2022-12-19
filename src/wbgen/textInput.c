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

void cleanLetterCounter(WINDOW *window, int winX);
void printLetterCounter(WINDOW *window, int ct, int locationSetter);
bool breachControl(WINDOW *window, int i, int winX, int wordstrlen);

/// @brief the function for working with the text input system
/// @param window 
/// @param ct 
/// @param wordstrlen 
/// @param winX
/// @param string
/// @param locationSetter
void textInput(WINDOW *window, int ct, int wordstrlen, int winX, char *string, int locationSetter)
{
    int lim = ct;
    int i = 0;
    int sc = 0;
    char dataChar;
    bool isBreached, isDotsPlaced;

    /* moves to the window header text input */
    wmove(window, 1, wordstrlen + 2);

    do
    {
        /* controls if breached */
        isBreached = breachControl(window, i, winX, wordstrlen);

        /* input */
        dataChar = wgetch(window);

        if (isDotsPlaced)
        {
            wmove(window, 1, winX - 1);
        }
        
        if (dataChar != BACKSPACE_CHAR)
        {
            string[sc] = dataChar;
            sc++; 

            ct--;
        }
        else
        {            
            if (ct != lim)
            {
                sc--; 
                string[sc] = '\0';

                ct++;

                mvwdelch(window, 1, i + wordstrlen + 3);
                mvwdelch(window, 1, i + wordstrlen + 2);
                mvwdelch(window, 1, i + wordstrlen + 1);

                i = i - 2;
            }
            else
            {
                mvwdelch(window, 1, i + wordstrlen + 3);
                mvwdelch(window, 1, i +  wordstrlen + 2);
                i--;
            }
        }

        /* cleans the letter counter part [64]-[256] */
        cleanLetterCounter(window, winX);
        
        /* pritns the letter counter */
        printLetterCounter(window, ct, locationSetter);

        if (!isBreached)
        {
            wmove(window, 1, wordstrlen + 3 + i);
        }
        else
        {
            if (!isDotsPlaced)
            {
                mvwaddch(window, 1, wordstrlen + 3 + i, '.');
                mvwaddch(window, 1, wordstrlen + 3 + i + 1, '.');
                mvwaddch(window, 1, wordstrlen + 3 + i + 2, '.');
                isDotsPlaced = true;
                noecho();
                curs_set(0);
            }
        }

        i++;
    } while (dataChar != KEY_ENTER && dataChar != '\n');

    /* adding a null terminator to the string */
    string[sc++] = '\0';

    isBreached = false; isDotsPlaced = false;
    echo();
    curs_set(1);
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
void printLetterCounter(WINDOW *window, int ct, int locationSetter)
{
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

/// @brief controls if the input breaches the window border
/// @param window 
/// @param i 
/// @param winX 
/// @param wordstrlen 
/// @return 
bool breachControl(WINDOW *window, int i, int winX, int wordstrlen)
{
    if (i == winX - wordstrlen - 7)
    {
        return true;
    } 
}