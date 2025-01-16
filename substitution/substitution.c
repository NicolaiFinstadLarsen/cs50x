#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*
TO-DO:

Run program by commandline arguments.
Error if 0 og 2+ commandline arguments are given.

KNOWN PROBLEMS:

*/


//Prototype
char* key_upper(string not_formated_key);
char* unique_key_check(string un_key);

const int XX = 26;

// Driver Code
int main(int argc, string argv[])
{

    // My string for comparison with key input
    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Calling iten 1 in array argv. Using main funtion for commandline argument.
    string key = argv[1];

    // Checking that argc is inside the number of args the program needs
    // if its not 2 we exit with two different printf statements.
    if(argc > 2)
    {
        printf("To many arguments\n");
        exit(1);
    }
    else if(argc <= 1)
    {
        printf("To few arguments\n");
        exit(1);
    }
    //string key = "nQxPoMaFtRhLzGeCyJiUwSkDvB";

    // Calling fuction for caseinsensitivity of user input for key
    string upper_key = key_upper(key);

    // Calling funtion for unique check of key(unique, is alpha, len == 26)
    string new_text = unique_key_check(upper_key);

    // Prompt user input for plaitext to be encrypted
    string text = get_string("Plaintext: ");

    // Vi printer "ciphertext her fordi den printer før vi printer
    // i ittereringen av plaintext
    printf("ciphertext: ");

    // Finner lengde av key for bruk i itterering av plaintext
    int length = strlen(upper_key);
    int text_length = strlen(text);

    // Ved å ittere gjennom hele alfabetet og key, så kan vi printe
    // ut key verdi hvis vi ser at text verdien tilsvarer alph verdien.
    // Tror dette er utrolig tregt, men det virker.
    // Itterere over text lengde fordi vi trenger ikke itterere over 26 runder
    for(int i = 0; i < text_length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if (alph[j] == text[i])
            {
                printf("%c", upper_key[j]);
                break;
            }
            // Sjekker om lowercase tilsvarer plaintext
            else if (tolower(alph[j]) == text[i])
            {
                printf("%c", tolower(upper_key[j]));
                break;
            }
            // Denne er for ikke alpha, som skal beholdes
            else if (isalpha(text[i])==0)
            {
                printf("%c", text[i]);
                break;
            }
        }
    }
    printf("\n");

   // Freeing up memory reserved.
   free(upper_key);
   // Return 0 from main if code runs ok.
   return(0);
}


// Function that returns key as uppercase for ASCII int comparison
char* key_upper(string not_formated_key)
{
    // Finding length and reserving memory for new_text
    // This is done to be able to return new_text from function
    int len = strlen(not_formated_key);
    char* new_text = malloc((strlen(not_formated_key) + 1) * sizeof(char));

    // Itteration over key and makeing it upper
    for(int i = 0; i<len; i++)
    {
        new_text[i] = toupper(not_formated_key[i]);

    }
    // Adding on char \0 so we know where string ends.
    new_text[len] = '\0';
    return new_text;
}

// Funksjon for check av kriterier for unikhet, lengde og alfabetisk.
char* unique_key_check(string un_key)
{
    int len = strlen(un_key);

    // Loop over hver index for å se at de er alpha.
    int k = 0;
    while(k < len)
    {
        if(!isalpha(un_key[k]))
        {
            printf("Errormessage: not alpha\n");
            k++;
            exit(1);
        }
        k++;
    }
    // Loop for å passe på at key er 26 tegn
    if(len != XX)
    {
        printf("Errormessage: not 26 digit\n");
        exit(1);
    }
    // Loop for å passe på at key er unik
    // Vi sjekker om i og j er like på samme string.
    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(un_key[j] == un_key[i])
            {
                printf("Errormessage: values not unique\n");
                //printf("%i\n", A[j]);
                //printf("%i\n", A[i]);
                exit(1);
            }
        }
    }
    //printf("Return A\n");
    return (un_key);
}
