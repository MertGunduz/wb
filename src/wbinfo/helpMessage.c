/** 
 * @file helpMessage.c
 * 
 * @brief prints the help information
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
    fprintf(stdout, "easily take vocabulary notes and manage them\n\n");
    fprintf(stdout, "options without arguments\n");
    fprintf(stdout, "%s-a, --add%s            opens a word generation ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-l, --list%s           opens a word list ui menu\n", KMAG, KNRM);
    fprintf(stdout, "%s-E, --export%s         exports wb data to wbdata.txt\n", KMAG, KNRM);
    fprintf(stdout, "%s-I, --import%s         imports wb data by using wbdata.txt\n", KMAG, KNRM);
    fprintf(stdout, "%s-h, --help%s           outputs help information\n", KMAG, KNRM);
    fprintf(stdout, "%s-v, --version%s        outputs version information\n", KMAG, KNRM);
    fprintf(stdout, "%s-g, --github%s         outputs github url information\n\n", KMAG, KNRM);
    fprintf(stdout, "options with arguments\n");
    fprintf(stdout, "%s-d, --delete [WORD]%s  deletes a word file\n", KMAG, KNRM);
    fprintf(stdout, "%s-w, --word [WORD]%s    outputs word information\n\n", KMAG, KNRM);
    fprintf(stdout, "issues and bugs related to wb\n");
    fprintf(stdout, "open an issue: %shttps://github.com/MertGunduz/wb/issues/new%s\n", KMAG, KNRM);
}