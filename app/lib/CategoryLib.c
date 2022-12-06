#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "MessageLib.h"

/* fetchCategories */
/* Copies the number of categories and the categories to the structure from the specified file */

void fetchCategories(FILE *logCategories, Categories *DATA) {
    int numCat;
    char category[MAX_CATEGORY_NAME];

    fscanf(logCategories, "%d", &numCat);
    if (fgets(category, MAX_CATEGORY_NAME, logCategories) != NULL) {
        DATA->numCategories = numCat;
        for (int i = 0; i < numCat; ++i) {
            fgets(category, MAX_CATEGORY_NAME, logCategories);
            REMOVENEWL(category);
            strcpy(DATA->name[i], category);
        }
    }
}

/* printCatList */
/* Prints the list of the categories from the structure */

void printCatList(Categories *DATA) {
    SEPARATOR;
    if (DATA->numCategories != 0) {
        for (int i = 0; i < DATA->numCategories; ++i) {
            printf("%d. %s\n", i + 1, DATA->name[i]);
        }
    } else
        printf("The category list is empty!");
    SEPARATORIND;
}

/* addCategory */
/* Adds a category to the structure */

void addCategory(Categories *DATA) {
    int numCat;
    char category[MAX_CATEGORY_NAME];
    numCat = DATA->numCategories;

    SEPARATOR;
    printf("Please enter a category name:");
    if (fgets(category, MAX_CATEGORY_NAME, stdin) != NULL) {
        REMOVENEWL(category);
        strcpy(DATA->name[numCat], category);
    }
    createCategoryDescription(DATA->name[numCat]);
    formLogFile(DATA->name[numCat]);
    DATA->numCategories = (DATA->numCategories) + 1;
}

/* deleteCategory */
/* Deletes a category from the structure */

void deleteCategory(Categories *DATA, int choice) {
    for (int i = choice - 1; i < DATA->numCategories; ++i) {
        strcpy(DATA->name[i], DATA->name[i + 1]);
    }
    DATA->numCategories = (DATA->numCategories) - 1;
}

/* fillCatLog */
/* Puts the number of categories and categories form the structure to the specified file */

void fillCatLog(FILE *logCategories, Categories *DATA) {
    fprintf(logCategories, "%d\n", DATA->numCategories);
    for (int i = 0; i < DATA->numCategories; ++i) {
        fprintf(logCategories, "%s\n", DATA->name[i]);
    }
}

/* formCatLogFile */
/* Forms a log file for a certain category if there is none */

void formLogFile(char *filename) {
    FILE *file;
    char complName[MAX_FOLDER_LENGTH];

    REMOVENEWL(filename);
    sprintf(complName, "%s%s%s", LOG_FOLDER, filename, LOG_FILE_EXTENSION);

    if ((file = fopen(complName, "r")) == NULL) {
        file = fopen(complName, "w");
        fprintf(file, "0\n");
        fclose(file);
    } else
        fclose(file);
}

void createCategoryDescription(char *categoryName) { // Creates formatted category description log
    char *categoryDescription;
    askForTextInput("Please choose a description for your new category (50 characters limit): ", &categoryDescription,
                    MAX_CATEGORY_DESCRIPTION);
    REMOVENEWL(categoryDescription);
    // Create log file
    char descriptionLogFileName[MAX_FOLDER_LENGTH];
    sprintf(descriptionLogFileName, "%s%s%s%s", LOG_FOLDER, categoryName, DESCRIPTION_TAG, LOG_FILE_EXTENSION);
    FILE *descriptionLogFile = fopen(descriptionLogFileName, "w");
    // Write formated description
    fprintf(descriptionLogFile, "%s\n%s\n%s\n", CATEGORY_DESCRIPTION, categoryDescription, H3);
    fclose(descriptionLogFile);
    free(categoryDescription);
}
