/** 
 * @file nullWordError.c
 * 
 * @brief the function for printing null word error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief the function for printing null word error info
void nullWordError()
{
    fprintf(stdout, "%swb:%s error in the word argument, %sthe word argument is missing%s\n",BOLD, RESET, KMAG, KNRM);
}