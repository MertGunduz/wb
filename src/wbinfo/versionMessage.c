/** 
 * @file versionMessage.c
 * 
 * @brief the function for printing the wb version
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the wb version
void versionMessage()
{
    fprintf(stdout, "%swb:%s version %s1.0.0%s\n", BOLD, RESET, KMAG, KNRM);
}