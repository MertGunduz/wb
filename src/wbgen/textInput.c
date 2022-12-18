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

/// @brief the function for working with the text input system
/// @param window 
/// @param ct 
/// @param wordstrlen 
/// @param winX
/// @param string
void textInput(WINDOW *window, int ct, int wordstrlen, int winX, char *string)
{
    int sc = 0;
    char dataChar;
    bool isBreached, isDotsPlaced;

    for (int i = 0; i < 64; i++)
    {
        if (ct != 0)
        {
            if (i == winX - wordstrlen - 7)
            {
                isBreached = true;
            } 

            dataChar = wgetch(window);

            if (dataChar == KEY_ENTER || dataChar == '\n')
            {
                break;
            }
        }

        if (dataChar != 127)
        {
            string[sc] = dataChar;
            sc++; 

            ct--;
        }
        else
        {            
            if (ct != 64)
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

        mvwdelch(window, 2, winX -1);
        mvwdelch(window, 2, winX -2);
        mvwdelch(window, 2, winX -3);

        if (ct >= 100)
        {
            mvwprintw(window, 2, getmaxx(window) - 4, "%d", ct);
        }
        else if (ct >= 10)
        {
            mvwprintw(window, 2, getmaxx(window) - 3, "%d", ct);
        }
        else if (ct > 0)
        {
            mvwprintw(window, 2, getmaxx(window) - 2, "%d", ct);
        }
        else if (ct == 0)
        {
            mvwprintw(window, 2, getmaxx(window) - 2, "0");
        } 

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
            }

            wmove(window, 1, winX - 2);
            wdelch(window);            
        }
    }

    echo();
}