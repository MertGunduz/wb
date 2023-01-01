/**
 * @file fileReadErrorMessage.c
 *
 * @brief prints the file access error information
 *
 * @author Artem Romanov
 *
 * @date 27/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the file access error information
void fileReadErrorMessage()
{
    fprintf(stdout, "%swb:%s file access error, %splease check the file permissions%s\n",BOLD, RESET, KMAG, KNRM);
    fprintf(stdout, "%swb:%s try giving permission %s755%s\n",BOLD, RESET, KMAG, KNRM);
}
