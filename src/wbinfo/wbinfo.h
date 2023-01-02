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

#include <ncurses.h>

#define KNRM  "\x1B[0m"  /**< makes the the text normal color */
#define KRED  "\x1B[31m" /**< makes the text red color*/
#define KMAG  "\x1B[35m" /**< makes the text magenta color*/
#define KCYN  "\x1B[36m" /**< makes the text cyan color*/

#define BOLD "\x1B[1m" /**< makes the text bold*/
#define RESET "\x1B[0m" /**< makes the text normal*/

void verifyArgcError(int argc);
void verifyFileStructureError();
void verifyArgumentError(char *argv);
void helpMessage();
void githubMessage();
void versionMessage();
void terminalColorError();
void fileReadErrorMessage();
void nullWordError();
void fileNotFoundError(char *word);
void wordsTxtFileNotFoundError();
void cantCreatewbdataFile();
void exportedInfo();
void noWordsInfo();