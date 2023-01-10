#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/DefinitionLib.h"
#include "./lib/CategoryLib.h"
#include "./lib/MessageLib.h"
#include "./lib/PageLib.h"
#include "./lib/ExtraLib.h"

extern Categories *DATA;

int main()
{
    DATA = malloc(sizeof(Categories));
    /* Work with files */

    FILE *logCategories;
    char logCategoriesFileName[MAX_FOLDER_LENGTH];
    sprintf(logCategoriesFileName, "%s%s%s", LOG_FOLDER, CATEGORY_LOG, LOG_FILE_EXTENSION);
    if ((logCategories = fopen(logCategoriesFileName, "r")) == NULL)
    {
        logCategories = fopen(logCategoriesFileName, "w");
        fprintf(logCategories, "0\n");
        fclose(logCategories);
    }
    else
        fclose(logCategories);

    /* Work with categories */

    int menuCat = 0, workCat = 0, menuMes = 0, choice;

    CLEAR;
    SEPARATOR;
    printf(SOURCE_VERSION, VERSION);
    printf(SOURCE_VERSION_DESC);

    logCategories = fopen(logCategoriesFileName, "r");
    fetchCategories(logCategories);
    fclose(logCategories);

    /* Create an Index page if there isn't one already */

    FILE *homePage;
    char homePageFileName[MAX_FOLDER_LENGTH];
    sprintf(homePageFileName, "%s%s%s", PAGE_FOLDER, HOME_PAGE, PAGE_FILE_EXTENSION);
    if ((homePage = fopen(homePageFileName, "r")) == NULL)
    {
        SEPARATOR;
        printf(SOURCE_CREATE_INDEX);
        strcpy(DATA->name[DATA->numCategories], HOME_PAGE);
        char indexLogFileName[MAX_FOLDER_LENGTH] = HOME_PAGE;
        formLogFile(indexLogFileName);
        createCategoryDescription(HOME_PAGE);
        buildPage(DATA->numCategories++);
        fillCatLog();
        CLEAR;
    }

    while (menuCat != 5)
    {
        LIST_CATEGORY_OPTIONS;
        while (1)
        {
            menuCat = getValidatedInt();
            CLEAR;
            if (menuCat != -1)
                break;
            else
            {
                SEPARATOR;
                printf(SOURCE_INVALID_OPTION);
                LIST_CATEGORY_OPTIONS;
            }
        }
        CLEAR;
        switch (menuCat)
        {
        case 1:
            addCategory();
            break;
        case 2:
            SEPARATOR;
            if (DATA->numCategories != 0)
            {
                printf(SOURCE_DELETE_CAT);
                printCatList();
                SEPARATOR;
                while (1)
                {
                    choice = getValidatedInt();
                    if (choice != -1 && choice <= DATA->numCategories)
                    {
                        CLEAR;
                        if (choice == 0)
                        {
                            break;
                        }
                        else if (choice == 1)
                        {
                            SEPARATOR;
                            printf(SOURCE_CANNOTDEL_HOME);
                            SEPARATOR;
                            printf(SOURCE_DELETE_CAT);
                            printCatList();
                            SEPARATOR;
                        }
                        else
                        {
                            deleteCategory(--choice);
                            break;
                        }
                    }
                    else
                    {
                        CLEAR;
                        SEPARATOR;
                        printf(SOURCE_INVALID_CAT);
                        printCatList();
                        SEPARATOR;
                    }
                }
            }
            else
                printf(SOURCE_NOTHING_DEL);
            break;
        case 3:
            printCatList();
            break;
        case 4:
            printCatList();
            if (DATA->numCategories == 0)
            {
                break;
            }
            SEPARATOR;
            printf(SOURCE_WHICH_CAT);
            while (1)
            {
                workCat = getValidatedInt();
                CLEAR;
                if (workCat != -1 && workCat <= DATA->numCategories)
                {
                    break;
                }
                else
                {
                    SEPARATOR;
                    printf(SOURCE_INVALID_OPTION);
                    printCatList();
                    SEPARATOR;
                    printf(SOURCE_WHICH_CAT);
                }
            }
            CLEAR;
            if (workCat == 0)
            {
                CLEAR;
                break;
            }
            fetchMessages(--workCat);

            while (menuMes != 4)
            {
                LIST_MESSAGE_OPTIONS;
                while (1)
                {
                    menuMes = getValidatedInt();
                    CLEAR;
                    if (menuMes != -1)
                    {
                        break;
                    }
                    else
                    {
                        SEPARATOR;
                        printf(SOURCE_INVALID_OPTION);
                        LIST_MESSAGE_OPTIONS;
                    }
                }
                CLEAR;
                switch (menuMes)
                {
                case 1:
                    createMessage(workCat);
                    break;
                case 2:
                    printMessageList(workCat);
                    SEPARATOR
                    printf(SOURCE_DELETE_MESS);
                    SEPARATOR;
                    while (1)
                    {
                        choice = getValidatedInt();
                        if (choice != -1 && choice <= DATA->CatMessages[workCat].numMessages)
                            break;
                        else
                        {
                            CLEAR;
                            SEPARATOR;
                            printf(SOURCE_INVALID_OPTION);
                            printMessageList(workCat);
                            SEPARATOR;
                        }
                    }
                    CLEAR;
                    if (choice == 0)
                    {
                        break;
                    }
                    SEPARATOR;
                    deleteMessage(workCat, --choice);
                    break;
                case 3:
                    printMessageList(workCat);
                    break;
                case 4:
                    if (!(buildPage(workCat)))
                    {
                        SEPARATOR;
                        printf(SOURCE_PBUILT_SUC);
                    }
                    break;
                default:
                    SEPARATOR;
                    printf(SOURCE_INVALID_OPTION);
                    break;
                }
            }
            menuMes = 0;
            break;
        case 5:
            SEPARATOR;
            fillCatLog();
            break;
        case 6:
            printCredits();
            break;
        case 7:
            printDebug();
            break;
        default:
            SEPARATOR
            printf(SOURCE_INVALID_OPTION);
            break;
        }
    }

    /* End of program */

    printf(SOURCE_CLOSE_MES);
    SEPARATOR;
    free(DATA);
    return 0;
}
