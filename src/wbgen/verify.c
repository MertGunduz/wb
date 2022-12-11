/** 
 * @file verify.c
 * 
 * @brief the system control function for wb, it basically checks the <u>usr/bin/wb (executable)</u> and <u>usr/local/wb (folder)</u>.
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

bool verify(int argc)
{
    if (argc == 2)
    {
        struct stat st; /**< for testing the directory */

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