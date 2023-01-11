#include <stdio.h>

#ifndef MessageLib
#define MessageLib

void fetchMessages(unsigned int numCat);

void fillMessageLog(unsigned int numCat);

void printMessageList(unsigned int numCat);

void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength);

void messageText(char **message, char *text);

void messageImage(char **message, char *link, char *altText);

void messageLink(char **message, char *link, char *linkText);

void parseYoutubeUrl(const char *url, char *video_id);

void messageVideo(char **message, char *videoID, char *title);

void createMessage(unsigned int numCat);

void deleteMessage(unsigned numCat, unsigned messageToDeleteNumber);

#endif // MessageLib
