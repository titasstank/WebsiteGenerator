#include <stdio.h>
#include <stdlib.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"

int failedToCopy = 0;
void copyFromFileToFile(FILE *destinationFile, char *sourceFileName) {
    FILE *sourceFile;
    if ((sourceFile = fopen(sourceFileName, "r")) == NULL) {
        printf("Could not open file to copy contents from. Page has not been built sucesfully!\n");
        failedToCopy = 1;
    }
    while (!feof(sourceFile)) {
        char buffer[COPY_BUFFER_SIZE] = {'\0'};
        fgets(buffer, COPY_BUFFER_SIZE + 1, sourceFile);
        fputs(buffer, destinationFile);
    }
}

void buildPage(Categories *DATA, unsigned int workingCategory) {
    char pageFileName[MAX_FOLDER_LENGTH];
    sprintf(pageFileName, "%s%s%s", PAGE_FOLDER, DATA->name[workingCategory], PAGE_FILE_EXTENSION);
    FILE *pageFile = fopen(pageFileName, "w");
    char sourceFileName[MAX_FOLDER_LENGTH];
    //Copy page start
    sprintf(sourceFileName, "%s%s", TEMPLATE_FOLDER, PAGE_START_TEMPLATE_NAME);
    copyFromFileToFile(pageFile, sourceFileName);
    //Copy page description
    sprintf(sourceFileName, "%s%s%s%s", LOG_FOLDER, DATA->name[workingCategory], DESCRIPTION_TAG, LOG_FILE_EXTENSION);
    copyFromFileToFile(pageFile, sourceFileName);
    //Copy all messages
    for (int i = 0; i < DATA->CatMessages[workingCategory].numMessages; ++i) {
        sprintf(sourceFileName, "%s%s_%s%s", LOG_FOLDER, DATA->name[workingCategory],
                DATA->CatMessages[workingCategory].Messages[i], LOG_FILE_EXTENSION);
        copyFromFileToFile(pageFile, sourceFileName);
    }
    //Copy page end
    sprintf(sourceFileName, "%s%s", TEMPLATE_FOLDER, PAGE_END_TEMPLATE_NAME);
    copyFromFileToFile(pageFile, sourceFileName);
    fclose(pageFile);
    if (!failedToCopy){
        SEPARATOR;
        printf("Page built successfully!\n");
        SEPARATORIND;
    }
}

void editNavBar(Categories *DATA) { //TODO: edit nav bar

}