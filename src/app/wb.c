/** 
 * @file wb.c
 * 
 * @brief the main application file of wb
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @bug No known bugs.
*/

#include "../wbgen/wbgen.h"

int main(int argc, char *argv[])
{
    if (verify(argc, argv[1]))
    {
        if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--settings") == 0)
        {
            fprintf(stdout, "settings menu!\n");
        }
        else if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--add") == 0)
        {
            addMenu();
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
            versionMessage();
        }
        else if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--github") == 0) 
        {
            githubMessage();
        }
        else if (strcmp(argv[1], "-E") == 0 || strcmp(argv[1], "--export") == 0) 
        {
            fprintf(stdout, "export menu!\n");
        }    
        else if (strcmp(argv[1], "-I") == 0 || strcmp(argv[1], "--import") == 0) 
        {
            fprintf(stdout, "import menu!\n");
        }    
    }
    return 0;
}