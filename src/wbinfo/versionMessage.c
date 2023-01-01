/** 
 * @file versionMessage.c
 * 
 * @brief prints the wb version
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the wb version
void versionMessage()
{
    fprintf(stdout, "wb (wordbook) version %s1.0.0%s\n", KMAG, KNRM);
    fprintf(stdout, "license GPL 3.0: GNU GPL version 3 %shttps://gnu.org/licenses/gpl.html%s\n", KMAG, KNRM);
    fprintf(stdout, "this is a free software: you are free to change and redistribute it.\n");
    fprintf(stdout, "there is no warranty, to the extent permitted by law.\n\n");
    fprintf(stdout, "developed by Mehmet Mert Gunduz and others.\n");
}