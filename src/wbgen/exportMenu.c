/**
 * @file exportMenu.c
 * 
 * @brief creates a file named wbdata.txt and exports the appdata to it
 * 
 * @author Mehmet Mert Gunduz
 * @date 02/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief creates a file named wbdata.txt and exports the appdata to it
void exportMenu()
{
    /* word */
    char lineword[65];
    int loopWords;
    
    /* full line */
    char wordTaker[65];
    char fullLineWord[1025];

    /* word reading file */
    FILE *oneWordReader;

    /* file related */
    char wordFilePath[128];
    char wordsFilePath[128];

    /* generating the path */
    sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

    /* taking the total words */
    FILE *totalWordsFile = fopen(wordsFilePath, "r");

    loopWords = takeFileLength(totalWordsFile);

    fclose(totalWordsFile);

    if (loopWords == 0)
    {
        noWordsInfo();
        exit(0);
    }

    /* remove the word from the words.txt file */
    FILE *readFile = fopen(wordsFilePath, "r");

    if (readFile == NULL)
    {
        wordsTxtFileNotFoundError();
        exit(0);
    }

    /* initializing total words variable */
    char words[loopWords][65];

    /* initialize the words */
    for (int i = 0; i < loopWords; i++)
    {
        fgets(words[i], 64, readFile);
    }

    fclose(readFile);

    /* write the wbdata.txt file */
    FILE *wbdataFile = fopen("wbdata.txt", "w");

    if (wbdataFile == NULL)
    {
        cantCreatewbdataFile();
        exit(0);
    }

    for (int i = 0; i < loopWords; i++)
    {
        /* removing the \n from the words */
        strncpy(wordTaker, words[i], strlen(words[i]) - 1);
        wordTaker[strlen(words[i]) - 1] = '\0';

        /* creating the path */
        sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), wordTaker);

        /* file for reading the word */
        oneWordReader = fopen(wordFilePath, "r");

        /* getting the full word vocabulary line */
        fgets(fullLineWord, 1024, oneWordReader);

        /* writing to wbdata.txt */
        fputs(fullLineWord, wbdataFile);
    }

    /* closing the wbdatafile */
    fclose(wbdataFile);
    fclose(oneWordReader);

    /* log a export info */
    exportedInfo();
}