#ifndef MessageLib
#define MessageLib

void fetchMessages(Categories *DATA, unsigned int numCat);

void fillMessageLog(Categories *DATA, unsigned int numCat, char *messageTitle);

void printMesList(Categories *DATA, unsigned int numCat);

void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength);

void createMessage(Categories *DATA, unsigned int numCat);

#endif // MessageLib
