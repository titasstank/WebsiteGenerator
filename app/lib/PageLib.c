#include <stdio.h>
#include <stdlib.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "MessageLib.h"

extern Categories *DATA;

int failedToCopy = 0;
void copyFromFileToFile(FILE *destinationFile, char *sourceFileName) {
    FILE *sourceFile;
    if ((sourceFile = fopen(sourceFileName, "r")) == NULL) {
        SEPARATOR;
        printf(PAGE_BUILDPAGE_FAIL);
        SEPARATOR;
        failedToCopy = 1;
    }
    while (!feof(sourceFile)) {
        char buffer[COPY_BUFFER_SIZE] = {'\0'};
        fgets(buffer, COPY_BUFFER_SIZE + 1, sourceFile);
        fputs(buffer, destinationFile);
    }
}

int buildPage(unsigned int workingCategory) {
    char pageFileName[MAX_FOLDER_LENGTH];
    sprintf(pageFileName, "%s%s%s", PAGE_FOLDER, DATA->name[workingCategory], PAGE_FILE_EXTENSION);
    FILE *pageFile = fopen(pageFileName, "w");
    char sourceFileName[MAX_FOLDER_LENGTH];

    //Copy page start
    sprintf(sourceFileName, "%s%s%s", TEMPLATE_FOLDER, PAGE_START, LOG_FILE_EXTENSION);
    copyFromFileToFile(pageFile, sourceFileName);

    //Copy page description
    sprintf(sourceFileName, "%s%s%s%s", LOG_FOLDER, DATA->name[workingCategory], DESCRIPTION_TAG, LOG_FILE_EXTENSION);
    copyFromFileToFile(pageFile, sourceFileName);

    //Copy all messages
    for (int i = DATA->CatMessages[workingCategory].numMessages - 1; i >= 0; --i) {
        sprintf(sourceFileName, "%s%s_%s%s", LOG_FOLDER, DATA->name[workingCategory], DATA->CatMessages[workingCategory].Messages[i], LOG_FILE_EXTENSION);
        copyFromFileToFile(pageFile, sourceFileName);
    }

    //Copy page end
    sprintf(sourceFileName, "%s%s%s", TEMPLATE_FOLDER, PAGE_END, LOG_FILE_EXTENSION);
    copyFromFileToFile(pageFile, sourceFileName);
    fclose(pageFile);
    int fail = failedToCopy;
    failedToCopy = 0;
    return fail;
}

void buildNavBar() {
    // Preparing start template file
    char destinationFileName[MAX_FOLDER_LENGTH];
    sprintf(destinationFileName, "%s%s%s", TEMPLATE_FOLDER, PAGE_START, LOG_FILE_EXTENSION);
    FILE *destinationFile;
    if((destinationFile = fopen(destinationFileName, "w")) == NULL){
        printf(PAGE_DESOPEN_FAIL);
    }

    char sourceFileName[MAX_FOLDER_LENGTH];
    // Copy nav start
    sprintf(sourceFileName, "%s%s%s", TEMPLATE_FOLDER, NAV_START, LOG_FILE_EXTENSION);
    copyFromFileToFile(destinationFile, sourceFileName);

    // Build every page into the navbar
    for(int i = 1; i < DATA->numCategories; ++i){
        fprintf(destinationFile, NAVBAR_LINE, DATA->name[i], DATA->name[i]);
    }

    //Copy nav end
    sprintf(sourceFileName, "%s%s%s", TEMPLATE_FOLDER, NAV_END, LOG_FILE_EXTENSION);
    copyFromFileToFile(destinationFile, sourceFileName);
    fclose(destinationFile);

    // Rebuild all pages so they have updated nav bars
    for(int i = 0; i < DATA->numCategories; ++i){
        fetchMessages(i);
        buildPage(i);
    }
}
