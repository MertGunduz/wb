/**
 * @file deleteMenu.c
 * 
 * @brief deletes the word from words.txt and the word file itself
 * 
 * @author Mehmet Mert Gunduz
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief deletes the word from words.txt and the word file itself
void deleteMenu(char *word)
{
    if (word != NULL && word != "")
    {
        /* word */
        char lineword[65];
        int loopWords;

        /* file related */
        char wordFilePath[128];
        char wordsFilePath[128];

        /* generating the path */
        sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), word);
        sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

        /* taking the total words */
        FILE *totalWordsFile = fopen(wordsFilePath, "r");

        loopWords = takeFileLength(totalWordsFile);

        fclose(totalWordsFile);

        /* remove the word file */
        FILE *controlFile = fopen(wordFilePath, "r");

        if (controlFile == NULL)
        {
            fileNotFoundError(word);
            exit(0);
        }

        remove(wordFilePath);
        fclose(controlFile);

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

        /* write the words */
        FILE *writeFile = fopen(wordsFilePath, "w");

        for (int i = 0; i < loopWords; i++)
        {
            if (strncmp(words[i], word, strlen(word)) != 0)
            {
                fputs(words[i], writeFile);
            }
        }

        fclose(writeFile);

        /* write deletion information */
        deletedInfo(word);
    }
    else
    {
        nullWordError();
    }
}