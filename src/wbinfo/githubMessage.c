/** 
 * @file githubMessage.c
 * 
 * @brief the function for printing the github source code information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the github source code url
void githubMessage()
{
    fprintf(stdout, "%swb:%s %shttps://github.com/MertGunduz/wb%s\n", BOLD, RESET, KMAG, KNRM);
}