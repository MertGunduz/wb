/** 
 * @file terminalColorError.c
 * 
 * @brief the function for printing terminal color capability error
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 17/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the terminal color capability error
void terminalColorError()
{
    fprintf(stdout, "%swb:%s terminal color capability error, %splease use a color-supporting terminal%s\n",BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb:%s try using %sxterm-256color%s\n",BOLD, RESET, KMAG, KNRM);
}