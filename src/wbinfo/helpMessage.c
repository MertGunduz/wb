/** 
 * @file helpMessage.c
 * 
 * @brief the function for printing the help information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/12/2022
 * @bug No known bugs.
*/

#include "wbinfo.h"

/// @brief prints the help information
void helpMessage()
{
    fprintf(stdout, "usage: wb [OPTION]\n");
    fprintf(stdout, "easily take vocabulary notes and manage them\n");
    fprintf(stdout, "example: wb --add\n\n");
    fprintf(stdout, "options and descriptions\n");
    fprintf(stdout, "%s-s, --settings%s     opens a settings ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-a, --add%s          opens a word adding ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-e, --edit%s         opens a word editing ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-l, --list%s         opens a word list ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-E, --export%s       opens a export data ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-I, --import%s       opens a import data ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-h, --help%s         outputs help information\n", KMAG, KNRM);
    fprintf(stdout, "%s-v, --version%s      outputs version information\n", KMAG, KNRM);
    fprintf(stdout, "%s-g, --github%s       outputs github url information\n\n", KMAG, KNRM);
    fprintf(stdout, "issues and bugs related to wb\n");
    fprintf(stdout, "open an issue: %shttps://github.com/MertGunduz/wb/issues/new%s\n", KMAG, KNRM);
}