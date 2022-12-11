#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"

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
        printf("Credits file does not exist or path is wrong!\n");
        SEPARATOR;
    }
    PAUSE;
    CLEAR;
    SEPARATOR;
    fclose(cr);
};

void printDebug(Categories *DATA) {
    SEPARATOR;
    printf("Global variables:\n\n");
    printf("Number of categories: %d\n", DATA->numCategories);
    printCatList(DATA);
}
