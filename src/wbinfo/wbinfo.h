/** 
 * @file wbinfo.h
 * 
 * @brief the general wb library for printing information messages
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 10/12/2022
 * @version 1.0.0
 * @bug No known bugs.
*/

#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

void verifyArgcError();