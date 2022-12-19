/** 
 * @file githubMessage.c
 * 
 * @brief the function for printing the github source code information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the github source code url
void githubMessage()
{
    fprintf(stdout, "wb %shttps://github.com/MertGunduz/wb%s\n\n", KMAG, KNRM);
    fprintf(stdout, "contributing to wb\n");
    fprintf(stdout, "you can open issues if you have errors: %shttps://github.com/MertGunduz/wb/issues/new%s\n", KMAG, KNRM);
    fprintf(stdout, "you can solve the issues and pull request to repo: %shttps://github.com/MertGunduz/wb/issues%s\n", KMAG, KNRM);
}