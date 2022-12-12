/** 
 * @file wb.c
 * 
 * @brief the main application file of wb
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include <stdio.h>
#include <ncurses.h>
#include "../wbgen/wbgen.h"

int main(int argc, char *argv[])
{
    if (verify(argc, argv[1]))
    {
        if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--add") == 0)
        {
            fprintf(stdout, "add menu!\n");
        }
        else if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--edit") == 0) 
        {
            fprintf(stdout, "edit menu!\n");
        }
        else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) 
        {
            fprintf(stdout, "list menu!\n");
        }
        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) 
        {
            helpMessage();
        }
        else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) 
        {
            fprintf(stdout, "version menu!\n");
        }
        else if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--github") == 0) 
        {
            githubMessage();
        }
    }
    return 0;
}