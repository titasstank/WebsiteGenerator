#ifndef PageLib
#define PageLib

void copyFromFileToFile(FILE *destinationFile, char *sourceFileName);

void buildPage(Categories *DATA, unsigned int workingCategory);

void editNavBar(Categories *DATA);

#endif