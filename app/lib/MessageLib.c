#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "TemplateLib.h"
#include "ExtraLib.h"

extern Categories *DATA;

void fetchMessages(unsigned int numCat)
{
    FILE *messageLog;
    char logFileName[MAX_FOLDER_LENGTH];
    sprintf(logFileName, "%s%s%s", LOG_FOLDER, DATA->name[numCat], LOG_FILE_EXTENSION);
    if ((messageLog = fopen(logFileName, "r")) == NULL)
    {
        printf(MESSAGE_CANNOTOPEN_LOGS);
        return;
    }
    fscanf(messageLog, "%d", &(DATA->CatMessages[numCat].numMessages));
    fgetc(messageLog);
    for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i)
    {
        fgets(DATA->CatMessages[numCat].Messages[i], MAX_TITLE + 1, messageLog);
        REMOVENEWL(DATA->CatMessages[numCat].Messages[i]);
    }
    fclose(messageLog);
}

void fillMessageLog(unsigned numCat)
{
    char logFileName[MAX_FOLDER_LENGTH];
    sprintf(logFileName, "%s%s%s", LOG_FOLDER, DATA->name[numCat], LOG_FILE_EXTENSION);
    FILE *messageLog = fopen(logFileName, "w");
    fprintf(messageLog, "%d\n", DATA->CatMessages[numCat].numMessages);
    for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i)
    {
        fprintf(messageLog, "%s\n", DATA->CatMessages[numCat].Messages[i]);
    }
    fclose(messageLog);
    fetchMessages(numCat);
}

void printMessageList(unsigned int numCat)
{
    SEPARATOR;
    if (DATA->CatMessages[numCat].numMessages == 0)
    {
        printf(MESSAGE_CATNO_MES);
    }
    else
    {
        printf(MESSAGE_MES);
        for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i)
        {
            printf("%d. %s\n", i + 1, DATA->CatMessages[numCat].Messages[i]);
        }
    }
}

void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength)
{
    SEPARATOR;
    printf("%s", instruction);
    SEPARATOR;
    if ((*unallocatedStr = (char *)malloc(maxLength * sizeof(char))) == NULL)
    {
        CLEAR;
        SEPARATOR;
        printf(MESSAGE_MALLOC_FAIL);
        SEPARATOR;
        return;
    }
    fgets(*unallocatedStr, maxLength + 1, stdin);
}

void messageText(char **message, char *text)
{
    char *formattedText = malloc((strlen(text) + strlen(TEXT)) * sizeof(char));
    sprintf(formattedText, TEXT, text);
    *message = (char *)realloc(*message, (strlen(*message) + strlen(formattedText) + 1) * sizeof(char));
    strcat(*message, formattedText);
    free(formattedText);
}

void messageImage(char **message, char *link, char *altText)
{
    char *formattedText = malloc((strlen(link) + strlen(altText) + strlen(link) + strlen(altText) + strlen(IMAGE)) * sizeof(char));
    sprintf(formattedText, IMAGE, link, altText, link, altText);
    *message = (char *)realloc(*message, (strlen(*message) + strlen(formattedText) + 1) * sizeof(char));
    strcat(*message, formattedText);
    free(formattedText);
}

void messageLink(char **message, char *link, char *linkText)
{
    char *formattedText = malloc((strlen(link) + strlen(linkText) + strlen(LINK)) * sizeof(char));
    sprintf(formattedText, LINK, link, linkText);
    *message = (char *)realloc(*message, (strlen(*message) + strlen(formattedText) + 1) * sizeof(char));
    strcat(*message, formattedText);
    free(formattedText);
}

// char url[] = "https://www.youtube.com/watch?v=1bMqdVS_Ch8";
// char video_id[12];
void parseYoutubeUrl(const char *url, char *video_id)
{
    const char *start = strstr(url, "v=");
    if (start == NULL)
    {
        start = strstr(url, "be/");
        if (start == NULL)
            return;
        start += 3;
    }
    else
    {
        start += 2;
    }
    strncpy(video_id, start, 11);
    video_id[11] = '\0';
}

