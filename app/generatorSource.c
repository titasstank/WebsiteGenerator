#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/DefinitionLib.h"
#include "./lib/CategoryLib.h"
#include "./lib/MessageLib.h"
#include "./lib/PageLib.h"

int main() {
    /* Work with files */

    FILE *logCategories;
    char logCategoriesFileName[MAX_FOLDER_LENGTH];
    sprintf(logCategoriesFileName, "%s%s%s", LOG_FOLDER, CATEGORY_LOG, LOG_FILE_EXTENSION);
    if ((logCategories = fopen(logCategoriesFileName, "r")) == NULL) {
        logCategories = fopen(logCategoriesFileName, "w");
        fprintf(logCategories, "0\n");
        fclose(logCategories);
    } else
        fclose(logCategories);

    /* Work with categories */

    int menuCat = 0, workCat = 0, menuMes = 0, choice;
    Categories *DATA;
    DATA = malloc(sizeof(Categories));
    CLEAR;
    SEPARATOR;
    printf("Running on Website-Generator version %s\n", VERSION);
    printf("The half assed/half way update");
    SEPARATORIND;

    logCategories = fopen(logCategoriesFileName, "r");
    fetchCategories(logCategories, DATA);
    fclose(logCategories);

    while (menuCat != 5) {
        printf("What would you like to do?\n");
        LIST_CATEGORY_OPTIONS;
        scanf("%d", &menuCat);
        getchar();
        switch (menuCat) {
            case 1:
                CLEAR;
                addCategory(DATA);
                CLEAR;
                printf("Category created!\n");
                SEPARATOR;
                break;
            case 2:
                if (DATA->numCategories != 0) {
                    CLEAR;
                    printf("Which category would you like to delete?\n");
                    printCatList(DATA);
                    scanf("%d", &choice);
                    CLEAR;
                    deleteCategory(DATA, choice);
                    printf("Category deleted!\n");
                    SEPARATOR;
                } else {
                    CLEAR;
                    printf("Nothing to delete!\n");
                }
                break;
            case 3:
                CLEAR;
                printCatList(DATA);
                break;
            case 4:
                CLEAR;
                printCatList(DATA);
                if(DATA->numCategories == 0){
                    break;
                }
                printf("Which is your working category?");
                scanf("%d", &workCat);
                getchar();
                fetchMessages(DATA, workCat - 1);
                CLEAR;

                while (menuMes != 4) {
                    printf("What would you like to do?\n");
                    LIST_MESSAGE_OPTIONS;
                    scanf("%d", &menuMes);
                    getchar();
                    CLEAR;
                    switch (menuMes) {
                        case 1:
                            createMessage(DATA, workCat - 1);
                            break;
                        case 2:
                            break;
                        case 3:
                            printMesList(DATA, workCat - 1);
                            break;
                        case 4:
                            buildPage(DATA, workCat - 1);
                            break;
                        default:
                            printf("Not a valid option!\n");
                            break;
                    }
                }
                menuMes = 0;
                break;
            case 5:
                CLEAR;
                logCategories = fopen(logCategoriesFileName, "w");
                fillCatLog(logCategories, DATA);
                fclose(logCategories);
                break;
            default:
                printf("Not a valid option!\n");
                break;
        }
    }

    /* End of program */

    printf("Closed program\n");
    printf("\nThank you for using WebsiteGenerator!\n");
    SEPARATOR;
    free(DATA);
    return 0;
}
