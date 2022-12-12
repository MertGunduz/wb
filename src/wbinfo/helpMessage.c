/** 
 * @file helpMessage.c
 * 
 * @brief the function for printing the help information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the help information
void helpMessage()
{
    fprintf(stdout, "%swb%s word adding menu: %swb -a%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb%s word editing menu: %swb -e%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb%s list menu: %swb -l%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb%s help: %swb -h%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb%s version: %swb -v%s\n", BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb%s github: %swb -g%s\n", BOLD, RESET, KMAG, KNRM);
}