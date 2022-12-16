#ifndef PageLib
#define PageLib

void copyFromFileToFile(FILE *destinationFile, char *sourceFileName);

int buildPage(unsigned int workingCategory);

void buildNavBar();

#endif
