/** 
 * @file verifyFileStructureError.c
 * 
 * @brief prints the verify function file structure availability error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 11/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints error information and solving advice about the file structure error
void verifyFileStructureError()
{
    fprintf(stderr, "%swb:%s error in the file structure, %susr/bin/wb and usr/local/wb are not found%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stderr, "%swb:%s create file structure, %srun the install.sh file and try to run again%s\n", BOLD, RESET, KMAG, KNRM);
}