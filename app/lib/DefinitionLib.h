#ifndef DefinitionLib
#define DefinitionLib

/* Size definitions */

#define VERSION "0.5"
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

/* HTML Definitions */

#define PAGE_START_TEMPLATE_NAME "start.txt"
#define PAGE_END_TEMPLATE_NAME "finish.txt"

// NAVBAR tags
#define NAVBAR_PAGE_FILE    "<li><a href=\"freshmore.html\" "
#define NAVBAR_PAGE_TITLE   "class=\"nav-link px-2 text-white\">"
#define NAVBAR_END          "</a></li>"

// Category description tags

#define CATEGORY_DESCRIPTION        "<h3 class=\"pb-4 mb-4 text-primary border-bottom\">"
#define H3                          "</h3>"

// Message tags
#define ARTICLE_BEGINNING "<article class=\"blog-post\">"
#define BLOG_TITLE       "<h2 class=\"blog-post-title mb-1\">"
#define H2              "</h2>"

#define BLOG_DATE        "<p class=\"blog-post-meta\">"
#define P_CLOSE          "</p>"

#define BLOG_MESSAGE     "<p>"
#define ARTICLE_ENDING   "</article>"

/* Utility Definitions */

#define CLEAR        printf("\033[2J")
#define REMOVENEWL(str)   str[strcspn(str, "\n")] = 0;
#define SEPARATOR    printf("%s","=====================================================\n");
#define SEPARATORIND printf("%s","\n=====================================================\n\n");

#define LIST_CATEGORY_OPTIONS printf("1. Create a category\n2. Delete a category\n3. Print list of categories\n4. Select working category\n5. Exit\n");
#define LIST_MESSAGE_OPTIONS  printf("1. Create a message\n2. Delete a message\n3. Print a list of messages\n4. Build page and go back\n");

#endif // DefinitionLib
