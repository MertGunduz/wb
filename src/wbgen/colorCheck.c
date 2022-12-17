/**
 * @file colorCheck.c
 * 
 * @brief checks the terminal color capabilities
 * 
 * @author Mehmet Mert Gunduz
 * @date 17/12/2022
 * @bug No known bugs.
*/

#include "wbgen.h"

/// @brief checks the terminal color capabilities
bool colorCheck()
{
    if (has_colors() && can_change_color())
    {
        return true;
    }
}