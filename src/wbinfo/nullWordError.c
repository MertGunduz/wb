/** 
 * @file nullWordError.c
 * 
 * @brief prints null word error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints null word error info
void nullWordError()
{
    fprintf(stderr, "%swb:%s error in the word argument, %sthe word argument is missing%s\n",BOLD, RESET, KMAG, KNRM);
}