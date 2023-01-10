#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"

char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                       "November", "December"};

void formatMessage(char *categoryName, char *messageTitle, char *message)
{
    // Create log file
    char messageFile[MAX_FOLDER_LENGTH];
    sprintf(messageFile, "%s%s_%s%s", LOG_FOLDER, categoryName, messageTitle, LOG_FILE_EXTENSION);
    FILE *file = fopen(messageFile, "w");

    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(file, POST_BEGIN, messageTitle, months[tm.tm_mon], tm.tm_mday, tm.tm_year + 1900);
    fprintf(file, "%s", message);
    fprintf(file, POST_END);

    fclose(file);
}