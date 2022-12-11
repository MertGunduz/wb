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
 * @version 1.0.0
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief the system control function for wb, it checks the usr/bin/wb (executable) and usr/local/wb (folder)
/// @param argc 
/// @return true if argc is 2 and file structure found, otherwise returns false
bool verify(int argc)
{
    if (argc == 2)
    {
        struct stat st;

        if (access("/usr/bin/wb", F_OK) == 0 && stat("/usr/local/wb", &st) == 0)
        {   
            return true;
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