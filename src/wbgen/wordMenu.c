/**
 * @file wordMenu.c
 * 
 * @brief opens the word menu and shows the word and its other informations
 * 
 * @author Mehmet Mert Gunduz
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief opens the word menu and shows the word and its other informations
void wordMenu(char *word)
{
    if (word != NULL && word != "")
    {
        /* word related*/
        char totalLine[1025];
        char wWordData[65];
        char wTypeData[65];
        char wOppositeData[65];
        char wdescData[257];
        char wExData[257];
        char wDateData[33];

        /* file related */
        char wordFilePath[128];

        /* generating the path */
        sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), word);

        /* read file for the word */
        FILE *file = fopen(wordFilePath, "r");

        if (file == NULL)
        {
            fileNotFoundError(word);
            exit(0);
        }

        /* initializing the totalLine variable with the word file data */
        fgets(totalLine, 1024, file);

        /* extracting the total line data into different variables */
        getWordData(totalLine, wWordData, wTypeData, wOppositeData, wdescData, wExData, wDateData);

        /* writing the data*/
        fprintf(stdout, "Word: %s\n", wWordData);
        fprintf(stdout, "Type: %s\n\n", wTypeData);
        fprintf(stdout, "Opposite: %s\n\n", wOppositeData);
        fprintf(stdout, "Description: %s\n\n", wdescData);
        fprintf(stdout, "Example: %s\n\n", wExData);
        fprintf(stdout, "Added in: %s", wDateData);

        /* close the file */
        fclose(file);
    }
    else
    {
        nullWordError();
    } 
}