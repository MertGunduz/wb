/**
 * @file wordsTxtFileNotFoundError.c
 *
 * @brief prints words.txt file not found
 *
 * @author Mehmet Mert Gunduz
 *
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints words.txt file not found
void wordsTxtFileNotFoundError()
{
    fprintf(stderr, "%swb:%s words.txt not found, %splease check the /home/.wb/words.txt%s\n",BOLD, RESET, KMAG, KNRM);
}
