/** 
 * @file importedInfo.c
 * 
 * @brief prints the importion info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 02/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the importion info
void importedInfo()
{
    fprintf(stdout, "%swb:%s application data imported, %snew words added to the system%s\n",BOLD, RESET, KMAG, KNRM);
}