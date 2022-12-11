/** 
 * @file verifyArgcError.c
 * 
 * @brief the function for printing verify argc count error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

void verifyArgcError(int argc)
{
    if (argc == 1)
    {
        fprintf(stdout, "%swb:%s Error in the size of argc: %smissing arguments%s\n",BOLD, RESET, KMAG, KNRM);
    }
    else
    {
        fprintf(stdout, "%swb:%s Error in the size of argc: %stoo many arguments%s\n", BOLD, RESET, KMAG, KNRM);
    }

    fprintf(stdout, "%swb:%s Size of argc: %d\n", BOLD, RESET, argc);
}