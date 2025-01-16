#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Denne fungerer for å finne antall ord i en setning.



int sort_by_space(text)

{

    int count = 0;

    // Variabel for lengden av string
    int length = strlen(text);

    // Itterere over lengden av string
    for(int i = 0; i < length; i++)
    {
        // Hvis char i ith plass i string == mellomrom count+=1
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // Printe ordcount men +1 fordi vi teller mellomrom ikke ord.
    return count+1;
    printf("%i\n", count+1);

}



