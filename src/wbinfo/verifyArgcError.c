/** 
 * @file verifyArgcError.c
 * 
 * @brief the function for printing verify function argc count error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief controls the argc, if the argc value equals to 1 writes "missing arguments", if not writes "too many arguments"
/// @param argc 
void verifyArgcError(int argc)
{
    if (argc == 1)
    {
        fprintf(stdout, "%swb:%s error in the size of argc, %smissing arguments%s\n",BOLD, RESET, KMAG, KNRM);
    }
    else
    {
        fprintf(stdout, "%swb:%s error in the size of argc, %stoo many arguments%s\n", BOLD, RESET, KMAG, KNRM);
    }

    fprintf(stdout, "%swb:%s size of argc: %d\n", BOLD, RESET, argc);
}