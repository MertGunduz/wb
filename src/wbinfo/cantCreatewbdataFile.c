/** 
 * @file cantCreatewbdataFile.c
 * 
 * @brief prints can't create wbdata.txt file info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 02/01/2023
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints can't create wbdata.txt file info
void cantCreatewbdataFile()
{
    fprintf(stderr, "%swb:%s wbdata.txt not created, %splease check working directory permissions%s\n",BOLD, RESET, KMAG, KNRM);
}