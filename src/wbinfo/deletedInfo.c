/** 
 * @file deletedInfo.c
 * 
 * @brief prints the deletion info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the deletion info
void deletedInfo(char *word)
{
    fprintf(stdout, "%swb:%s deletion successful, %s%s word deleted from the system%s\n",BOLD, RESET, KMAG, word, KNRM);
}