/**
 * @file importMenu.c
 * 
 * @brief imports the exported wbdata.txt file
 * 
 * @author Mehmet Mert Gunduz
 * @date 03/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

void writeWord(FILE *file, char *word);
void createWordsTxtFile(FILE *writeFile, FILE *readFile, int totalWords, char taker, int wct, char *word, char *trashRead);

/// @brief imports the exported wbdata.txt file
void importMenu()
{
    /* variables */
    char trashRead[1025];
    char fullLine[1025];
    char word[65];
    char taker; 
    int wct = 0;

    /* file paths */
    char wordsFilePath[128];  /* words.txt path */

    /* initalizing words.txt file path */
    sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

    /* totalwords */
    FILE *totalWordsFile = fopen("wbdata.txt", "r");

    if (totalWordsFile == NULL)
    {
        fileNotFoundError("wbdata.txt");
        exit(0);
    }

    int totalWords = takeFileLength(totalWordsFile);

    fclose(totalWordsFile);

    /* words.txt file */
    FILE *wordstxtFile = fopen(wordsFilePath, "w");
    FILE *wbDataTxtFile = fopen("wbdata.txt", "r");

    createWordsTxtFile(wordstxtFile, wbDataTxtFile, totalWords, taker, wct, word, trashRead);
}

/// @brief the function for writing the words
/// @param file 
/// @param word 
void writeWord(FILE *file, char *word)
{
    fputs(word, file);
    fputc('\n', file);
}

void createWordsTxtFile(FILE *writeFile, FILE *readFile, int totalWords, char taker, int wct, char *word, char *trashRead)
{
    /* variables */
    char wordFilePath[128];  /* path for words */
    char writingLine[1025]; /* for storing all line data */
    
    FILE *wordGenerationFile;

    /* words.txt file creation */
    for (int i = 0; i < totalWords; i++)
    {
        do 
        {
            taker = fgetc(readFile);

            if (taker != ':')
            {
                word[wct] = taker;
                wct++;
            }
        } while (taker != ':');

        /* null terminating */
        word[wct] = '\0';

        /* writes the word to words.txt file */
        writeWord(writeFile, word);

        /* go to the next line of wbdata.txt and read for the word file */
        fgets(trashRead, 1024, readFile);

        /* create a string for word */
        sprintf(wordFilePath, "%s/.wb/%s.txt", getenv("HOME"), word);

        /* creates the word file */
        wordGenerationFile = fopen(wordFilePath, "w");

        /* initializes the full line */
        sprintf(writingLine, "%s:%s", word, trashRead);

        /* writes the data to file */
        fputs(writingLine, wordGenerationFile);

        /* resets wct */
        wct = 0;

        /* closes the stream */
        if (i == totalWords - 1)
        {
            fclose(wordGenerationFile);
        }
    }

    /* close file streams */
    fclose(writeFile);
    fclose(readFile);

    /* write information */
    importedInfo();
}