/**
 * @file getWordData.c
 * 
 * @brief extracts the data from total word line
 * 
 * @author Mehmet Mert Gunduz
 * @date 01/01/2023
 * @bug No known bugs.
*/

/// @brief extracts the data from total word line
/// @param totalLine 
/// @param wWordData 
/// @param wTypeData 
/// @param wOppositeData 
/// @param wdescData 
/// @param wExData 
/// @param wDateData 
void getWordData(char *totalLine, char *wWordData, char *wTypeData, char *wOppositeData, char *wdescData, char *wExData, char *wDateData)
{
    /* tokenizing string */
    int tlCt = 0, clCt = 0;
    int wordI = 0, typeI = 0, oppositeI = 0, descI = 0, exI = 0, dateI = 0;

    do
    {
        if (totalLine[tlCt] != ':')
        {
            switch (clCt)
            {
                case 0:
                    wWordData[wordI] = totalLine[tlCt];
                    wordI++;
                    break;
                case 1:
                    wTypeData[typeI] = totalLine[tlCt];
                    typeI++;
                    break;
                case 2:
                    wOppositeData[oppositeI] = totalLine[tlCt];
                    oppositeI++;
                    break;
                case 3:
                    wdescData[descI] = totalLine[tlCt];
                    descI++;
                    break;
                case 4:
                    wExData[exI] = totalLine[tlCt];
                    exI++;
                    break;
                case 5:
                    wDateData[dateI] = totalLine[tlCt];
                    dateI++;
                    break;
            }
        }
        else
        {
            clCt++;
        }

        tlCt++;
    } while (totalLine[tlCt] != '\0');

    /* adding the null terminators */
    wWordData[wordI] = '\0'; 
    wTypeData[typeI] = '\0';
    wOppositeData[oppositeI] = '\0';
    wdescData[descI] = '\0';
    wExData[exI] = '\0';
    wDateData[dateI] = '\0';
}