#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DefinitionLib.h"
#include "CategoryLib.h"
#include "TemplateLib.h"

extern Categories *DATA;

void fetchMessages(unsigned int numCat) {
    FILE *messageLog;
    char logFileName[MAX_FOLDER_LENGTH];
    sprintf(logFileName, "%s%s%s", LOG_FOLDER, DATA->name[numCat], LOG_FILE_EXTENSION);
    if ((messageLog = fopen(logFileName, "r")) == NULL) {
        printf(MESSAGE_CANNOTOPEN_LOGS);
        return;
    }
    fscanf(messageLog, "%d", &(DATA->CatMessages[numCat].numMessages));
    fgetc(messageLog);
    for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i) {
        fgets(DATA->CatMessages[numCat].Messages[i], MAX_MESSAGE_TITLE + 1, messageLog);
        REMOVENEWL(DATA->CatMessages[numCat].Messages[i]);
    }
    fclose(messageLog);
}

void fillMessageLog(unsigned numCat) {
    char logFileName[MAX_FOLDER_LENGTH];
    sprintf(logFileName, "%s%s%s", LOG_FOLDER, DATA->name[numCat], LOG_FILE_EXTENSION);
    FILE *messageLog = fopen(logFileName, "w");
    fprintf(messageLog, "%d\n", DATA->CatMessages[numCat].numMessages);
    for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i) {
        fprintf(messageLog, "%s\n", DATA->CatMessages[numCat].Messages[i]);
    }
    fclose(messageLog);
    fetchMessages(numCat);
}

void printMesList(unsigned int numCat) {
    SEPARATOR;
    if (DATA->CatMessages[numCat].numMessages == 0) {
        printf(MESSAGE_CATNO_MES);
    } else {
        printf(MESSAGE_MES);
        for (int i = 0; i < DATA->CatMessages[numCat].numMessages; ++i) {
            printf("%d. %s\n", i + 1, DATA->CatMessages[numCat].Messages[i]);
        }
    }
}


void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength) {
    SEPARATOR;
    printf("%s", instruction);
    SEPARATOR;
    if ((*unallocatedStr = (char *) malloc(maxLength * sizeof(char))) == NULL) {
        CLEAR;
        SEPARATOR;
        printf(MESSAGE_MALOC_FAIL);
        SEPARATOR;
        return;
    }
    fgets(*unallocatedStr, maxLength + 1, stdin);
}

void createMessage(unsigned int numCat) {
    char *messageTitle;
    char *message;

    CLEAR;
    askForTextInput(MESSAGE_ENTERTITLE_MES, &messageTitle, MAX_MESSAGE_TITLE);
    REMOVENEWL(messageTitle);

    CLEAR;
    askForTextInput(MESSAGE_ENTER_MES, &message, MAX_MESSAGE_LENGTH);
    REMOVENEWL(message);

    formatBasicMessage(DATA->name[numCat], messageTitle, message);
    strcpy(DATA->CatMessages[numCat].Messages[DATA->CatMessages[numCat].numMessages++], messageTitle);
    fillMessageLog(numCat);

    free(messageTitle);
    free(message);
    CLEAR;
}

extern unsigned failedToDelete;
void deleteMessage(unsigned numCat, unsigned messageToDeleteNumber){
    // Deleting the log file
    char messageLogFileName[MAX_FOLDER_LENGTH];
    sprintf(messageLogFileName, "%s%s_%s%s", LOG_FOLDER, DATA->name[numCat], DATA->CatMessages[numCat].Messages[messageToDeleteNumber], LOG_FILE_EXTENSION);
    DELETE_FILE(messageLogFileName);

    // Overriding it in structure
    for(int i = messageToDeleteNumber; i < DATA->CatMessages[numCat].numMessages; ++i){
        strcpy(DATA->CatMessages[numCat].Messages[i], DATA->CatMessages[numCat].Messages[i + 1]);
    }
    --(DATA->CatMessages[numCat].numMessages);
    fillMessageLog(numCat);
    printf(MESSAGE_MESDEL_SUC);
}
