/** 
 * @file wbgen.h
 * 
 * @brief the general wb library for generating word files and listing
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../wbinfo/wbinfo.h"

bool verify(int argc, char *firstArgv);