/*
Student Name: Eyad Jabraouti
Student ID: 1333651
Due Date: March 1st, 2025
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include "givenA2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchContacts (char * fileName, int keyId) {
    
    if (keyId < 1 || keyId > 9999) {
        printf("No match found!\n");
        return 0;
    }

    
    FILE *fptr = fopen(fileName, "rb");
    if (fptr == NULL) {
        perror("Failed to open file\n");
        return -1;
    }
    
    struct contact currentContact;
    
    while (fread(&currentContact, sizeof(struct contact), 1, fptr)) {
        fseek(fptr, currentContact.empIdPosn, SEEK_SET);
        int emplpoyeeId;
        fread(&emplpoyeeId, sizeof(int), 1, fptr);
        
        if (emplpoyeeId == keyId) {
            printf("****************************\n");
            printf("Employee Id: %d\n", emplpoyeeId);
            
            printf("First Name: ");
            fseek(fptr, currentContact.firstNamePosn, SEEK_SET);
            char firstName [100] = {0};
            fread(firstName, 1, currentContact.lastNamePosn - currentContact.firstNamePosn, fptr);
            printf("%s\n", firstName);
            
            printf("Last Name: ");
            fseek(fptr, currentContact.lastNamePosn, SEEK_SET);
            char lastName [100] = {0};
            fread(lastName, 1, currentContact.emailPosn - currentContact.lastNamePosn, fptr);
            printf("%s\n", lastName);
            
            printf("Email: ");
            fseek(fptr, currentContact.emailPosn, SEEK_SET);
            char email [100] = {0};
            fread(email, 1, currentContact.next - currentContact.emailPosn, fptr);
            printf("%s\n", email);
            
            fclose(fptr);
            return 1;
        }
        
        fseek(fptr, currentContact.next, SEEK_SET);
    }
    
    fclose(fptr); 
    return 0;
}

