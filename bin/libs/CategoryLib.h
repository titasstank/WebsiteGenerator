#ifndef FILELIB_H_INCLUDED
#define FILELIB_H_INCLUDED

/* Struct Definition */

typedef struct Messages{
    int numMessages;
    char *Messages[MAX_MESSAGE_FILES];
} Messages;

typedef struct Categories{
    int numCategories;
    char name[MAX_CATEGORIES][MAX_CATEGORY_NAME];
    Messages CatMessages[MAX_CATEGORIES];
} Categories;

/* Function Definitions */

void fetchCategories(FILE *logCategories, Categories *DATA);
void printCatList(Categories *DATA);
void addCategory(Categories *DATA);
void deleteCategory(Categories *DATA, int choice);
void fillCatLog(FILE *logCategories, Categories *DATA);
void formLogFile(char filename[MAX_CATEGORY_NAME]);

/* fetchCategories */
/* Copies the number of categories and the categories to the structure from the specified file */

void fetchCategories(FILE *logCategories, Categories *DATA){
    int numCat;
    char category[MAX_CATEGORY_NAME];

    fscanf(logCategories, "%d", &numCat);
    if (fgets(category, MAX_CATEGORY_NAME, logCategories) != NULL){
        DATA->numCategories = numCat;
        for (int i = 0 ; i < numCat ; ++i){
            fgets(category, MAX_CATEGORY_NAME, logCategories);
            strcpy(DATA->name[i], category);
        }
    }
}

/* printCatList */
/* Prints the list of the categories from the structure */

void printCatList(Categories *DATA){
    SEPARATOR;
    if (DATA->numCategories != 0){
        for (int i = 0 ; i < DATA->numCategories ; ++i){
            printf("%d. %s", i + 1, DATA->name[i]);
        }
    } else
        printf("The category list is empty!");
    SEPARATORIND;
}

/* addCategory */
/* Adds a category to the structure */

void addCategory(Categories *DATA){
    int numCat;
    char category[MAX_CATEGORY_NAME];
    numCat = DATA->numCategories;

    SEPARATOR;
    printf("Please enter a category name:");
    if (fgets(category, MAX_CATEGORY_NAME, stdin) != NULL){
        strcpy(DATA->name[numCat], category);
    }
    DATA->numCategories = (DATA->numCategories) + 1;
}

/* deleteCategory */
/* Deletes a category from the structure */

void deleteCategory(Categories *DATA, int choice){
    for (int i = choice - 1 ; i < DATA->numCategories ; ++i){
        strcpy(DATA->name[i], DATA->name[i + 1]);
    }
    DATA->numCategories = (DATA->numCategories) - 1;
}

/* fillCatLog */
/* Puts the number of categories and categories form the structure to the specified file */

void fillCatLog(FILE *logCategories, Categories *DATA){
    fprintf(logCategories, "%d\n", DATA->numCategories);
    for(int i = 0 ; i < DATA->numCategories ; ++i){
        fputs(DATA->name[i], logCategories);
    }
}

/* formCatLogFile */
/* Forms a log file for a certain category if there is none */

void formLogFile(char filename[MAX_CATEGORY_NAME]){
    FILE *file;
    char complName[MAX_FOLDER_LENGTH];

    REMOVENEWL;
    sprintf(complName, "%s%s%s", LOG_FOLDER, filename, LOG_FILE_EXTENSION);
    printf("\n%s\n", complName);

    if((file = fopen(complName, "r")) == NULL){
        file = fopen(complName, "w");
        fprintf(file, "0\n");
        fclose(file);
    } else
        fclose(file);
}

#endif // FILELIB_H_INCLUDED
