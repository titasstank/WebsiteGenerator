#ifndef PageLib
#define PageLib

void copyFromFileToFile(FILE *destinationFile, char *sourceFileName);

int buildPage(Categories *DATA, unsigned int workingCategory);

void buildNavBar(Categories *DATA);

#endif