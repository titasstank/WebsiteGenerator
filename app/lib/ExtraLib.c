#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "MessageLib.h"

extern Categories *DATA;

void printCredits() {
    FILE *cr;
    char buffer[COPY_BUFFER_SIZE];

    CLEAR;
    if ((cr = fopen(CREDITS_PATH, "r")) != NULL){
        while (fgets(buffer, COPY_BUFFER_SIZE, cr) != NULL){
            printf("%s", buffer);
        }
    } else {
        SEPARATOR;
        printf(EXTRA_OPENCRED_FAIL);
        SEPARATOR;
    }
    PAUSE;
    CLEAR;
    fclose(cr);
};

void printDebugList(){
    for (int i = 0 ; i < DATA->numCategories ; ++i){
        printf("%d. %s\n", i + 1, DATA->name[i]);
        fetchMessages(i);
        for (int j = 0 ; j < DATA->CatMessages[i].numMessages ; ++j){
            printf("    %d.%d. %s\n", i + 1, j + 1, DATA->CatMessages[i].Messages[j]);
        }
    }
}

void printDebug(){
    SEPARATOR;
    printf(EXTRA_GLOBAL_VAR);
    printf(EXTRA_NUMBER_CAT, DATA->numCategories);
    printDebugList();
}

int getValidatedInt(){
    int num;
    if (scanf("%u", &num) == 1 && getchar() == '\n'){
        return num;
    } else {
        while(getchar() != '\n');
        return -1;
    }
}

unsigned char checkForDuplicates(char *newString, char (*existingStrings)[MAX_TITLE], unsigned size){
    for(int i = 0; i < size; ++i){
        if(strcmp(newString, existingStrings[i]) == 0){
            return 1;
        printf("hello guys\n");
        }
    }
    return 0;
}