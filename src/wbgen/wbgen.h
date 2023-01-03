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

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include "../wbinfo/wbinfo.h"

#define PURE_BLACK_COLOR 100

bool verify(int argc, char *firstArgv);
void addMenu();
bool colorCheck();
void bgColorSet();
void textInput(WINDOW *window, int ct, int wordstrlen, int winX, char *string, int locationSetter);
void fullrefresh(WINDOW *window);
void listMenu();
void wordMenu(char *word);
void getWordData(char *totalLine, char *wWordData, char *wTypeData, char *wOppositeData, char *wdescData, char *wExData, char *wDateData);
void deleteMenu(char *word);
int takeFileLength(FILE *file);
void exportMenu();
void importMenu();
void writeKey(WINDOW *window, char key, char *keyExp, bool isSeperate);