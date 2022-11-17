#ifndef DEFINITIONLIB_H_INCLUDED
#define DEFINITIONLIB_H_INCLUDED

/* Size definitions */

#define MAX_MESSAGE_FILES 100
#define MAX_CATEGORIES 10
#define MAX_LOG_DATA 1000
#define MAX_CATEGORY_NAME 20
#define MAX_FOLDER_LENGTH 258
#define LOG_FOLDER "logs//"
#define LOG_FILE_EXTENSION ".txt"

/* HTML Definitions */

#define BLOGTITLE "<h2 class=\"blog-post-title mb-1\">"
#define H2        "</h2>"

#define BLOGINFO "<p class=\"blog-post-meta\">"
#define P        "</p>"

#define BLOGMESSAGE "<article class=\"blog-post\">\n<p>"
#define PARTICLE    "</p></article>"

/* Utility Definitions */

#define CLEAR        system("cls");
#define REMOVENEWL   filename[strcspn(filename, "\n")] = 0;
#define SEPARATOR    printf("%s","=====================================================\n")
#define SEPARATORIND printf("%s","\n=====================================================\n\n")

#define LIST_CATEGORY_OPTIONS printf("1. Create a category\n2. Delete a category\n3. Print list of categories\n4. Select working category\n5. Exit\n\n");
#define LIST_MESSAGE_OPTIONS  printf("1. Create a message\n2. Delete a message\n3. Print a list of messages\n4. Go back\n");

#endif // DEFINITIONLIB_H_INCLUDED
