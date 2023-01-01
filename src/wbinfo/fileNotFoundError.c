/** 
 * @file fileNotFoundError.c
 * 
 * @brief prints the false file name info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the false file name info
void fileNotFoundError(char *word)
{
    fprintf(stdout, "%swb:%s file not found, %swrong file name or file doesn't exist%s\n",BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb:%s file input: %s%s.txt%s\n",BOLD, RESET, KMAG, word, KNRM);
}