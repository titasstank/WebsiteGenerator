#ifndef DefinitionLib
#define DefinitionLib

// Size definitions

#define VERSION "0.7.6"
#define COPY_BUFFER_SIZE 255
#define MAX_MESSAGE_LENGTH 5000
#define MAX_TITLE 50
#define MAX_MESSAGE_FILES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_DESCRIPTION 50
#define MAX_LOG_DATA 1000
#define MAX_FOLDER_LENGTH 258
#define MAX_LINK_LENGTH 2048

// File locations & extensions

#define LOG_FOLDER "../logs/"
#define TEMPLATE_FOLDER "../templates/"
#define PAGE_FOLDER "../../src/pages/"
#define LOG_FILE_EXTENSION ".txt"
#define CATEGORY_LOG "logCategories"
#define PAGE_FILE_EXTENSION ".html"
#define DESCRIPTION_TAG "_description"
#define CREDITS_PATH "../templates/credits.txt"

// HTML Definitions

#define HOME_PAGE "index"
#define PAGE_START "start"
#define PAGE_END "finish"
#define NAV_START "nav_start"
#define NAV_END "nav_end"

// NAVBAR tags

#define NAVBAR_MEMBER "<li><a href=\"%s.html\" class=\"nav-link px-2 text-white\">%s</a></li>\n"

// Category description tags

#define CATEGORY_DESCRIPTION "<h3 class=\"pb-4 mb-4 text-primary border-bottom\">\n%s\n</h3>\n"

// Message tags

#define POST_BEGIN "<article class=\"blog-post\">\n"              \
                   "<h2 class=\"blog-post-title mb-1\">%s</h2>\n" \
                   "<p class=\"blog-post-meta\">%s %d, %d</p>\n"

#define POST_END "</article>\n"

#define TEXT "<p>%s</p>\n"

#define IMAGE "<img src=\"%s\" class=\"col-lg-7 col-md-10 col-sm-11 d-block img-fluid mx-auto\" alt=\"%s\">\n" \
              "<small class =\"d-block mb-3 mx-auto text-center text-muted\"><a src =\"%s\">%s</a></small>\n"

#define LINK "<a href=\"%s\" class=\"link-primary\">%s</a>\n"

#define YT_VIDEO "<div class=\"ratio ratio-16x9 my-3\" id=\"player\">\n"                                                       \
                 "<iframe src=\"https://www.youtube.com/embed/%s\" title=\"%s\" frameborder=\"0\" allowfullscreen></iframe>\n" \
                 "</div>\n"

// Utility Definitions

#define CLEAR printf("\e[1;1H\e[2J");
#define PAUSE system("pause");
#define REMOVENEWL(str) str[strcspn(str, "\n")] = 0;
#define DELETE_FILE(fileName)  \
    if (remove(fileName) != 0) \
        failedToDelete = 1;    \
    else                       \
        failedToDelete = 0;
#define SEPARATOR printf("%s", "────────────────────────────────────────────────────────────────────────────────\n");

#define LIST_CATEGORY_OPTIONS                                                                                                                                                                         \
    SEPARATOR;                                                                                                                                                                                        \
    printf("What would you like to do?\n1. Create a category\n2. Delete a category\n3. Print list of categories\n4. Select working category\n5. Exit\n6. Credits\n7. Debug (Loads all messages!)\n"); \
    SEPARATOR;
#define LIST_MESSAGE_OPTIONS                                                                                                                  \
    SEPARATOR;                                                                                                                                \
    printf("What would you like to do?\n1. Create a message\n2. Delete a message\n3. Print a list of messages\n4. Build page and go back\n"); \
    SEPARATOR;
#define LIST_MESSAGE_TYPES                                                                                                              \
    SEPARATOR;                                                                                                                          \
    printf("What would you like to do?\n1. Insert text\n2. Insert image\n3. Insert link\n4. Insert YouTube video\n0. Exit the loop\n"); \
    SEPARATOR;

// Message Definitions

// From generatorSource.c
#define SOURCE_VERSION "Running on Website-Generator version %s\n"
#define SOURCE_VERSION_DESC "The half assed/more than half way update\n"
#define SOURCE_CREATE_INDEX "Please create a home page for your Website (index):\n"
#define SOURCE_INVALID_OPTION "Invalid option! Please select a valid option...\n"
#define SOURCE_DELETE_CAT "Which category would you like to delete? (0 to go back)\n"
#define SOURCE_INVALID_CAT "There is no such category! Please select a valid option... (0 to go back)\n"
#define SOURCE_CANNOTDEL_HOME "Cannot delete home page!\n"
#define SOURCE_NOTHING_DEL "Nothing to delete!\n"
#define SOURCE_WHICH_CAT "Which is your working category? (0 to go back)\n"
#define SOURCE_DELETE_MESS "Which message would you like to delete? (0 to go back)\n"
#define SOURCE_PBUILT_SUC "Page built successfully!\n"
#define SOURCE_CLOSE_MES "Closed program...\n\nThank you for using WebsiteGenerator!\n"

// From CategoryLib.c
#define CATEGORY_CAT "Categories:\n"
#define CATEGORY_EMPTY_CAT "The category list is empty!\n"
#define CATEGORY_NAME_CAT "Please enter a category name (0 to go back):\n"
#define CATEGORY_CREATED_CAT "Created category - %d. %s\n"
#define CATEGORY_DELETED_CAT "Category successfully deleted!\n"
#define CATEGORY_DESCRIPTION_CAT "Please choose a description for your new category (50 characters limit):\n"
#define CATEGORY_EXISTS "Category with that name already exists!\n"

// From MessageLib.c
#define MESSAGE_CANNOTOPEN_LOGS "Could not open message logs!\n"
#define MESSAGE_CATNO_MES "This category has no messages!\n"
#define MESSAGE_MES "Messages:\n"
#define MESSAGE_MALLOC_FAIL "Could not allocate memory!\n"
#define MESSAGE_ENTERTITLE_MES "Enter the title of your message (input 0 to go back):\n"
#define MESSAGE_ENTER_MES "Enter the message\n"
#define MESSAGE_MESDEL_SUC "Message deleted successfully!\n"
#define MESSAGE_EXISTS "Message with that title already exists!\n"
#define MESSAGE_IMAGE_LINK "Enter the link to your image.\n"
#define MESSAGE_IMAGE_ALT "Describe the picture.\n"
#define MESSAGE_LINK_LINK "Enter the link to your link.\n"
#define MESSAGE_LINK_TEXT "Enter the text for your link.\n"
#define MESSAGE_YT_LINK "Enter the link to your YouTube video.\n"
#define MESSAGE_YT_TITLE "Enter the title of your YouTube video.\n"

// From PageLib.c
#define PAGE_BUILDPAGE_FAIL "Could not open file to copy contents from. Page has not been built successfully!\nDon't forget to exit!\n"
#define PAGE_DESOPEN_FAIL "Failed to open destination file!\n"

// From ExtraLib.c
#define EXTRA_EXIT_CREDS "\nPress any key to go back.\n"
#define EXTRA_OPENCRED_FAIL "Credits file does not exist or path is wrong!\n"
#define EXTRA_GLOBAL_VAR "Global variables:\n"
#define EXTRA_NUMBER_CAT "Number of categories: %d\n"
#define EXTRA_INVALID_OPT "Invalid option! Please enter a new option..."

#endif // DefinitionLib
