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

        if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--word") == 0)
        {
            wordMenu(argv[2]);
        }
        else if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--add") == 0)
        {
            addMenu();
        }
        else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--delete") == 0) 
        {
            deleteMenu(argv[2]);
        }
        else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) 
        {
            listMenu();
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
            exportMenu();
        }    
        else if (strcmp(argv[1], "-I") == 0 || strcmp(argv[1], "--import") == 0) 
        {
            importMenu();
        }    
    }
    return 0;
}