void messageVideo(char **message, char *videoID, char *title)
{
    char *formattedText = malloc((strlen(videoID) + strlen(title) + strlen(YT_VIDEO)) * sizeof(char));
    sprintf(formattedText, YT_VIDEO, videoID, title);
    *message = (char *)realloc(*message, (strlen(*message) + strlen(formattedText) + 1) * sizeof(char));
    strcat(*message, formattedText);
    free(formattedText);
}

void createMessage(unsigned int numCat)
{
    char *messageTitle;
    char *message = malloc(MAX_MESSAGE_LENGTH * sizeof(char));

    CLEAR;
    while (1)
    {
        askForTextInput(MESSAGE_ENTERTITLE_MES, &messageTitle, MAX_TITLE);
        REMOVENEWL(messageTitle);
        if (checkForDuplicates(messageTitle, DATA->CatMessages[numCat].Messages, DATA->CatMessages[numCat].numMessages) == 0)
        {
            if (strcmp(messageTitle, "0") == 0)
            {
                CLEAR;
                free(messageTitle);
                return;
            }
            break;
        }
        CLEAR;
        SEPARATOR;
        printf(MESSAGE_EXISTS);
    }

    int askForTypes = 1;
    while (askForTypes)
    {
        CLEAR;
        LIST_MESSAGE_TYPES;
        int messageType = getValidatedInt();
        char *link = NULL, *text = NULL;
        char *videoID = malloc(12 * sizeof(char));
        switch (messageType)
        {
        case 1: // message
            askForTextInput(MESSAGE_ENTER_MES, &text, MAX_MESSAGE_LENGTH);
            REMOVENEWL(text);
            messageText(&message, text);
            break;
        case 2: // image
            askForTextInput(MESSAGE_IMAGE_LINK, &link, MAX_LINK_LENGTH);
            REMOVENEWL(link);
            askForTextInput(MESSAGE_IMAGE_ALT, &text, MAX_MESSAGE_LENGTH);
            REMOVENEWL(text);
            messageImage(&message, link, text);
            break;
        case 3: // link
            askForTextInput(MESSAGE_LINK_LINK, &link, MAX_LINK_LENGTH);
            REMOVENEWL(link);
            askForTextInput(MESSAGE_LINK_TEXT, &text, MAX_MESSAGE_LENGTH);
            REMOVENEWL(text);
            messageLink(&message, link, text);
            break;
        case 4: // video
            askForTextInput(MESSAGE_YT_LINK, &link, MAX_LINK_LENGTH);
            REMOVENEWL(link);
            parseYoutubeUrl(link, videoID);
            askForTextInput(MESSAGE_YT_TITLE, &text, MAX_MESSAGE_LENGTH);
            REMOVENEWL(text);
            messageVideo(&message, videoID, text);
            break;
        case 0:
            CLEAR;
            askForTypes = 0;
            break;
        default:
            SEPARATOR;
            printf(SOURCE_INVALID_OPTION);
            break;
        }
        free(link);
        free(text);
        free(videoID);
    }

    SEPARATOR;
    formatMessage(DATA->name[numCat], messageTitle, message);
    strcpy(DATA->CatMessages[numCat].Messages[DATA->CatMessages[numCat].numMessages++], messageTitle);
    fillMessageLog(numCat);

    free(messageTitle);
    free(message);
    CLEAR;
}

extern unsigned failedToDelete;
void deleteMessage(unsigned numCat, unsigned messageToDeleteNumber)
{
    // Deleting the log file
    char messageLogFileName[MAX_FOLDER_LENGTH];
    sprintf(messageLogFileName, "%s%s_%s%s", LOG_FOLDER, DATA->name[numCat], DATA->CatMessages[numCat].Messages[messageToDeleteNumber], LOG_FILE_EXTENSION);
    DELETE_FILE(messageLogFileName);

    // Overriding it in structure
    for (int i = messageToDeleteNumber; i < DATA->CatMessages[numCat].numMessages; ++i)
    {
        strcpy(DATA->CatMessages[numCat].Messages[i], DATA->CatMessages[numCat].Messages[i + 1]);
    }
    --(DATA->CatMessages[numCat].numMessages);
    fillMessageLog(numCat);
    printf(MESSAGE_MESDEL_SUC);
}