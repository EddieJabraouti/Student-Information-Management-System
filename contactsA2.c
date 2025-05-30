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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "givenA2.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];
    int choice;
    char response [10];
    
    printf("Do you wish to enter a new contact (Yes or No)?: ");
    scanf("%s", response);
    
    if (strcmp(response, "Yes") == 0 || strcmp(response, "yes") == 0) {
        createContacts(fileName);
    }

    do {
        printf("Enter a choice:\n");
        printf("1 to print, 2 to search, 3 to create more, -1 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readContacts(fileName);
                break;
            case 2:
                printf("Search for Employee Id? ");
                int keyId;
                scanf("%d", &keyId);
                searchContacts(fileName, keyId);
                break;
            case 3:
                createContacts(fileName);
                break;
            case -1:
                break;
//            case 4:
//                clearContacts(fileName);
//                break;
            default:
                printf("Invalid choice\n");
                printf("\n");
        }
    } while (choice != -1);

    return 0;
}
