#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "libs\DefinitionLib.h"
#include "libs\CategoryLib.h"
#include "libs\MessageLib.h"

int main()
{
    /* Work with files */

    FILE* logCategories,* site,* start,* end;
    if ((logCategories = fopen("logs\\logCategories.txt", "r")) == NULL){
        logCategories = fopen("logs\\logCategories.txt", "w");
        fprintf(logCategories, "0\n");
        fclose(logCategories);
    } else
        fclose(logCategories);
    site = fopen("index.html", "w");
    start = fopen("templates\\start.txt", "r");
    end = fopen("templates\\end.txt", "r");

    /* Work with categories */

    int menuCat = 0, workCat = 0, menuMes = 0, choice;
    char catLogFile[MAX_CATEGORY_NAME];
    const float version = 0.22f;
    Categories *DATA;
    DATA = malloc(sizeof(Categories));

    printf("Running on Website-Generator version %g\n", version);
    printf("Now with no bullshit and fully rewritten code!\n");
    SEPARATOR;

    logCategories = fopen("logs\\logCategories.txt", "r");
    fetchCategories(logCategories, DATA);
    fclose(logCategories);

    while(menuCat != 5){
        printf("What would you like to do?\n");
        LIST_CATEGORY_OPTIONS;
        scanf("%d", &menuCat);
        getchar();
        switch (menuCat){
        case 1:
            CLEAR;
            addCategory(DATA);
            CLEAR;
            printf("Category created!\n");
            SEPARATOR;
            break;
        case 2:
            if (DATA->numCategories != 0){
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
            printf("Which is your working category?");
            scanf("%d", &workCat);
            getchar();
            formLogFile(DATA->name[workCat - 1]);

            printf("What would you like to do?\n");
            LIST_MESSAGE_OPTIONS;
            scanf("%d", &menuMes);
            getchar();
            CLEAR;

            while(menuMes != 4){
                switch(menuMes){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    printf("Not a valid option!\n");
                    break;
                }
            }
            break;
        case 5:
            CLEAR;
            logCategories = fopen("logs\\logCategories.txt", "w");
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
