#ifndef CategoryLib
#define CategoryLib

/* Struct Definition */

typedef struct Messages {
    int numMessages;
    char Messages[MAX_MESSAGE_FILES][MAX_MESSAGE_TITLE];
} Messages;

typedef struct Categories {
    int numCategories;
    char name[MAX_CATEGORIES][MAX_CATEGORY_NAME];
    Messages CatMessages[MAX_CATEGORIES];
} Categories;

/* Function Definitions */

void fetchCategories(FILE *logCategories, Categories *DATA);

void printCatList(Categories *DATA);

void fillCatLog(FILE *logCategories, Categories *DATA);

void addCategory(Categories *DATA);

void deleteCategory(Categories *DATA, int choice);

void formLogFile(char *filename);

void createCategoryDescription(char *categoryName);

#endif // CategoryLib
