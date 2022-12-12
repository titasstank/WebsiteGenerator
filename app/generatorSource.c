#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/DefinitionLib.h"
#include "./lib/CategoryLib.h"
#include "./lib/MessageLib.h"
#include "./lib/PageLib.h"
#include "./lib/ExtraLib.h"

extern Categories *DATA;

int main() {
    DATA = malloc(sizeof(Categories));
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

    CLEAR;
    SEPARATOR;
    printf("Running on Website-Generator version %s\n", VERSION);
    printf("The half assed/more than half way update\n");

    logCategories = fopen(logCategoriesFileName, "r");
    fetchCategories(logCategories);
    fclose(logCategories);

    /* Create an Index page if there isn't one already */

    FILE *homePage;
    char homePageFileName[MAX_FOLDER_LENGTH];
    sprintf(homePageFileName, "%s%s%s", PAGE_FOLDER, HOME_PAGE, PAGE_FILE_EXTENSION);
    if((homePage = fopen(homePageFileName, "r")) == NULL){
        SEPARATOR;
        printf("Please create a home page for your Website (index).\n");
        strcpy(DATA->name[DATA->numCategories], HOME_PAGE);
        char indexLogFileName[MAX_FOLDER_LENGTH] = HOME_PAGE;
        formLogFile(indexLogFileName);
        createCategoryDescription(HOME_PAGE);
        buildPage(DATA->numCategories++);
    }



    while (menuCat != 5) {
        LIST_CATEGORY_OPTIONS;
        while (1){
            if (scanf("%u", &menuCat) == 1 && getchar() == '\n')
                break;
            else {
                CLEAR;
                SEPARATOR;
                printf("Invalid option! Please select a valid option...\n");
                LIST_CATEGORY_OPTIONS;
                while(getchar() != '\n');
            }
        }
        switch (menuCat) {
            case 1:
                CLEAR;
                addCategory();
                break;
            case 2:
                if (DATA->numCategories != 0) {
                    CLEAR;
                    SEPARATOR;
                    printf("Which category would you like to delete? (0 to go back)\n");
                    printCatList();
                    while (1){
                        if (scanf("%u", &choice) == 1 && getchar() == '\n'){
                            if (choice <= DATA->numCategories){
                                CLEAR; 
                                if (choice == 0){
                                    break;
                                }
                                else if(choice == 1){
                                    printf("Cannot delete home page!\n");
                                }
                                else{
                                    deleteCategory(--choice);
                                    break;
                                }
                            } else {
                                CLEAR;
                                SEPARATOR;
                                printf("There is no such category! Please select a valid option...\n");
                                printCatList();
                            }
                        } else {
                            CLEAR;
                            while (getchar() != '\n');
                            SEPARATOR;
                            printf("Invalid option! Please select a valid option...\n");
                            printCatList();
                        }
                    }
                } else {
                    CLEAR;
                    printf("Nothing to delete!\n");
                }
                break;
            case 3:
                CLEAR;
                printCatList();
                break;
            case 4:
                CLEAR;
                printCatList();
                if(DATA->numCategories == 0){
                    break;
                }
                printf("Which is your working category?");
                scanf("%d", &workCat);
                getchar();
                fetchMessages(--workCat);
                CLEAR;

                while (menuMes != 4) {
                    LIST_MESSAGE_OPTIONS;
                    scanf("%d", &menuMes);
                    getchar();
                    CLEAR;
                    switch (menuMes) {
                        case 1:
                            createMessage(workCat);
                            break;
                        case 2:
                            SEPARATOR
                            printMesList(workCat);
                            SEPARATOR
                            printf("Which message would you like to delete? (0 to go back)\n");
                            scanf("%u", &choice); // TODO: input validation
                            getchar();
                            if(choice <= DATA->CatMessages[workCat].numMessages){
                                CLEAR;
                                if(choice == 0){
                                    break;
                                }
                                SEPARATOR;
                                deleteMessage(workCat, --choice);
                                SEPARATOR;
                                break;
                            }
                            else{
                                printf("Not a valid option!\n");
                            }
                        case 3:
                            printMesList(workCat);
                            break;
                        case 4:
                            if(!(buildPage(workCat))){
                                SEPARATOR;
                                printf("Page built successfully!\n");
                            }
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
                SEPARATOR;
                logCategories = fopen(logCategoriesFileName, "w");
                fillCatLog(logCategories);
                fclose(logCategories);
                break;
            case 6:
                CLEAR;
                printCredits();
                break;
            case 7:
                CLEAR;
                printDebug();
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
