#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "MessageLib.h"
#include "PageLib.h"

Categories *DATA;

/* fetchCategories */
/* Copies the number of categories and the categories to the structure from the specified file */

void fetchCategories(FILE *logCategories) {
    char category[MAX_CATEGORY_NAME];

    fscanf(logCategories, "%d", &(DATA->numCategories));
    if (fgets(category, MAX_CATEGORY_NAME, logCategories) != NULL) {
        for (int i = 0; i < DATA->numCategories; ++i) {
            fgets(category, MAX_CATEGORY_NAME, logCategories);
            REMOVENEWL(category);
            strcpy(DATA->name[i], category);
        }
    }
}

/* printCatList */
/* Prints the list of the categories from the structure */

void printCatList() {
    SEPARATOR;
    if (DATA->numCategories != 0) {
        printf("Categories:\n\n");
        for (int i = 0; i < DATA->numCategories; ++i) {
            printf("%d. %s\n", i + 1, DATA->name[i]);
        }
    } else
        printf("The category list is empty!\n");
    SEPARATOR;
}

/* fillCatLog */
/* Puts the number of categories and categories form the structure to the specified file */

void fillCatLog(FILE *logCategories) {
    fprintf(logCategories, "%d\n", DATA->numCategories);
    for (int i = 0; i < DATA->numCategories; ++i) {
        fprintf(logCategories, "%s\n", DATA->name[i]);
    }
}

/* addCategory */
/* Adds a category to the structure */

void addCategory() {
    char category[MAX_CATEGORY_NAME];

    SEPARATOR;
    printf("Please enter a category name:\n");
    SEPARATOR;
    if (fgets(category, MAX_CATEGORY_NAME, stdin) != NULL) {
        REMOVENEWL(category);
        strcpy(DATA->name[DATA->numCategories], category);
    }
    CLEAR;
    createCategoryDescription(DATA->name[DATA->numCategories]);
    formLogFile(DATA->name[DATA->numCategories]);
    DATA->numCategories = (DATA->numCategories) + 1;

    CLEAR;
    SEPARATOR;
    printf("Created category %d - %s\n", DATA->numCategories, category);
    buildNavBar(DATA);
}

/* deleteCategory */
/* Deletes a category from the structure */

void deleteCategory(int choice) {
    fetchMessages(choice);
    // Delete all the files
    for(int i = 0; i < DATA->CatMessages[choice].numMessages; ++i){
        char messageLogFileName[MAX_FOLDER_LENGTH];
        sprintf(messageLogFileName, "%s%s_%s%s", LOG_FOLDER, DATA->name[choice], DATA->CatMessages[choice].Messages[i], LOG_FILE_EXTENSION);
        DELETE_FILE(messageLogFileName);
    }
    // Delete category log, category description and page
    char categoryLogFileName[MAX_FOLDER_LENGTH];
    sprintf(categoryLogFileName, "%s%s%s", LOG_FOLDER, DATA->name[choice], LOG_FILE_EXTENSION);
    DELETE_FILE(categoryLogFileName);
    sprintf(categoryLogFileName, "%s%s%s%s", LOG_FOLDER, DATA->name[choice], DESCRIPTION_TAG, LOG_FILE_EXTENSION);
    DELETE_FILE(categoryLogFileName);
    sprintf(categoryLogFileName, "%s%s%s", PAGE_FOLDER, DATA->name[choice], PAGE_FILE_EXTENSION);
    DELETE_FILE(categoryLogFileName);

    for (int i = choice; i < DATA->numCategories; ++i) {
        strcpy(DATA->name[i], DATA->name[i + 1]);
    }
    --(DATA->numCategories);

    char logCategoriesFileName[MAX_FOLDER_LENGTH];
    sprintf(logCategoriesFileName, "%s%s%s", LOG_FOLDER, CATEGORY_LOG, LOG_FILE_EXTENSION);
    FILE *logCategories = fopen(logCategoriesFileName, "w");
    fillCatLog(logCategories);
    fclose(logCategories);
    
    SEPARATOR;
    printf("Category successfully deleted!\n");
    buildNavBar(DATA);
}


/* formCatLogFile */
/* Forms a log file for a certain category if there is none */

void formLogFile(char *filename) {
    FILE *file;
    char logFileName[MAX_FOLDER_LENGTH];

    REMOVENEWL(filename);
    sprintf(logFileName, "%s%s%s", LOG_FOLDER, filename, LOG_FILE_EXTENSION);

    if ((file = fopen(logFileName, "r")) == NULL) {
        file = fopen(logFileName, "w");
        fprintf(file, "0\n");
        fclose(file);
    } else
        fclose(file);
}

void createCategoryDescription(char *categoryName) { // Creates formatted category description log
    char descriptionLogFileName[MAX_FOLDER_LENGTH];
    char *categoryDescription;

    askForTextInput("Please choose a description for your new category (50 characters limit):\n", &categoryDescription, MAX_CATEGORY_DESCRIPTION);
    REMOVENEWL(categoryDescription);

    // Create log file
    sprintf(descriptionLogFileName, "%s%s%s%s", LOG_FOLDER, categoryName, DESCRIPTION_TAG, LOG_FILE_EXTENSION);
    FILE *descriptionLogFile = fopen(descriptionLogFileName, "w");

    // Write formated description
    fprintf(descriptionLogFile, CATEGORY_DESCRIPTION, categoryDescription);
    fclose(descriptionLogFile);
    free(categoryDescription);
}
