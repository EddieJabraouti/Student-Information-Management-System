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

void createContacts (char * fileName) {
    
    FILE *fptr = fopen(fileName, "ab");
    
    if (!fptr) {
        perror("Failed to open file");
        return;
    }
    
        struct contact newContact;
        char firstName[100], lastName[100], email[100];
        int employeeId;
            
        printf("Employee Id: ");
        scanf("%d", &employeeId);
    if (employeeId < 1 || employeeId > 9999) {
        printf("Invalid student id!\n");
        fclose(fptr);
        return;
    }
        printf("First Name: ");
        scanf("%s", firstName);
        printf("Last Name: ");
        scanf("%s", lastName);
        printf("Email: ");
        scanf("%s", email);
            
        fseek(fptr, 0, SEEK_END);
        long startPosition = ftell(fptr);
            
        newContact.empIdPosn = startPosition + sizeof(struct contact);
        newContact.firstNamePosn = newContact.empIdPosn + sizeof(int);
        newContact.lastNamePosn = newContact.firstNamePosn + strlen(firstName) + 1;
        newContact.emailPosn = newContact.lastNamePosn + strlen(lastName) + 1;
        newContact.next = newContact.emailPosn + strlen(email) + 1;
            
        fwrite(&newContact, sizeof(struct contact), 1, fptr);
            
        fwrite(&employeeId, sizeof(int), 1, fptr);
        fwrite(firstName, strlen(firstName) + 1, 1, fptr);
        fwrite(lastName, strlen(lastName) + 1, 1, fptr);
        fwrite(email, strlen(email) + 1, 1, fptr);
        
        fclose(fptr);
        
    }








