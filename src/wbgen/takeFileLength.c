/** 
 * @file takeFileLength.c
 * 
 * @brief the function for taking the total lines in a txt file 
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief the function for taking the total lines in a txt file 
/// @param file 
/// @return total lines of the text
int takeFileLength(FILE *file)
{
    int totalWords = 0;
    char wordReaderTrashVar[65];

    if (file == NULL)
    {
        fileReadErrorMessage();
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