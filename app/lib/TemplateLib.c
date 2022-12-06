#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"

char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                       "November", "December"};

void formatBasicMessage(char *categoryName, char *messageTitle, char *message) {
    // Create log file
    char messageFile[MAX_FOLDER_LENGTH];
    sprintf(messageFile, "%s%s_%s%s", LOG_FOLDER, categoryName, messageTitle, LOG_FILE_EXTENSION);
    FILE *file = fopen(messageFile, "w");


    fprintf(file, "%s\n", ARTICLE_BEGINNING);
    fprintf(file, "%s%s%s\n", BLOG_TITLE, messageTitle, H2);
    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(file, "%s%s %d, %d%s\n", BLOG_DATE, months[tm.tm_mon], tm.tm_mday, tm.tm_year + 1900, P_CLOSE);
    fprintf(file, "%s\n%s\n%s\n", BLOG_MESSAGE, message, P_CLOSE);
    fprintf(file, "%s\n", ARTICLE_ENDING);

    fclose(file);
}