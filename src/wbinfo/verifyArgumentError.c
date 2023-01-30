/** 
 * @file verifyArgumentError.c
 * 
 * @brief prints the verify argv mismatch
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the mismatched argv and adivces to get help by writing the -h or --help argument
/// @param argv
void verifyArgumentError(char *argv)
{
    fprintf(stderr, "%swb:%s invalid option, %s%s%s\n",BOLD, RESET, KMAG, argv, KNRM);
    fprintf(stderr, "%swb:%s try %s--help or -h%s for more information\n",BOLD, RESET, KMAG, KNRM);
}