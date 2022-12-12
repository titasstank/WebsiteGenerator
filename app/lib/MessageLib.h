#ifndef MessageLib
#define MessageLib

void fetchMessages(unsigned int numCat);

void fillMessageLog(unsigned int numCat);

void printMesList(unsigned int numCat);

void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength);

void createMessage(unsigned int numCat);

void deleteMessage(unsigned numCat, unsigned messageToDeleteNumber);

#endif // MessageLib
