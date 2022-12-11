#ifndef MessageLib
#define MessageLib

void fetchMessages(Categories *DATA, unsigned int numCat);

void fillMessageLog(Categories *DATA, unsigned int numCat);

void printMesList(Categories *DATA, unsigned int numCat);

void askForTextInput(char *instruction, char **unallocatedStr, size_t maxLength);

void createMessage(Categories *DATA, unsigned int numCat);

void deleteMessage(Categories *DATA, unsigned numCat, unsigned messageToDeleteNumber);

#endif // MessageLib
