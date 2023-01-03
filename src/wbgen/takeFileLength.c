/** 
 * @file takeFileLength.c
 * 
 * @brief takes the total lines of a txt file 
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief takes the total lines of a txt file 
/// @param file 
/// @return total lines of the text
int takeFileLength(FILE *file)
{
    int totalWords = 0;
    char wordReaderTrashVar[1025];

    if (file == NULL)
    {
        fileReadErrorMessage();
        exit(0);
    }

    while (!feof(file))
    {
        fgets(wordReaderTrashVar, 1024, file);
        totalWords++;
    }

    /* corrector for totalwords */
    totalWords--;

    return totalWords;
}