/** 
 * @file verify.c
 * 
 * @brief the system control function for wb, it checks the usr/bin/wb (executable) and usr/local/wb (folder)
 * @brief <u>usr/bin/wb:</u> the executable for the program
 * @brief <u>usr/local/wb:</u> the folder for the words
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 12/10/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

char *arguments[] = {"-s", "--settings", "-a", "--add", "-e", "--edit", "-l", "--list", "-h", "--help", "-v", "--version", "-g", "--github", "-E", "--export", "-I", "--import" };
int argSize = 18;

/// @brief the system control function for wb, it checks the usr/bin/wb (executable) and usr/local/wb (folder)
/// @param argc 
/// @return true if argc is 2 and file structure found, otherwise returns false
bool verify(int argc, char *firstArgv)
{
    // controls the argc value
    if (argc == 2)
    {
        // struct stat for controlling directory /usr/local/wb
        struct stat st;

        // .wb paths
        char folderPath[128]; 
        char wordsFilePath[128];

        // making the path strings 
        sprintf(folderPath, "%s/.wb", getenv("HOME"));
        sprintf(wordsFilePath, "%s/.wb/words.txt", getenv("HOME"));

        // controllign the file and folder /usr/local/wb and home/.wb
        if (access("/usr/bin/wb", F_OK) == 0 && access(wordsFilePath, F_OK) == 0 && stat(folderPath, &st) == 0)
        {   
            // controlling the argv[1]
            for (int i = 0; i < argSize; i++)
            {
                if (strcmp(firstArgv, arguments[i]) == 0)
                {
                    return true;
                }
            }

            // return false if argument not matched the arguments array values
            verifyArgumentError(firstArgv);
            return false;
        }
        else
        {
            verifyFileStructureError();
            return false;
        }
    }
    else
    {
        verifyArgcError(argc);
        return false;
    }
}