/** 
 * @file noWordsInfo.c
 * 
 * @brief prints no words info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 02/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints no words info
void noWordsInfo()
{
    fprintf(stdout, "%swb:%s no words in words.txt, %scan\'t export data%s\n",BOLD, RESET, KMAG, KNRM);
}