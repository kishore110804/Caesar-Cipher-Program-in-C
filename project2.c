#include <stdio.h>
#include <ctype.h>

// function for encryption 

void encryptMessage(char text[], int key) {
    
   
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        // isalnum = alpha numerical 
        if (isalnum(ch)) {
            
            if (islower(ch)) {
                // formulae for lower case 
                ch = (ch - 'a' + key) % 26 + 'a'; // a is the initial character of the series
            }
            if (isupper(ch)) {
                // Formulae for  upper case 
                ch = (ch - 'A' + key) % 26 + 'A'; // A is capatal letters 
            }
            if (isdigit(ch)) {
                // Formula for numbers 
                ch = (ch - '0' + key) % 10 + '0'; 
                // digits from 1 to 10 
            }
        }
        else {
            printf("Invalid Message"); // error message 
            return;
        }
        text[i] = ch;
    }
    printf("Encrypted message: %s\n", text);
}

// function for decryption 

void decryptMessage(char text[], int key) {
    
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' -key + 26) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' - key + 26)% 26 +'A';
            }
            if (isdigit(ch)) {
                ch = (ch -'0' - key + 10) % 10 +'0';
            }
        }
        else {
            printf("Invalid Message"); // error message 
            return;
        }
        text[i]= ch;
    }
    printf("Decrypted message: %s\n", text);
}

// main function 

int main() {

    char text[500];
    int key;
    int choice;
   
    
    // this executes first 
    
    printf("Enter 1 if you want to encrypt and 2 if you want to decrypt: ");
    scanf("%d", &choice); 
    
    if (choice == 1){
        // taking the inputs from the user
        printf("Enter a message to encrypt: ");
        scanf("%s", text);
    
        printf("Enter the key: ");
        scanf("%d", &key);
    
        encryptMessage(text, key); // calls the function for encryption 
    }
    else if (choice == 2) {
        // taking the inputs from the user 
        printf("Enter a message to decrypt: ");
        scanf("%s", text);
    
        printf("Enter the key: ");
        scanf("%d", &key);
    
        decryptMessage(text, key); // calls the function for decryption 
    }
    
    else {
        printf("Enter a valid value, please!\n"); // error message 
    }
    
    return 0;
}