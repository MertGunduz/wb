/** 
 * @file exportedInfo.c
 * 
 * @brief prints the false file name info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 02/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the false file name info
void exportedInfo()
{
    fprintf(stdout, "%swb:%s application data exported, %swbdata.txt created%s\n",BOLD, RESET, KMAG, KNRM);
}