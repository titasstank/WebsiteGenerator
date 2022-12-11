#ifndef DefinitionLib
#define DefinitionLib

/* Size definitions */

#define VERSION "0.7"
#define COPY_BUFFER_SIZE 255
#define MAX_MESSAGE_LENGTH 5000
#define MAX_MESSAGE_TITLE 100
#define MAX_MESSAGE_FILES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_DESCRIPTION 50
#define MAX_LOG_DATA 1000
#define MAX_CATEGORY_NAME 20
#define MAX_FOLDER_LENGTH 258

/* File locations & extensions */
#define LOG_FOLDER "../logs/"
#define TEMPLATE_FOLDER "../templates/"
#define PAGE_FOLDER "../../src/pages/"
#define LOG_FILE_EXTENSION ".txt"
#define CATEGORY_LOG "logCategories"
#define PAGE_FILE_EXTENSION ".html"
#define DESCRIPTION_TAG "_description"
#define CREDITS_PATH "../templates/credits.txt"

/* HTML Definitions */

#define HOME_PAGE       "index"
#define PAGE_START      "start"
#define PAGE_END        "finish"
#define NAV_START       "nav_start"
#define NAV_END         "nav_end"


// NAVBAR tags
#define NAVBAR_LINE             "<li><a href=\"%s.html\" class=\"nav-link px-2 text-white\">%s</a></li>\n"

// Category description tags
#define CATEGORY_DESCRIPTION    "<h3 class=\"pb-4 mb-4 text-primary border-bottom\">\n%s\n</h3>\n"

// Message tags
#define BASIC_MESSAGE           "<article class=\"blog-post\">\n"\
                                "<h2 class=\"blog-post-title mb-1\">%s</h2>\n"\
                                "<p class=\"blog-post-meta\">%s %d, %d</p>\n"\
                                "<p>%s</p>\n"\
                                "</article>\n"

/* Utility Definitions */

#define CLEAR                   printf("\e[1;1H\e[2J");
#define PAUSE                   system("pause");
#define REMOVENEWL(str)         str[strcspn(str, "\n")] = 0;
#define DELETE_FILE(fileName)   remove(fileName);
#define SEPARATOR               printf("%s","=====================================================\n");

#define LIST_CATEGORY_OPTIONS SEPARATOR; printf("What would you like to do?\n\n1. Create a category\n2. Delete a category\n3. Print list of categories\n4. Select working category\n5. Exit\n\n6. Credits\n7. Debug\n"); SEPARATOR;
#define LIST_MESSAGE_OPTIONS  SEPARATOR; printf("What would you like to do?\n\n1. Create a message\n2. Delete a message\n3. Print a list of messages\n4. Build page and go back\n"); SEPARATOR;

#endif // DefinitionLib
