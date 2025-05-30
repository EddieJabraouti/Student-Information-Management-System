#include "givenA2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearContacts (char *fileName) {
    FILE *fptr = fopen(fileName, "wb");
    if (!fptr) {
        perror("Failed to clear file");
        return;
    }
    
    fclose(fptr);
    printf("cleared file");
}
