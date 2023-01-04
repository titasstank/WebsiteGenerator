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

void fetchCategories(FILE *logCategories);

void printCatList();

void fillCatLog();

void addCategory();

void deleteCategory(int choice);

void formLogFile(char *filename);

void createCategoryDescription(char *categoryName);

#endif // CategoryLib
