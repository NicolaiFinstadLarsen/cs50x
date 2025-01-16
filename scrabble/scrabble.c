#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Fortsatt noe feil her.

//Prototyper
char* key_lower(string a);

// Lager en datastruct for å mappe bokstav og verdi sammen
typedef struct
{
    char letter;
    int value;
} value_dict;

// Legger en const max lengde for datastrucy array (så lenge ordene er under 26 så går dette fint?)
const int MAX = 26;
value_dict values[MAX];



int main(void)
{
    // Hardcoder bokstaver og verdier her
    char let[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int num[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for(int i = 0; i < MAX; i++)
    {
        values[i].letter = let[i];
        values[i].value = num[i];
    }

    // Får input og går den til lower gjennom funksjon key_lower
    string input_a = get_string("Input player a:");
    string player_a = key_lower(input_a);

    string input_b = get_string("Input player b: ");
    string player_b = key_lower(input_b);

    //printf("%i\n", values[25].value);
    //printf("%c\n", player_a[1]);

    // gjøre en nestet for loop for å itterere gjennom hele alfabetet for hver bokstav av inputstring
    // Finner så verdien av den boksaven og legger det inn i en score

    //Dette er delen som ikke virker. Vi får bare ut scoren etter ith posisjon oppover i values[].value
    // Jeg måtte bare bytte values[i].value til values[j].value i score beregningen
    // Det er jo ingen poeng å finne letter i j også bruke value i....
    int score_a = 0;
    int length_a = strlen(player_a);

    for (int i = 0; i < length_a; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(player_a[i] == values[j].letter)
            {
                score_a = score_a + values[j].value;
            }
        }

    }

    // gjøre en nestet for loop for å itterere gjennom hele alfabetet for hver bokstav av inputstring
    // Finner så verdien av den boksaven og legger det inn i en score

    //Dette er delen som ikke virker. Vi får bare ut scoren etter ith posisjon oppover i values[].value
    // Jeg måtte bare bytte values[i].value til values[j].value i score beregningen
    // Det er jo ingen poeng å finne letter i j også bruke value i....
    int score_b = 0;
    int length_b = strlen(player_b);

    for (int i = 0; i < length_b; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (player_b[i] == values[j].letter)
            {
                score_b = score_b + values[j].value;
            }
        }

    }

    // Printfunksjon for debug
    //printf("score a is: %i\n", score_a);
    //printf("score b is: %i\n", score_b);

    // If statements for winner output
    if (score_a > score_b)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_b > score_a)
    {
        printf("Player 2 wins!\n");
    }
    else if (score_a == score_b)
    {
        printf("Tie!\n");
    }
    // Free allocated memory from malloc for variables.
    free(player_a);
    free(player_b);
    return 0;
}


// tolower() funksjon
char* key_lower(string a)
{

    int len = strlen(a);
    char* new_text = malloc((strlen(a) + 1) * sizeof(char));

    for(int i = 0; i < len; i++)
    {
        new_text[i] = tolower(a[i]);

    }
    new_text[len] = '\0';
    return new_text;
}

